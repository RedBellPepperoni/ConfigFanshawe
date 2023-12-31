#pragma once
#include <string>
#include <vector>

namespace DynamicLib
{




	// A simple Turnbased Dungeon sim
	class Dungeon
	{
		

	public:
		// Default Constructor
		Dungeon();

		//Constructor with custom Parameters
		Dungeon(const std::string dungeonName,const int enemiesToSpawn,const int enemyHealth,const int enemyDamage);

		// Destructor
		virtual ~Dungeon();


		// =================== FUNCTIONAL STUFF ==================

		// Process all the happening during one turn : one turn at a time 
		// process all the turn either till player dies or player completes the dungeon
		virtual void ProcessTurn(const int& damagefromPlayer);

		

		// Getter to check if the dungeon is complete
		virtual const bool AllEnemiesKilled() const;
		virtual const int GetRemainingEnemies() const;
		virtual const int GetEnemyMaxHealth() const;
		virtual const int GetEnemyCurrentHealth() const;
		virtual const int GetEnemyAttack() const;
		virtual const std::string GetName() const;
		
		

	protected:
		void TakeDamage(const int incomingDamage);


	protected:

		// Name of the Dungeon
		std::string m_name;

		// The total number of enemies in this dungeon
		int m_totalEnemies;

		// Counter to see how many eneies are left
		int m_remainingEnemies;

		// NOTE :: For simplicity sake, all the enemies have same attack and health
		// The attack damage of each enemies
		int m_enemyAttack;

		int m_currentSelectedEnemyHealth;

		// The health of each enemy
		int m_enemyMaxHealth;



	};

}

