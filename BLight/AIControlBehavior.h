#pragma once
#include "AIBlackboard.h"
#include "ControlBehavior.h"

class AIControlBehavior : public ControlBehavior
{
public:
	AIControlBehavior(void);
	~AIControlBehavior(void);

	CustomPoint* getMoveTo(){return blackboard.getMoveTo();}
	float getMoveForce(){return blackboard.getMoveForce();}

	ControllerBase* getTarget(){return blackboard.getTarget();}
	ControlAction getAction(){return blackboard.getAction();}

protected:
	AIBlackboard blackboard;
};

