#include "ChargerBehavior.h"
#include "Scene.h"

ChargerBehavior::ChargerBehavior(void)
{
	chargingObject = nullptr;

	debugEnergyText.setText("Energy: 20");
	debugEnergyText.setFont("tahoma");
	Scene::getInstance().addChild(&debugEnergyText);
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

	int energy = chargingObject->getEnergy();
	if(energy >= 100)
		return false;	
		
	chargingObject->setEnergy(++energy);
	debugEnergyText.setText("Energy: " + to_string(long long(energy)));
	return true;
}

bool ChargerBehavior::onBeginInteraction(ObjectBase* target)
{
	chargingObject = target;
	return true;
}

bool ChargerBehavior::onEndInteraction(ObjectBase* target)
{
	if(*chargingObject == *target){
		chargingObject = nullptr;
		return true;
	}	
	return false;
}

