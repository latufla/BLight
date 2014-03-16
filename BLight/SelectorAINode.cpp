#include "SelectorAINode.h"


SelectorAINode::SelectorAINode(void)
{
}


SelectorAINode::~SelectorAINode(void)
{
}

bool SelectorAINode::run()
{
	for(auto it = children.cbegin(); it != children.cend(); it++){
		if((*it)->run())
			return true;
	}
	return false;
}
