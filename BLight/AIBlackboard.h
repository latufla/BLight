#pragma once
#include "CustomPoint.h"
#include "ControllerBase.h"
#include "ControlBehavior.h"

class AIBlackboard
{
public:
	AIBlackboard(void);
	~AIBlackboard(void);

	CustomPoint* getMoveTo() {return moveTo;}
	void setMoveTo(CustomPoint* val){moveTo = val;}
	
	float getMoveForce() const { return moveForce; }
	void setMoveForce(float val) { moveForce = val; }
	
	ControllerBase* getTarget() const { return target; }
	void setTarget(ControllerBase* val) { target = val; }

	ControlAction getAction() const { return action; }
	void setAction(ControlAction val) { action = val; }

protected:
	CustomPoint* moveTo;
	float moveForce;
	
	ControllerBase* target;
	ControlAction action;	
};

