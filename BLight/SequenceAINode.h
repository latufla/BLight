#pragma once
#include "AINode.h"

class SequenceAINode : public AINode 
{
public:
	SequenceAINode(void);
	SequenceAINode(AIBlackboard*);

	~SequenceAINode(void);

	bool run();
};

