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

	target = nullptr;
	action = NONE_ACTION;

	CustomPoint* pos = gamepad.getTouch();
	
	if(pos == nullptr)
		pos = gamepad.getOverPoint();	
		
	vector<ControllerBase*>& controllers = Config::field->getControllers(); // TODO: optimize
	for(auto it = controllers.cbegin(); it != controllers.cend(); ++it){
		if((*it)->getObject()->contains(*pos)){
			target = *it;
			break;
		}
	}			

	if(target != nullptr){
		if(pos == gamepad.getTouch() && target->getName() == "aiDummy")
			action = ATTACK_ACTION;
		else if(pos == gamepad.getOverPoint())
			action = APPLY_ACTION;
		
		return true;
	}
	
	return false;
}

CustomPoint* UserControlBehavior::getMoveTo()
{
	return action == NONE_ACTION ? gamepad.getTouch() : nullptr;
}

BehaviorBase* UserControlBehavior::clone()
{
	return new UserControlBehavior();
}
