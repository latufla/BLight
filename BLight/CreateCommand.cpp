#include "CreateCommand.h"

int CreateCommand::id = 6;


CreateCommand::CreateCommand(void)
{
	creature = nullptr;
}

CreateCommand::~CreateCommand(void)
{
	
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
	CustomPoint pos = caller->getController()->getObject()->getPosition();
	pos.x -= 1.0;
	pos.y += 1.0;
	creature = Config::field->createObjectController(id++, *info, pos);
	creature->startBehaviors();
	Config::scene->addChild(creature->getView());
}

