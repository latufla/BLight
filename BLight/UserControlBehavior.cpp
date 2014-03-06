#include "UserControlBehavior.h"

UserControlBehavior::UserControlBehavior(void)
{
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
	return true;
}

CustomPoint* UserControlBehavior::getDestination()
{
	return gamepad.getTouch();
}
