#include "ChargePackBehavior.h"
#include "DestroyCommand.h"
#include "ControlBehavior.h"
#include "ChargeCommand.h"

ChargePackBehavior::ChargePackBehavior(void)
{
	target = nullptr;
}

ChargePackBehavior::~ChargePackBehavior(void)
{
}


bool ChargePackBehavior::start(ControllerBase* c)
{
	__super::start(c);
	
	controller->getObject()->setSensor(true);
	Config::phEngine->addContactReceiver(this);

	return true;
}

bool ChargePackBehavior::stop()
{
	controller->getObject()->setSensor(false);
	Config::phEngine->removeContactReceiver(this);

	__super::stop();

	return true;	
}


bool ChargePackBehavior::onBeginInteraction(ObjectBase* target)
{
	if(this->target != nullptr)
		return false;

	this->target = target;
	return true;
}

bool ChargePackBehavior::doStep(int step)
{
	__super::doStep(step);

	ControlBehavior* control = (ControlBehavior*)Config::player->getBehaviorBy(CONTROL_BEHAVIOR);
	if(control == nullptr)
		return false;

	if(control->getCommand() == APPLY_COMMAND && control->getTarget() == controller)
		target = Config::player->getObject();
	
	if(target == nullptr)
		return false;
		
	ChargeCommand charge;
	charge.setUp(this, target);
	if(charge.tryToExecute()){
		DestroyCommand destroy;
		destroy.setUp(this, controller);
		destroy.tryToExecute();

		target = nullptr;
		return true;
	}
	return false;
}

BehaviorBase* ChargePackBehavior::clone()
{
	return new ChargePackBehavior();
}
