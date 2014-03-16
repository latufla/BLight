#include "MoveToTargetAINode.h"


MoveToTargetAINode::MoveToTargetAINode(void)
{
}

MoveToTargetAINode::MoveToTargetAINode(AIBlackboard* blackboard)
{
	this->blackboard = blackboard;
}


MoveToTargetAINode::~MoveToTargetAINode(void)
{
}


bool MoveToTargetAINode::run()
{
	ControllerBase* target = blackboard->getTarget();
	if(target == nullptr || target->getToDestroy()){
		blackboard->setMoveTo(nullptr);
		return false;
	}
	
	CustomPoint* pos = new CustomPoint();
	pos->set(target->getObject()->getPosition());
	blackboard->setMoveTo(pos);
	return true;
}
