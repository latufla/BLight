#include "DestroyCommand.h"
#include "Config.h"


DestroyCommand::DestroyCommand(void)
{
}


DestroyCommand::~DestroyCommand(void)
{
}

void DestroyCommand::setUp(BehaviorBase* caller, ControllerBase* targetToDestroy)
{
	this->caller = caller;
	this->targetToDestroy = targetToDestroy;
}

bool DestroyCommand::canExecute()
{
	return targetToDestroy && !targetToDestroy->getToDestroy();
}

void DestroyCommand::execute()
{
	Config::field->destroyObjectController(targetToDestroy);
}
