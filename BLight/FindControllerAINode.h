#pragma once
#include "AINode.h"
#include "BehaviorBase.h"

class FindControllerAINode : public AINode
{
public:
	FindControllerAINode(void);
	FindControllerAINode(AIBlackboard*, BehaviorType);

	~FindControllerAINode(void);

	bool run();

protected:
	BehaviorType bType;
};

