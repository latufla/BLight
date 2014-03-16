#pragma once
#include "AINode.h"

class CheckPropAINode : public AINode
{
public:
	CheckPropAINode(void);
	CheckPropAINode(AIBlackboard*, int*, int);
	~CheckPropAINode(void);

	bool run();

protected:
	int* prop;
	int val;
};

