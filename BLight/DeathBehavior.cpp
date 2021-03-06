#include "DeathBehavior.h"
#include "DestroyCommand.h"


DeathBehavior::DeathBehavior(void) : BehaviorBase()
{
}

DeathBehavior::DeathBehavior(Info* info) : BehaviorBase(info)
{
}

DeathBehavior::~DeathBehavior(void)
{
}

bool DeathBehavior::doStep(int step)
{
	__super::doStep(step);

	if(controller->getObject()->getEnergy() <= 0){
		DestroyCommand destroy;
		destroy.setUp(this, controller);
		return destroy.tryToExecute();
	}

	return false;
}
