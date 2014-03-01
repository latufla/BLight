#pragma once
#include "BehaviorBase.h"
#include "ControlBehavior.h"

class MoveBehavior : public BehaviorBase
{
public:
	MoveBehavior(void);
	~MoveBehavior(void);

	BehaviorType getType(){return MOVE;};

protected:
	bool doStep(int);
	
	bool shouldStop(CustomPoint*);
	void applyStoppage();
};

