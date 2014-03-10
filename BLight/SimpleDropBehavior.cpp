#include "SimpleDropBehavior.h"
#include "SceneController.h"


SimpleDropBehavior::SimpleDropBehavior(void)
{
}

SimpleDropBehavior::SimpleDropBehavior(int drop)
{
	this->drop = drop;
	processed = false;
}


SimpleDropBehavior::~SimpleDropBehavior(void)
{
}


bool SimpleDropBehavior::start(ControllerBase* c)
{
	__super::start(c);
	
	controller->getObject()->setSensor(true);
	PhEngineConnector::getInstance().addContactReceiver(this);

	return true;
}

bool SimpleDropBehavior::stop()
{
	controller->getObject()->setSensor(false);
	PhEngineConnector::getInstance().removeContactReceiver(this);

	__super::stop();

	return true;	
}


bool SimpleDropBehavior::onBeginInteraction(ObjectBase* target)
{
	if(processed)
		return false;

	command.setUp(this, target, target->getEnergyProp(), drop);
	processed = command.tryToExecute();
	return processed;
}

bool SimpleDropBehavior::doStep(int step)
{
	__super::doStep(step);

	if(processed){
		// destroy here
	}

	return true;
}
