#include "ChargeCommand.h"


ChargeCommand::ChargeCommand(void)
{
}


ChargeCommand::~ChargeCommand(void)
{
}

void ChargeCommand::setUp(BehaviorBase* caller, ObjectBase* target, int charge)
{
	this->caller = caller;
	this->target = target;
	this->charge = charge;
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
	int energy = target->getEnergy();
	target->setEnergy(energy + charge);
}
