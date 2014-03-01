#include "UserControlBehavior.h"

UserControlBehavior::UserControlBehavior(void)
{
	gamepad = new GamepadBehavior();
}


UserControlBehavior::~UserControlBehavior(void)
{
	gamepad->stop();
	delete gamepad;
}

bool UserControlBehavior::start(ControllerBase* c)
{
	__super::start(c);
	
	gamepad->start(c);
	return true;
}

bool UserControlBehavior::stop()
{
	__super::stop();
	
	gamepad->stop();
	return true;
}

bool UserControlBehavior::doStep(int step)
{
	__super::doStep(step);

	gamepad->tryDoStep(step);
	return true;
}

CustomPoint* UserControlBehavior::getDestination()
{
	return gamepad->getTouch();
}

float UserControlBehavior::getForce()
{
	return 15.0f;
}
