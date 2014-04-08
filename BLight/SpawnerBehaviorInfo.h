#pragma once
#include "Info.h"
#include "CustomPoint.h"

class SpawnerBehaviorInfo : public Info
{
public:
	SpawnerBehaviorInfo(void);
	~SpawnerBehaviorInfo(void);

	int intervalMSec;
	int chance;
	string creature;
	float spawnX;
	float spawnY;
};

