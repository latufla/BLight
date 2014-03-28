#include "UserControlBehavior.h"
#include "Config.h"
#include "Infos.h"

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
	command = NONE_COMMAND;

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
		if(pos == gamepad.getTouch())
			command = ATTACK_COMMAND;
		else if(pos == gamepad.getOverPoint())
			command = APPLY_COMMAND;
		
		return true;
	}
	
	return false;
}

CustomPoint* UserControlBehavior::getMoveTo()
{
	return command == NONE_COMMAND ? gamepad.getTouch() : nullptr;
}

BehaviorBase* UserControlBehavior::clone()
{
	return new UserControlBehavior();
}
