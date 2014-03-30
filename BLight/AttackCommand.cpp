#include "AttackCommand.h"
#include "Infos.h"


AttackCommand::AttackCommand(void)
{
}


AttackCommand::~AttackCommand(void)
{
}

void AttackCommand::setUp(BehaviorBase* caller, ObjectBase* target)
{
	this->caller = caller;
	this->target = target;
}

bool AttackCommand::canExecute()
{
	return __super::canExecute() && target->getEnergy() > 0;
}

void AttackCommand::execute()
{
	ObjectBase* cObj = caller->getController()->getObject();
	ObjectInfo* info = Infos::getInfoBy(cObj->getName());
	DropInfo* drop = info->drop[getType()]->first;
	showPopup(drop, cObj->getGlobalCenter());
	
	drop = info->drop[getType()]->second;
	showPopup(drop, target->getGlobalCenter());
	
	__super::execute();
}

bool AttackCommand::canShowPopup()
{
	return true;
}
