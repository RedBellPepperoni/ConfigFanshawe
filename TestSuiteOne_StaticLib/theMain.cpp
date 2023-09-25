#include <iostream>
#include "gtest/gtest.h"
#include "ConfigStaticLib/Player.h"

namespace TestSuiteOne
{
	// =================== TEST FIXTURES =========================

	// Test Fixture to test Player Data from the linked static library
	struct PlayerFixtureStatic : testing::Test
	{
		// initializing an empty Player pointer
		StaticLib::Player* playerHandle = nullptr;

		// Constructor
		PlayerFixtureStatic()
		{

		}

		//Destructor (adding to the V-table)
		virtual ~PlayerFixtureStatic()
		{

		}

		//  Player Setup with Default values
		void SetUp()
		{
			// Setting up a new player with default health and attack damage
			playerHandle = new StaticLib::Player();

		}

		// Player Setup with custom parameters
		void SetUp(std::string name, int startingHealth, int startingDamage)
		{
			// Custom data
			playerHandle = new StaticLib::Player(name, startingHealth, startingDamage);
		}


		// called at the end : clear everything here
		virtual void TearDown()
		{
			delete playerHandle;
		}




	};

	// ========================== TESTS ==============================
	// testOne, testTwo and testThree  should test the Deafult Player Initialization and Value Changes
	// testFour, testFive and testSix deal with the Custom Player Data.

	// ------------ Tests for the Default player ----------------------

	// testOne: Testing if Player has correct default values
	TEST_F(PlayerFixtureStatic, correctPlayerDefaults)
	{
		SetUp();
		// Checking if The default values are correct
		EXPECT_EQ(playerHandle->GetHealth(), 100);

		EXPECT_EQ(playerHandle->GetName(), "PlayerOne");

		// Utilizing a differnt test 
		EXPECT_TRUE(playerHandle->GetAttack() == 10);

		// player is just created, so the test shouldn't fail 
		EXPECT_EQ(playerHandle->IsDead(), false);

	}

	// testTwo: Testing with incorrect Defaults 
	TEST_F(PlayerFixtureStatic, incorrectPlayerDefault)
	{
		SetUp();

		// The health should never be above 100 for the default player
		EXPECT_FALSE(playerHandle->GetHealth() > 100);

		// Checking if the Name of the player is differnt from default
		EXPECT_FALSE(playerHandle->GetName() == "SomeOtherName");

		// Seeing if the player is Dead from the get do, this shouldn't be possible
		EXPECT_FALSE(playerHandle->IsDead() == true);


	}

	// testThree: Testing case where player is attacked, healed and killed
	TEST_F(PlayerFixtureStatic, updatedPlayerDefault)
	{
		SetUp();

		// Hitting player with 40 Damage
		playerHandle->TakeDamage(40);

		// Checking if the health is correctly reflected after taking damage
		EXPECT_EQ(playerHandle->GetHealth(), 60);

		//overhealing healing the Player
		playerHandle->Heal(50);

		// player health shouln't go above the max health 
		EXPECT_FALSE(playerHandle->GetHealth() > 100);

		// Hitting the player with enough damage to kil the player
		playerHandle->TakeDamage(120);

		// Checking if the player is truly dead, othwerwise something is seriously wrong
		EXPECT_TRUE(playerHandle->IsDead());
	}


	// ------------ Tests for the Custom player ----------------------

	// testFour: Testing if Player has correct default values
	TEST_F(PlayerFixtureStatic, correctPlayerCustom)
	{
		// Setting up custom data with  double the default health and triple the attack damage
		const std::string newName = "RedBellPepper";
		const int newHealth = 200;
		const int newAttack = 30;


		// Setting up a new player with custom Data
		SetUp(newName, newHealth, newAttack);

		// Checking if The default values are correct
		EXPECT_EQ(playerHandle->GetHealth(), newHealth);

		EXPECT_EQ(playerHandle->GetName(), newName);

		// Utilizing a differnt test 
		EXPECT_TRUE(playerHandle->GetAttack() == newAttack);

		// player is just created, so the test shouldn't fail 
		EXPECT_EQ(playerHandle->IsDead(), false);

	}

	// testFive: Testing with incorrect Defaults 
	TEST_F(PlayerFixtureStatic, incorrectPlayerCustom)
	{
		// Setting up custom data with  double the default health and triple the attack damage
		const std::string newName = "RedBellPepper";
		const int newHealth = 200;
		const int newAttack = 30;


		// Setting up a new player with custom Data
		SetUp(newName, newHealth, newAttack);

		// The health should never be above 100 for the default player
		EXPECT_FALSE(playerHandle->GetHealth() > newHealth);

		// Checking if the Custom Name is not the DefaultName
		EXPECT_FALSE(playerHandle->GetName() == "PlayerOne");

		// Seeing if the player is Dead from the get go, this shouldn't be possible
		EXPECT_FALSE(playerHandle->IsDead() == true);


	}

	// testSiz: Testing case where player is attacked, healed and killed
	TEST_F(PlayerFixtureStatic, updatedPlayerCustom)
	{
		// Setting up custom data with  double the default health and triple the attack damage
		const std::string newName = "RedBellPepper";
		const int newHealth = 200;
		const int newAttack = 30;


		// Setting up a new player with custom Data
		SetUp(newName, newHealth, newAttack);

		// Hitting player so that the player remains with 1 hp
		playerHandle->TakeDamage(playerHandle->GetHealth() - 1);

		// Checking if the health is correctly reflected after taking damage
		EXPECT_EQ(playerHandle->GetHealth(), 1);

		//healing the Player so that the player health is equal to attack damage
		playerHandle->Heal(playerHandle->GetAttack() - playerHandle->GetHealth());

		// player health shouln't go above the attack damage
		EXPECT_FALSE(playerHandle->GetHealth() > playerHandle->GetAttack());

		// Hitting the player with its own attack so that the damage is just enough to kill the player
		playerHandle->TakeDamage(playerHandle->GetAttack());

		// Checking if the player is truly dead, othwerwise something is seriously wrong
		EXPECT_TRUE(playerHandle->IsDead());
	}

}




int main(int argc, char* argv)
{
	::testing::InitGoogleTest();

	RUN_ALL_TESTS();

	std::cout << "Press any key to exit" << std::endl;

	std::cin.get();

}