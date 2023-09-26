#include "Dungeon.h"


#define DLLEXPORT __declspec ( dllexport )

#define DLLIMPORT __declspec ( dllimport )



namespace DynamicLib
{
	extern "C" DLLEXPORT Dungeon* CreateDungeonDefault()
	{
		return new Dungeon();
	}

	extern "C" DLLEXPORT Dungeon* CreateDungeonCuston(const std::string dungeonName, const int enemiesToSpawn, const int enemyHealth, const int enemyDamage)
	{
		return new Dungeon(dungeonName,enemiesToSpawn,enemyHealth,enemyDamage);
	}
	
}
