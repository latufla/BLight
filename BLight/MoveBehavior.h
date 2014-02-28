#pragma once
#include "BehaviorBase.h"
#include "ControlBehavior.h"

class MoveBehavior : public BehaviorBase
{
public:
	MoveBehavior(void);
	~MoveBehavior(void);

	bool doStep(int);

	BehaviorType getType(){return MOVE;};
};

