#include "AttackCommand.h"
#include "Infos.h"


AttackCommand::AttackCommand(void)
{
}


AttackCommand::~AttackCommand(void)
{
}

void AttackCommand::setUp(BehaviorBase* caller, ObjectBase* target, int damage)
{
	this->caller = caller;
	this->target = target;
	this->damage = damage;
}

bool AttackCommand::canExecute()
{
	return __super::canExecute() && target->getEnergy() > 0;
}

void AttackCommand::execute()
{
	int energy = target->getEnergy() - damage;
	target->setEnergy(energy >= 0 ? energy : 0);
}
