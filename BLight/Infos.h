#pragma once
#include "stdafx.h"
#include "ObjectInfo.h"

class Infos
{
public:
	static void init();

	static ObjectInfo* getInfoBy(int);
	static ObjectInfo* getInfoBy(string);

	// pretend to be external
	static const int HERO = 0;
	static const int ENEMY = 1;
	static const int SMALL_ENERGY_PACK = 2;
	static const int MEDIUM_ENERGY_PACK = 3;
	static const int CHARGER = 4;
	static const int ENEMY_SPAWNER = 5;

	static const string HERO_NAME;
	static const string ENEMY_NAME;
	static const string SMALL_ENERGY_PACK_NAME;
	static const string MEDIUM_ENERGY_PACK_NAME;
	static const string CHARGER_NAME;
	static const string ENEMY_SPAWNER_NAME;

private:
	static map<int, ObjectInfo*> idToInfo;
	static map<string, ObjectInfo*> nameToInfo;

	// drop when implement external infos
	static ObjectInfo* getHeroInfo();
	static ObjectInfo* getEnemyInfo();
	static ObjectInfo* getSmallEnergyPackInfo();
	static ObjectInfo* getMediumEnergyPackInfo();
	static ObjectInfo* getChargerInfo();
	static ObjectInfo* getEnemySpawnerInfo();
};

