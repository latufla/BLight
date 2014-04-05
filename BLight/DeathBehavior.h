#pragma once
#include "BehaviorBase.h"

class DeathBehavior : public BehaviorBase
{
public:
	DeathBehavior(void);
	DeathBehavior(Info* info);
	~DeathBehavior(void);

	BehaviorType getType(){return DEATH_BEHAVIOR;}

protected:
	bool doStep(int);
};

