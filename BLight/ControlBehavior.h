#pragma once
#include "CustomPoint.h"
#include "BehaviorBase.h"

class ControlBehavior : public BehaviorBase
{
public:
	virtual CustomPoint* getMoveTo() = 0;
	virtual float getForce() = 0;
};

