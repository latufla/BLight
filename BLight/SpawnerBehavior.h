#pragma once
#include "BehaviorBase.h"
#include "ObjectInfo.h"
#include "CreateCommand.h"

class SpawnerBehavior : public BehaviorBase
{
public:
	SpawnerBehavior(void);
	~SpawnerBehavior(void);
	
	BehaviorType getType(){return SPAWNER_BEHAVIOR;}

protected:
	bool doStep(int);

	ObjectInfo* creature;
	int intervalMSec;
	int chance;

	int time;
};

