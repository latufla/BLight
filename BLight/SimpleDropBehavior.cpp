#include "SimpleDropBehavior.h"
#include "PopupManager.h"

SimpleDropBehavior::SimpleDropBehavior(void)
{
}

SimpleDropBehavior::SimpleDropBehavior(int drop)
{
	this->drop = drop;
	target = nullptr;
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
	if(this->target != nullptr)
		return false;

	this->target = target;
	return true;
}

bool SimpleDropBehavior::doStep(int step)
{
	__super::doStep(step);

	if(target == nullptr)
		return false;

	command.setUp(this, target, target->getEnergyProp(), drop);
	if(command.tryToExecute()){
		showPopup(controller);

		FieldController::getInstance().destroyObjectController(controller);
		target = nullptr;
		return true;
	}
	return false;
}

BehaviorBase* SimpleDropBehavior::clone()
{
	return new SimpleDropBehavior(drop);
}

void SimpleDropBehavior::showPopup(ControllerBase* c)
{
	PopupText* p = new PopupText();
	p->setText("" + string(drop > 0 ? "+" : "-") + to_string(long long(drop)));
	p->getPosition().set(c->getObject()->getGlobalCenter());
	PopupManager::getInstance().add(p);
}
