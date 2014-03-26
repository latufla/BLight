#include "DestroyCommand.h"
#include "Config.h"


DestroyCommand::DestroyCommand(void)
{
}


DestroyCommand::~DestroyCommand(void)
{
}

void DestroyCommand::setUp(BehaviorBase* caller, ControllerBase* target)
{
	this->caller = caller;
	this->target = target;
}

bool DestroyCommand::canExecute()
{
	return target 
		&& !target->getToDestroy() 
		&& __super::canExecute();
}

void DestroyCommand::execute()
{
	Config::field->destroyObjectController(target);
}
