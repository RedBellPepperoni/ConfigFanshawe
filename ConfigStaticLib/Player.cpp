#include "Player.h"

namespace StaticLib
{
	// Default Constructor
	Player::Player() 
		    : m_health(100)
			, m_maxHealth(100)
			, m_name("PlayerOne")
			, m_attackDamage(10)
	{
	}

	// Constructor with parameter initializaton
	Player::Player(const std::string playerName,const int startingHealth,const int attackDamage)
			: m_health(startingHealth)
			, m_maxHealth(startingHealth)
			, m_name(playerName)
			, m_attackDamage(attackDamage)
	{
	}

	// Destructor
	Player::~Player()
	{
	}

	// Function to take damage from sources
	void Player::TakeDamage(const int incomingDamage)
	{
		// If the damage received is greater than current health we kill the player
		if (incomingDamage >= m_health)
		{
			m_health = 0;

			// Player Died
			return;
		}

		// Otherwise we lower the health according to the incoming damage
		m_health -= incomingDamage;
		
	}
	void Player::Heal(const int healValue)
	{
		// Temporary variable storing the amount of health after healing
		const int totalHealed = healValue + m_health;

		// If we overheal the player , set player to maximun health
		if (totalHealed >= m_maxHealth)
		{
			m_health = m_maxHealth;
			return;
		}

		// Otherwise heal the player for the given amount
		m_health = totalHealed;

	}

	const int Player::GetHealth() const
	{
		return m_health;
	}
	const int Player::GetMaxHealth() const
	{
		return m_maxHealth;
	}
	const int Player::GetAttack() const
	{
		return m_attackDamage;
	}
	const std::string Player::GetName() const
	{
		return m_name;
	}
	const bool Player::IsDead() const
	{
		return !(m_health > 0);
	}
}