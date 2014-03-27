#include "CreateCommand.h"

int CreateCommand::id = 6;


CreateCommand::CreateCommand(void)
{
}

CreateCommand::~CreateCommand(void)
{
	creature = nullptr;
}


void CreateCommand::setUp(BehaviorBase* caller, ObjectInfo* info)
{
	this->caller = caller;
	this->info = info;
}

bool CreateCommand::canExecute()
{
	return true;
}

void CreateCommand::execute()
{
	creature = Config::field->createObjectController(id++, *info, caller->getController()->getObject()->getPosition());
	creature->startBehaviors();
	Config::scene->addChild(creature->getView());
}

