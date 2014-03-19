#pragma once
#include "AIBlackboard.h"
#include "ControlBehavior.h"
#include "AINode.h"

class AIControlBehavior : public ControlBehavior
{
public:
	AIControlBehavior(void);
	~AIControlBehavior(void);
	
	BehaviorBase* clone();

	bool start(ControllerBase*);
//	virtual bool stop();
//	virtual bool tryDoStep(int); // frame behavior

	CustomPoint* getMoveTo(){return blackboard.getMoveTo();}
	float getMoveForce(){return blackboard.getMoveForce();}

	ControllerBase* getTarget(){return blackboard.getTarget();}
	ControlAction getAction(){return blackboard.getAction();}

	BehaviorType getType(){return CONTROL_BEHAVIOR;}

protected:
	bool doStep(int);

	AIBlackboard blackboard;
	AINode* tree;
};

