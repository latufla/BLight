#pragma once
#include "AINode.h"

class StopMoveAINode : public AINode
{
public:
	StopMoveAINode(void);
	StopMoveAINode(AIBlackboard*);
	
	~StopMoveAINode(void);

	bool run();
};

