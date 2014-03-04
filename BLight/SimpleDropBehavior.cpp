#include "SimpleDropBehavior.h"
#include "PopupText.h"
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

	__super::stop();
	return true;	
}


bool SimpleDropBehavior::onBeginInteraction(ObjectBase* target)
{
	if(processed)
		return false;

	int energy = target->getEnergy() + drop;
	target->setEnergy(energy);

	SceneController& scene = SceneController::getInstance();
	scene.getEnergyText()->setText("Energy: " + to_string(long long(energy)));

	// TODO: dirty leak stuff
	PopupText* debugPopUp = new PopupText();
	debugPopUp->setText((drop >= 0 ? "+" : "-") + to_string(long long(drop)));
	CustomPoint pos = controller->getObject()->getPosition();
	debugPopUp->setPosition(&pos);
	
	SceneController::getInstance().addChild((TextBase*)debugPopUp);		
	//

	return processed = true;
}

bool SimpleDropBehavior::doStep(int step)
{
	__super::doStep(step);

	if(processed){
		// destroy here
	}

	return true;
}
