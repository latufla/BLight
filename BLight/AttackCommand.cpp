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
	return __super::canExecute() 
		&& caller->getController()->getObject()->getEnergy() > 0 
		&& target->getEnergy() > 0;
}

void AttackCommand::execute()
{
	ObjectBase* cObj = caller->getController()->getObject();
	ObjectInfo* info = Infos::getInfoBy(cObj->getName());
	DropInfo* drop = info->drop[getType()];

	if(drop != nullptr){
		showPopup(drop->caller, cObj->getGlobalCenter());
		showPopup(drop->target, target->getGlobalCenter());
	}
	
	__super::execute();
}

bool AttackCommand::canShowPopup()
{
	return true;
}
