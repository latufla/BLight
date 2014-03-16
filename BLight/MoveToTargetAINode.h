#pragma once
#include "AINode.h"

class MoveToTargetAINode : public AINode
{
public:
	MoveToTargetAINode(void);
	MoveToTargetAINode(AIBlackboard*);

	~MoveToTargetAINode(void);

	bool run();
};

