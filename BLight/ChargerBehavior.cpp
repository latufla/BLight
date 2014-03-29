#include "ChargerBehavior.h"
#include "Config.h"

ChargerBehavior::ChargerBehavior(void)
{
	target = nullptr;
}


ChargerBehavior::~ChargerBehavior(void)
{
}


bool ChargerBehavior::start(ControllerBase* c)
{
	__super::start(c);

	controller->getObject()->setSensor(true);
	Config::phEngine->addContactReceiver(this);
	
	return true;
}

bool ChargerBehavior::stop()
{
	controller->getObject()->setSensor(false);
	Config::phEngine->removeContactReceiver(this);

	__super::stop();
	
	return true;
}


bool ChargerBehavior::doStep(int step)
{
	__super::doStep(step);

	if(target == nullptr)
		return false;

	command.setUp(this, target, 1);
	return command.tryToExecute();
}

bool ChargerBehavior::onBeginInteraction(ObjectBase* target)
{
	this->target = target;
	return true;
}

bool ChargerBehavior::onEndInteraction(ObjectBase* target)
{
	if(this->target == target){
		this->target = nullptr;
		return true;
	}	
	return false;
}

BehaviorBase* ChargerBehavior::clone()
{
	return new ChargerBehavior();
}

