#pragma once
#include "ObjectInfo.h"
class Infos
{
public:
	static ObjectInfo* createHero();
	static ObjectInfo* createEnemy();
	static ObjectInfo* createSmallEnergyPack();
	static ObjectInfo* createMediumEnergyPack();
	static ObjectInfo* createCharger();
};

