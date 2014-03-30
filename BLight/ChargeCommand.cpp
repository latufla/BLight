#include "ChargeCommand.h"
#include "Infos.h"
#include "PopupManager.h"


ChargeCommand::ChargeCommand(void)
{
}


ChargeCommand::~ChargeCommand(void)
{
}

void ChargeCommand::setUp(BehaviorBase* caller, ObjectBase* target)
{
	this->caller = caller;
	this->target = target;
}

bool ChargeCommand::canExecute()
{
	BehaviorType bType = caller->getType();
	int energy = target->getEnergy();
	bool res = true;
	switch(bType){
		case CHARGER_BEHAVIOR:
			res = energy < 100;
			break;
		default: ;
			// do nothing
	}

	return res && __super::canExecute();
}

void ChargeCommand::execute()
{
	ObjectBase* cObj = caller->getController()->getObject();
	ObjectInfo* info = Infos::getInfoBy(cObj->getName());
	DropInfo* drop = info->drop[getType()];

	if(drop != nullptr)
		showPopup(drop->target, cObj->getGlobalCenter());

	__super::execute();
}

bool ChargeCommand::canShowPopup()
{
	return caller->getType() == CHARGE_PACK_BEHAVIOR;
}


