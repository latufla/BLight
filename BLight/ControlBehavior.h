#pragma once
#include "CustomPoint.h"
#include "BehaviorBase.h"
#include "Command.h"

class ControlBehavior : public BehaviorBase
{
public:
	ControlBehavior(void) : BehaviorBase(){};
	ControlBehavior(Info* info) : BehaviorBase(info){};
	
	virtual CustomPoint* getMoveTo() = 0;
	virtual float getMoveForce() = 0;

	virtual ControllerBase* getTarget() = 0;
	virtual CommandType getCommand() = 0;
};

