#pragma once
#include "BehaviorBase.h"
#include "ControlBehavior.h"

class MoveBehavior : public BehaviorBase
{
public:
	MoveBehavior(void);
	~MoveBehavior(void);
	
	BehaviorBase* clone();

	BehaviorType getType(){return MOVE_BEHAVIOR;}

protected:
	bool doStep(int);
	
	bool shouldStop(CustomPoint&);
	void applyStoppage();
};

