#pragma once
#include "BehaviorBase.h"

class DeathBehavior : public BehaviorBase
{
public:
	DeathBehavior(void);
	~DeathBehavior(void);

	BehaviorBase* clone();

	BehaviorType getType(){return DEATH_BEHAVIOR;}

protected:
	bool doStep(int);
};

