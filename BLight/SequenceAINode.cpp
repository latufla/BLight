#include "SequenceAINode.h"


SequenceAINode::SequenceAINode(void)
{
}

SequenceAINode::~SequenceAINode(void)
{
}

bool SequenceAINode::run()
{
	for(auto it = children.cbegin(); it != children.cend(); it++){
		if(!(*it)->run())
			return false;
	}
	return true;
}
