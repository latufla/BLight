#include "AttackBehavior.h"
#include "PopupManager.h"
#include "Infos.h"


AttackBehavior::AttackBehavior(void)
{
	damage = 20;
}


AttackBehavior::~AttackBehavior(void)
{
}

bool AttackBehavior::doStep(int step)
{
	__super::doStep(step);

	ControlBehavior* control = (ControlBehavior*)controller->getBehaviorBy(CONTROL_BEHAVIOR);
	if(control == nullptr)
		return false;

	CommandType command = control->getCommand();
	ControllerBase* cTarget = control->getTarget();
	if(!cTarget || command != ATTACK_COMMAND)
		return false;

	AttackCommand attack;
	attack.setUp(this, cTarget->getObject());		
	return attack.tryToExecute();
}

BehaviorBase* AttackBehavior::clone()
{
	return new AttackBehavior();
}