#include "CreateCommand.h"
#include "StatusViewManager.h"

int CreateCommand::id = 6;


CreateCommand::CreateCommand(void)
{
	creature = nullptr;
}

CreateCommand::~CreateCommand(void)
{
	
}


void CreateCommand::setUp(BehaviorBase* caller, ObjectInfo* info, const CustomPoint& position)
{
	this->caller = caller;
	this->info = info;
	this->position = position;
}

bool CreateCommand::canExecute()
{
	return true;
}

void CreateCommand::execute()
{
	creature = Config::field->createObjectController(id++, *info, position);
	creature->startBehaviors();
	Config::scene->addChild(creature->getView());
	
	if(creature->getDisplayStatus())
		StatusViewManager::getInstance().addStatusView(creature);
}

