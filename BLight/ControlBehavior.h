#pragma once
#include "CustomPoint.h"
#include "BehaviorBase.h"

enum ControlAction{NONE_ACTION, ATTACK_ACTION, COLLECT_ACTION}; //, APPLY_ACTION};

class ControlBehavior : public BehaviorBase
{
public:
	virtual CustomPoint* getMoveTo() = 0;
	virtual float getMoveForce() = 0;

	virtual ControllerBase* getTarget() = 0;
	virtual ControlAction getAction() = 0;
};

