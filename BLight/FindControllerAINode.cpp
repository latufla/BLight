#include "FindControllerAINode.h"
#include "FieldController.h"


FindControllerAINode::FindControllerAINode(void)
{
}

FindControllerAINode::FindControllerAINode(AIBlackboard* blackboard, BehaviorType bType)
{
	this->blackboard = blackboard;
	this->bType = bType;
}


FindControllerAINode::~FindControllerAINode(void)
{
}

bool FindControllerAINode::run()
{
	if(blackboard->getTarget() != nullptr)
		return true;

	vector<ControllerBase*> targets;
	vector<ControllerBase*>& cs = FieldController::getInstance().getControllers();
	for(auto it = cs.cbegin(); it != cs.cend(); it++){
		if((*it)->getBehaviorBy(bType) != nullptr)
			targets.push_back(*it);
	}

	if(targets.size() == 0){
		blackboard->setTarget(nullptr);
		return false;
	}

	ControllerBase* target = targets[0];
	blackboard->setTarget(target);
	return true;
}
