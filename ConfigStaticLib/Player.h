#pragma once
#include <string>
namespace StaticLib 
{
	class Player
	{
	public:

		// Default Constructor
		Player();

		// Custom Constructor with parameters
		Player(const std::string playerName,const int startingHealth,const int attackDamage);
		~Player();

		// =================== FUNCTIONAL STUFF ==============
	
		// Function to give damage to teh player from a damage source
		void TakeDamage(const int incomingDamage);

		// Fucntion to heal up teh player by the provided value
		void Heal(const int healValue);

		// ==================== GETTERS ================

		// Getter for fetching the current Health
		const int GetHealth() const;

		const int GetMaxHealth() const;

		// Getter for fetching the current attack damage
		const int GetAttack() const;

		// Getter for fetching the name of the Player
		const std::string GetName() const;

		// Getter for cheking if the player is Dead
		const bool IsDead() const;

	private:


		// Name of the player
		std::string m_name;

		// CurrentHealth of the player
		int m_health;
		
		// Maximum health of the player (Should always be 100)
		int m_maxHealth;

		// Attack damage of the Player
		int m_attackDamage;

		

	};
}

