#include "AIControlBehavior.h"
#include "CheckPropAINode.h"
#include "SequenceAINode.h"
#include "FindControllerAINode.h"
#include "MoveToTargetAINode.h"
#include "SelectorAINode.h"
#include "StopMoveAINode.h"


AIControlBehavior::AIControlBehavior(void)
{
}


AIControlBehavior::~AIControlBehavior(void)
{
}

bool AIControlBehavior::start(ControllerBase* c)
{
	__super::start(c);
	
	tree = new SelectorAINode();	

	SequenceAINode* sequence = new SequenceAINode();
	
	sequence->getChildren().push_back(new CheckPropAINode(&blackboard, c->getObject()->getEnergyProp(), 100));
	sequence->getChildren().push_back(new FindControllerAINode(&blackboard, SIMPLE_DROP_BEHAVIOR));
	sequence->getChildren().push_back(new MoveToTargetAINode(&blackboard));

	tree->getChildren().push_back(sequence);
	tree->getChildren().push_back(new StopMoveAINode(&blackboard));
	return true;
}

bool AIControlBehavior::doStep(int step)
{
	__super::doStep(step);
	
	return tree->run();
}


