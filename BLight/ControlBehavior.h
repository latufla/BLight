#pragma once
#include "CustomPoint.h"
#include "BehaviorBase.h"
class ControlBehavior : public BehaviorBase
{
public:
	virtual CustomPoint* getDestination() = 0;
	virtual int getForce() = 0;
};

