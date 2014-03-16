#pragma once
#include "AINode.h"

class SequenceAINode : public AINode 
{
public:
	SequenceAINode(void);
	~SequenceAINode(void);

	bool run();
};

