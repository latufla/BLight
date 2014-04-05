#pragma once
#include "AIBlackboard.h"
#include "ControlBehavior.h"
#include "AINode.h"
#include "Command.h"

class AIControlBehavior : public ControlBehavior
{
public:
	AIControlBehavior(void);
	AIControlBehavior(Info*);
	~AIControlBehavior(void);
	
	bool start(ControllerBase*);

	CustomPoint* getMoveTo(){return blackboard.getMoveTo();}
	float getMoveForce(){return blackboard.getMoveForce();}

	ControllerBase* getTarget(){return blackboard.getTarget();}
	CommandType getCommand(){return blackboard.getCommand();}

	BehaviorType getType(){return CONTROL_BEHAVIOR;}

protected:
	bool doStep(int);

	AIBlackboard blackboard;
	AINode* tree;
};

