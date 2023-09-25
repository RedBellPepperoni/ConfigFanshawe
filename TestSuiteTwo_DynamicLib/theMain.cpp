#include <iostream>
#include "gtest/gtest.h"
#include "ConfigDynamicLib/Dungeon.h"

namespace TestSuiteOne
{
	// =================== TEST FIXTURES =========================

	// Test Fixture to test dungeon Data from the linked static library
	struct DungeonFixtureDynamic : testing::Test
	{
		// initializing an empty dungeon pointer
		DynamicLib::Dungeon* dungeonHandle = nullptr;

		// Constructor
		DungeonFixtureDynamic()
		{

		}

		//Destructor (adding to the V-table)
		virtual ~DungeonFixtureDynamic()
		{

		}

		//  Dungeon Setup with Default values
		void SetUp()
		{
			// Setting up a new dungeon with default data
			dungeonHandle = new DynamicLib::Dungeon();

		}

		// Dungeon Setup with custom parameters
		void SetUp(const std::string dungeonName, const int enemiesToSpawn, const int enemyHealth, const int enemyAttack)
		{
			// Custom data
			dungeonHandle = new DynamicLib::Dungeon(dungeonName, enemiesToSpawn, enemyHealth, enemyAttack);
		}


		// called at the end : clear everything here
		virtual void TearDown()
		{
			delete dungeonHandle;
		}




	};

	// ========================== TESTS ==============================
	// testOne, testTwo and testThree  should test the Default Dungeon Initialization and Value Changes
	// testFour, testFive and testSix deal with the Custom Dungeon Data.

	// ------------ Tests for the Default Dungeon ----------------------

	// testOne: Testing if Dungeon has correct default values
	TEST_F(DungeonFixtureDynamic, correctDungeonDefaults)
	{
		SetUp();
		// Checking if The default values are correct
		EXPECT_EQ(dungeonHandle->GetRemainingEnemies(), 10);

		EXPECT_EQ(dungeonHandle->GetName(), "ScaryDungeon");


		EXPECT_EQ(dungeonHandle->AllEnemiesKilled(), false);

	}

	// testTwo: Testing with incorrect Defaults 
	TEST_F(DungeonFixtureDynamic, incorrectDungeonDefault)
	{
		SetUp();

		// The health should never be above 100 for the default dungeon
		EXPECT_FALSE(dungeonHandle->GetRemainingEnemies() == 5);

		// Checking if the Name of the dungeon is differnt from default
		EXPECT_FALSE(dungeonHandle->GetName() == "SomeOtherName");

		// Seeing if all the enemies are already killed when the dungeon spawns, this shouldn't be possible
		EXPECT_FALSE(dungeonHandle->AllEnemiesKilled());


	}

	// testThree: Testing case where dungeon is attacked, healed and killed
	TEST_F(DungeonFixtureDynamic, updateDefaultDungeon)
	{
		SetUp();

		const int dungeonDamage = 50;
		
		// testing by killing one Enemy
		dungeonHandle->ProcessTurn(dungeonDamage);

		// Checking if all enemies are dead, shouldnt happen
		EXPECT_FALSE(dungeonHandle->AllEnemiesKilled());

	
		// testing by killing another enemy
		dungeonHandle->ProcessTurn(dungeonDamage);

		// since some enmies are killed, the value should be less than the default 10
		EXPECT_FALSE(dungeonHandle->GetRemainingEnemies() > 10);
	}


	// ------------ Tests for the Custom dungeon ----------------------

	// testFour: Testing if dungeon has correct default values
	TEST_F(DungeonFixtureDynamic, correctDungeonCustom)
	{
		// Setting up custom data with  double the default health and triple the attack damage
		const std::string newName = "TreachrousDungeon";
		const int enemyCount = 1;
		const int enemyHealth = 10;
		const int enemyAttack = 80;


		// Setting up a new Dungeon with custom Data
		SetUp(newName, enemyCount, enemyHealth, enemyAttack);

		// Checking if The default values are correct
		EXPECT_EQ(dungeonHandle->GetName(), newName);

		EXPECT_EQ(dungeonHandle->GetRemainingEnemies(), enemyCount);

		// Utilizing a differnt test 
		EXPECT_TRUE(dungeonHandle->GetEnemyAttack() == enemyAttack);

		// Dungeon is just created, so the test shouldn't fail 
		EXPECT_EQ(dungeonHandle->AllEnemiesKilled(), false);

	}

	// testFive: Testing with incorrect Defaults 
	TEST_F(DungeonFixtureDynamic, incorrectDungeonCustom)
	{
		// Setting up custom data with  one enemy having 10 health and 80 attack
		const std::string newName = "CrowdedDungeon";
		const int enemyCount = 1337;
		const int enemyHealth = 80;
		const int enemyAttack = 200;


		// Setting up a new Dungeon with custom Data
		SetUp(newName, enemyCount, enemyHealth, enemyAttack);

		
		// Checking if The default values are correct
		EXPECT_FALSE(dungeonHandle->GetName() ==  "IncorrectName");

		// The Remaining Enemies should be a lot
		EXPECT_FALSE(dungeonHandle->GetRemainingEnemies() < 20);

		// Utilizing a differnt test 
		EXPECT_FALSE(dungeonHandle->GetEnemyAttack() < enemyAttack);

		// Dungeon is just created, so the test shouldn't fail 
		EXPECT_FALSE(dungeonHandle->AllEnemiesKilled());


	}

	// testSiz: Testing case where dungeon is attacked, healed and killed
	TEST_F(DungeonFixtureDynamic, updatedDungeonCustom)
	{
		// Setting up custom data with  one enemy having 10 health and 80 attack
		const std::string newName = "WeakDungeon";
		const int enemyCount = 4;
		const int enemyHealth = 5;
		const int enemyAttack = 1;


		// Setting up a new Dungeon with custom Data
		SetUp(newName, enemyCount, enemyHealth, enemyAttack);

		// Checking if The default values are correct
		EXPECT_EQ(dungeonHandle->GetName(), newName);


		EXPECT_EQ(dungeonHandle->GetRemainingEnemies(), enemyCount);

		// Killing 3 enemies
		dungeonHandle->ProcessTurn(10);
		dungeonHandle->ProcessTurn(10);
		dungeonHandle->ProcessTurn(10);

		EXPECT_EQ(dungeonHandle->GetRemainingEnemies(), enemyCount - 3);

		// killing the last enemy
		dungeonHandle->ProcessTurn(10);

		// One extra to test edge case
		dungeonHandle->ProcessTurn(10);

		// Dungeon is just created, so the test shouldn't fail 
		EXPECT_EQ(dungeonHandle->AllEnemiesKilled(), true);
	}

}




int main(int argc, char* argv)
{
	::testing::InitGoogleTest();

	RUN_ALL_TESTS();

}