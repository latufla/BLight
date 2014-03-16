#pragma once
#include "AINode.h"

class SelectorAINode : public AINode
{
public:
	SelectorAINode(void);
	~SelectorAINode(void);

	bool run();
};

