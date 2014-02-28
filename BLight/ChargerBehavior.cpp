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


bool ChargerBehavior::doStep( int step )
{
	if(!enabled)
		return false;

	__super::doStep(step);
	
	if(chargingObject == nullptr)
		return false;

	int energy = chargingObject->getEnergy();
	if(energy >= 100)
		return false;	
		
	chargingObject->setEnergy(++energy);
	EngineConnector::printDebug(to_string(long long(chargingObject->getEnergy())));
	return true;
}

bool ChargerBehavior::onBeginInteraction( ObjectBase* obj1, ObjectBase* obj2)
{

	ObjectBase* charger = controller->getObject();
	if(*charger == *obj1){
		chargingObject = obj2;
		return true;
	} else if(*charger == *obj2){
		chargingObject = obj1;
		return true;
	}
	
	
	return false;
}

bool ChargerBehavior::onEndInteraction( ObjectBase* obj1, ObjectBase* obj2)
{
	ObjectBase* charger = controller->getObject();
	if(*charger == *obj1 || *charger == *obj2){
		chargingObject = nullptr;
		return true;
	}	

	return false;
}

