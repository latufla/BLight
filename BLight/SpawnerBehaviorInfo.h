#pragma once
#include "Info.h"

class SpawnerBehaviorInfo : public Info
{
public:
	SpawnerBehaviorInfo(void);
	~SpawnerBehaviorInfo(void);

	int intervalMSec;
	int chance;
	string creature;
};

