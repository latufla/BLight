#include "AIControlBehavior.h"
#include "CheckPropAINode.h"
#include "SequenceAINode.h"
#include "FindControllerAINode.h"
#include "MoveToTargetAINode.h"


AIControlBehavior::AIControlBehavior(void)
{
}


AIControlBehavior::~AIControlBehavior(void)
{
}

bool AIControlBehavior::start(ControllerBase* c)
{
	__super::start(c);
	
	tree = new SequenceAINode(&blackboard);	
	tree->getChildren().push_back(new CheckPropAINode(&blackboard, c->getObject()->getEnergyProp(), 100));
	tree->getChildren().push_back(new FindControllerAINode(&blackboard, SIMPLE_DROP_BEHAVIOR));
	tree->getChildren().push_back(new MoveToTargetAINode(&blackboard));
	
	return true;
}

bool AIControlBehavior::doStep(int step)
{
	__super::doStep(step);
	
	return tree->run();
}


