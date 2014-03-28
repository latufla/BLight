#include "AttackBehavior.h"
#include "PopupManager.h"


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
	if(command == ATTACK_COMMAND && cTarget != nullptr){
		AttackCommand attack;
		attack.setUp(this, cTarget, damage);		
		if(attack.tryToExecute()){
			showPopup(cTarget);
			return true;
		}
	}

	return false;
}

BehaviorBase* AttackBehavior::clone()
{
	return new AttackBehavior();
}

void AttackBehavior::showPopup(ControllerBase* c)
{
	PopupText* p = new PopupText();
	p->setText("" + string(damage > 0 ? "+" : "") + to_string(long long(damage)));
	p->getPosition().set(c->getObject()->getGlobalCenter());
	PopupManager::getInstance().add(p);
}