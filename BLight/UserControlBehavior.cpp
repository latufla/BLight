#include "UserControlBehavior.h"
#include "Config.h"

UserControlBehavior::UserControlBehavior(void)
{
	target = nullptr;
}


UserControlBehavior::~UserControlBehavior(void)
{
	gamepad.stop();
}

bool UserControlBehavior::start(ControllerBase* c)
{
	__super::start(c);
	
	gamepad.start(c);
	return true;
}

bool UserControlBehavior::stop()
{
	__super::stop();
	
	gamepad.stop();
	return true;
}

bool UserControlBehavior::doStep(int step)
{
	__super::doStep(step);
	
	gamepad.tryDoStep(step);
	action = NONE_ACTION;

	CustomPoint* touch = gamepad.getTouch();
	if(touch == nullptr)
		return false;

	vector<ControllerBase*>& controllers = Config::field->getControllers(); // TODO: optimize
	for(auto it = controllers.cbegin(); it != controllers.cend(); ++it){
		if((*it)->getObject()->contains(*touch)){
			target = *it;
			break;
		}
	}			

	if(target != nullptr){
		action = ATTACK_ACTION;
		return true;
	}
	
	return false;
}

CustomPoint* UserControlBehavior::getMoveTo()
{
	return gamepad.getTouch();
}

BehaviorBase* UserControlBehavior::clone()
{
	return new UserControlBehavior();
}
