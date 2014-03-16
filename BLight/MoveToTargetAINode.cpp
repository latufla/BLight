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


// TODO: fix leak
bool MoveToTargetAINode::run()
{
	ControllerBase* target = blackboard->getTarget();
	CustomPoint* pos = new CustomPoint();
	pos->set(target->getObject()->getPosition());
	blackboard->setMoveTo(pos);
	return true;
}
