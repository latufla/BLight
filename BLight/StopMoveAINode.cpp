#include "StopMoveAINode.h"


StopMoveAINode::StopMoveAINode(void)
{
}

StopMoveAINode::StopMoveAINode(AIBlackboard* blackboard)
{
	this->blackboard = blackboard;
}


StopMoveAINode::~StopMoveAINode(void)
{
}

bool StopMoveAINode::run()
{		
	blackboard->setMoveTo(nullptr);
	return true;
}
