#include "DestroyCommand.h"
#include "Config.h"
#include "Infos.h"


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
	this->target = targetToDestroy->getObject();
}

bool DestroyCommand::canExecute()
{
	return targetToDestroy && !targetToDestroy->getToDestroy();
}

void DestroyCommand::execute()
{
	ObjectBase* cObj = caller->getController()->getObject();
	ObjectInfo* info = Infos::getInstance().getObjectInfoBy(cObj->getName());
	DropInfo* drop = info->drop[getType()];

	if(drop != nullptr)
		showPopup(drop->target, cObj->getGlobalCenter());

	__super::execute();

	Config::field->destroyObjectController(targetToDestroy);
}

bool DestroyCommand::canShowPopup()
{
	return true;
}
