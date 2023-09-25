#include "Dungeon.h"



namespace DynamicLib
{
	//Default Dungeon with 10 enemies each having 10 atatck and 10 health
	Dungeon::Dungeon() 
		: m_name("ScaryDungeon")
		, m_totalEnemies(10)
		, m_remainingEnemies(10)
		, m_enemyMaxHealth(10)
		, m_currentSelectedEnemyHealth(10)
		, m_enemyAttack(10)
		
	{

	}

	//Custom Dungeon according to data from parameters
	Dungeon::Dungeon(const std::string dungeonName, const int enemiesToSpawn, const int enemyHealth, const int enemyDamage)
		: m_name(dungeonName)
		, m_totalEnemies(enemiesToSpawn)
		, m_remainingEnemies(enemiesToSpawn)
		, m_enemyMaxHealth(enemyHealth)
		, m_currentSelectedEnemyHealth(enemyHealth)
		, m_enemyAttack(enemyDamage)
		
	{
		
	}
	Dungeon::~Dungeon()
	{
	}

	// Process events in one turn
	//One turn ends when player attacks one enemy and one of the enemies attacks the player
	void Dungeon::ProcessTurn(const int& damagefromPlayer)
	{
		// Atleast one Enemy is alive
		if (!AllEnemiesKilled())
		{
			// The last enemy in the dynamic array gets damaged from teh Player
			TakeDamage(damagefromPlayer);

			return;
		}



	}
	void Dungeon::TakeDamage(const int incomingDamage)
	{
		// if the damage is enough to kill the enemy we set the current Selected health of new enemy and decrement the enemy counter
		if (incomingDamage >= m_currentSelectedEnemyHealth)
		{
			m_currentSelectedEnemyHealth = m_enemyMaxHealth;
			m_remainingEnemies -= 1;
			return;
		}

		m_currentSelectedEnemyHealth -= incomingDamage;

	}
	const bool Dungeon::AllEnemiesKilled() const
	{
		return m_remainingEnemies <= 0 ;
	}

	const int Dungeon::GetRemainingEnemies() const
	{
		return m_remainingEnemies;
	}

	const int Dungeon::GetEnemyMaxHealth() const
	{
		return m_enemyMaxHealth;
	}

	const int Dungeon::GetEnemyCurrentHealth() const
	{
		return m_currentSelectedEnemyHealth;
	}

	const int Dungeon::GetEnemyAttack() const
	{
		return m_enemyAttack;
	}

	const std::string Dungeon::GetName() const
	{
		return m_name;
	}
	
	
}
