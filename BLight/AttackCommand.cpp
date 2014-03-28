#include "AttackCommand.h"


AttackCommand::AttackCommand(void)
{
}


AttackCommand::~AttackCommand(void)
{
}

void AttackCommand::setUp(BehaviorBase* caller, ControllerBase* target, int damage)
{
	this->caller = caller;
	this->target = target;
	this->damage = damage;
}

bool AttackCommand::canExecute()
{
	return target->getObject()->getEnergy() > 0;
}

void AttackCommand::execute()
{
	ObjectBase* obj = target->getObject();
	int energy = obj->getEnergy() - damage;
	obj->setEnergy(energy >= 0 ? energy : 0);
}
