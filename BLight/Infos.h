#pragma once
#include "ObjectInfo.h"
class Infos
{
public:
	static ObjectInfo* getHeroInfo();
	static ObjectInfo* getEnemyInfo();
	static ObjectInfo* getSmallEnergyPackInfo();
	static ObjectInfo* getMediumEnergyPackInfo();
	static ObjectInfo* getChargerInfo();
	static ObjectInfo* getEnemySpawnerInfo();
};

