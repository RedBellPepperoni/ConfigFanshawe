#include <iostream>
#include "gtest/gtest.h"
#include "ConfigStaticLib/Player.h"
#include "ConfigDynamicLib/Dungeon.h"

namespace TestSuiteOne
{
	// =================== TEST FIXTURES =========================

	struct DungeonData 
	{
		// Easier  and Cleaner Dat formatting
		 std::string newName ;
		 int enemyCount;
		 int enemyHealth;
		 int enemyAttack;
	};


	struct PlayerData
	{
		std::string newName;
		int newHealth;
		int newAttack;
	};


	// Test Fixture to test Player Data from the linked static library
	struct IntegrationFixture : testing::Test
	{
		// initializing an empty Dungeon pointer
		DynamicLib::Dungeon* dungeonHandle = nullptr;

		// initializing an empty player pointer
		StaticLib::Player* playerHandle = nullptr;

		// Constructor
		IntegrationFixture()
		{

		}

		//Destructor (adding to the V-table)
		virtual ~IntegrationFixture()
		{

		}

		//  Dungeon and Player Setup with Default values
		void SetUp()
		{
			// Setting up a new dungeon with default data
			dungeonHandle = new DynamicLib::Dungeon();

			// Setting up a new player with default health and attack damage
			playerHandle = new StaticLib::Player();

		}

		// Dungeon and Player Setup with custom parameters
		void SetUp(const DungeonData& dungeonData, const PlayerData& playerData)
		{
			// Custom data
			dungeonHandle = new DynamicLib::Dungeon(dungeonData.newName, dungeonData.enemyCount, dungeonData.enemyHealth, dungeonData.enemyAttack);

			playerHandle = new StaticLib::Player(playerData.newName, playerData.newHealth, playerData.newAttack);
		}


		// called at the end : clear everything here
		virtual void TearDown()
		{
			delete dungeonHandle;
			delete playerHandle;
		}




	};

	// ========================== TESTS ==============================
	// testOne, testTwo and testThree  should test the Default Initialization and Value Changes
	// testFour, testFive and testSix deal with the Custom Data.

	// ------------ Tests for the Default Data ----------------------

	// testOne: Testing correct default values
	TEST_F(IntegrationFixture, correctDefaults)
	{
		SetUp();

		// Checking if The default Dungeon values are correct
		EXPECT_EQ(dungeonHandle->GetRemainingEnemies(), 10);

		EXPECT_EQ(dungeonHandle->GetName(), "ScaryDungeon");

		EXPECT_EQ(dungeonHandle->AllEnemiesKilled(), false);


		// The health should never be above 100 for the default player
		EXPECT_FALSE(playerHandle->GetHealth() > 100);

		// Checking if the Name of the player is differnt from default
		EXPECT_FALSE(playerHandle->GetName() == "SomeOtherName");

		// Seeing if the player is Dead from the get do, this shouldn't be possible
		EXPECT_FALSE(playerHandle->IsDead() == true);


	}

	// testTwo: Tesing a Turn Based dungeon gameplay with default Value
	TEST_F(IntegrationFixture, dungeonGameFair)
	{
		SetUp();

		// Attacking the first enemy 
		dungeonHandle->ProcessTurn(playerHandle->GetAttack());

		// Enemy Attacking the Player
		playerHandle->TakeDamage(dungeonHandle->GetEnemyAttack());

		// Default dungeon should have 10 enemies so killing one wont really end the Run
		EXPECT_FALSE(dungeonHandle->AllEnemiesKilled());

		//since the player should have taken some damage , the health shouldn't be full
		EXPECT_FALSE(playerHandle->GetHealth() ==  playerHandle->GetMaxHealth());

	}

	// testThree: Testing case where player is attacked, healed and killed
	TEST_F(IntegrationFixture, dungeonGameOPPlayer)
	{
		SetUp();

		// Player does a combo and hit multiple Enemies
		 
		// testing by killing one Enemy
		dungeonHandle->ProcessTurn(playerHandle->GetAttack());
		// testing by killing another enemy
		dungeonHandle->ProcessTurn(playerHandle->GetAttack());
		// testing by killing another enemy
		dungeonHandle->ProcessTurn(playerHandle->GetAttack());
		// testing by killing another enemy
		dungeonHandle->ProcessTurn(playerHandle->GetAttack());
		// testing by killing another enemy
		dungeonHandle->ProcessTurn(playerHandle->GetAttack());


		// We only Kiled 5 enemies, so there shold be more than 2 left
		EXPECT_TRUE(dungeonHandle->GetRemainingEnemies() > 2);


		// The player is really skilled and attacks 5 more times
		// testing by killing one Enemy
		dungeonHandle->ProcessTurn(playerHandle->GetAttack());
		// testing by killing another enemy
		dungeonHandle->ProcessTurn(playerHandle->GetAttack());
		// testing by killing another enemy
		dungeonHandle->ProcessTurn(playerHandle->GetAttack());
		// testing by killing another enemy
		dungeonHandle->ProcessTurn(playerHandle->GetAttack());
		// testing by killing another enemy
		dungeonHandle->ProcessTurn(playerHandle->GetAttack());



		// Player should have cleared the dungeon
		EXPECT_TRUE(dungeonHandle->AllEnemiesKilled());


	}


	// ------------ Tests for the Custom Data ----------------------

	// testFour: Custom Player and Dungeon : Defaults
	TEST_F(IntegrationFixture, correctCustom)
	{
		DungeonData dData;
		// Setting up custom DUngeon data
		dData.newName = "PunishingDungeon";
		dData.enemyCount = 10;
		dData.enemyHealth = 1000;
		dData.enemyAttack = 200;

		PlayerData pData;

		pData.newName = "Newbie";
		pData.newHealth = 50;
		pData.newAttack = 5;

		// Setting up with custom Data
		SetUp(dData, pData);

		// Checking if The default values are correct
		EXPECT_EQ(dungeonHandle->GetName(), dData.newName);

		EXPECT_EQ(playerHandle->GetName(), pData.newName);

		// The Newbie player should be one hit by the enemies
		EXPECT_TRUE(dungeonHandle->GetEnemyAttack() > playerHandle->GetMaxHealth());

		// Dungeon is just created, so the test shouldn't fail 
		EXPECT_EQ(dungeonHandle->AllEnemiesKilled(), false);

	}

	// testFive: Putting a new player in a darksouls environment
	TEST_F(IntegrationFixture, dungeonGameUnfair)
	{
		DungeonData dData;
		// Setting up custom DUngeon data
		dData.newName = "PunishingDungeon";
		dData.enemyCount = 10;
		dData.enemyHealth = 1000;
		dData.enemyAttack = 200;

		PlayerData pData;

		pData.newName = "Newbie";
		pData.newHealth = 50;
		pData.newAttack = 5;

		// Setting up with custom Data
		SetUp(dData, pData);

		// Newbie tries to do what ever damage possible
		dungeonHandle->ProcessTurn(playerHandle->GetAttack());

		// Dungeon Enemy absolutly Decimates Newbie
		playerHandle->TakeDamage(dungeonHandle->GetEnemyAttack());


		// RIP newbie
		EXPECT_TRUE(playerHandle->IsDead());


	}

	// testSiz: Testing case where player is attacked, healed and killed
	TEST_F(IntegrationFixture, dungeonGameHealer)
	{
		DungeonData dData;
		// Setting up custom DUngeon data
		dData.newName = "GlassCannonDungeon";
		dData.enemyCount = 3;
		dData.enemyHealth = 5;
		dData.enemyAttack = 80;

		PlayerData pData;

		pData.newName = "Healer";
		pData.newHealth = 100;
		pData.newAttack = 20;

		// Setting up custom Data
		SetUp(dData, pData);

		// Our Healer gets the first HIT
		dungeonHandle->ProcessTurn(playerHandle->GetAttack());
		
		// One enemy shoyld Die
		EXPECT_EQ(dungeonHandle->GetRemainingEnemies(), dData.enemyCount - 1);

		// High damage from the enemy Hit
		playerHandle->TakeDamage(dungeonHandle->GetEnemyAttack());

		// Our healer should have some healthleft
		EXPECT_FALSE(playerHandle->IsDead());

		// Healer has an extremely powerful heal spell
		playerHandle->Heal(120);

		// healer should be fully healed
		EXPECT_TRUE(playerHandle->GetHealth() == playerHandle->GetMaxHealth());


		
	}

}




int main(int argc, char* argv)
{
	::testing::InitGoogleTest();

	RUN_ALL_TESTS();

	std::cout << "Press any key to exit" << std::endl;

	std::cin.get();

}