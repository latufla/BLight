#include "CheckPropAINode.h"

CheckPropAINode::CheckPropAINode(void)
{
}

CheckPropAINode::CheckPropAINode(AIBlackboard* blackboard, int* prop, int val)
{
	this->blackboard = blackboard;
	this->prop = prop;
	this->val = val;
}

CheckPropAINode::~CheckPropAINode(void)
{
}

bool CheckPropAINode::run()
{
	return *prop <= val;
}

