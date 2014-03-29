#include "SimpleDropBehavior.h"
#include "DestroyCommand.h"
#include "ControlBehavior.h"
#include "ChargeCommand.h"

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
	Config::phEngine->addContactReceiver(this);

	return true;
}

bool SimpleDropBehavior::stop()
{
	controller->getObject()->setSensor(false);
	Config::phEngine->removeContactReceiver(this);

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

	ControlBehavior* control = (ControlBehavior*)Config::player->getBehaviorBy(CONTROL_BEHAVIOR);
	if(control == nullptr)
		return false;

	if(control->getCommand() == APPLY_COMMAND && control->getTarget() == controller)
		target = Config::player->getObject();
	
	if(target == nullptr)
		return false;
		
	ChargeCommand charge;
	charge.setUp(this, target, drop);
	if(charge.tryToExecute()){
		showPopup(controller);

		DestroyCommand destroy;
		destroy.setUp(this, controller);
		destroy.tryToExecute();

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
