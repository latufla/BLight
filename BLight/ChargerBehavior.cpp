#include "ChargerBehavior.h"

ChargerBehavior::ChargerBehavior(void)
{
	chargingObject = nullptr;
}


ChargerBehavior::~ChargerBehavior(void)
{
}


bool ChargerBehavior::start(ControllerBase* c)
{
	__super::start(c);

	PhEngineConnector::getInstance().addContactReceiver(this);
	return true;
}

bool ChargerBehavior::stop()
{
	__super::stop();

	// remove collision listener

	return true;
}


bool ChargerBehavior::doStep(int step)
{
	__super::doStep(step);

	if(chargingObject == nullptr)
		return false;

	command.setUp(this, chargingObject, chargingObject->getEnergyProp(), 1);
	return command.tryToExecute();
}

bool ChargerBehavior::onBeginInteraction(ObjectBase* target)
{
	chargingObject = target;
	return true;
}

bool ChargerBehavior::onEndInteraction(ObjectBase* target)
{
	if(chargingObject == target){
		chargingObject = nullptr;
		return true;
	}	
	return false;
}

