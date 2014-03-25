#include "CreateCommand.h"

int CreateCommand::id = 6;


CreateCommand::CreateCommand(void)
{
}

CreateCommand::~CreateCommand(void)
{
}


void CreateCommand::setUp(BehaviorBase* caller, ObjectInfo* creature)
{
	this->caller = caller;
	this->creature = creature;
}

bool CreateCommand::tryToExecute()
{
	if(canExecute()){
		execute();
		return true;
	}
	return false;
}

bool CreateCommand::canExecute()
{
	return true;
}

void CreateCommand::execute()
{
	ControllerBase* c = Config::field->createObjectController(id++, *creature, caller->getController()->getObject()->getPosition());
	c->startBehaviors();
	Config::scene->addChild(c->getView());
}

