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
	if(!enabled)
		return false;

	__super::doStep(step);

	gamepad->doStep(step);

	CustomPoint* dest = getDestination();
	if(dest != nullptr){
		CustomPoint pos = controller->getObject()->getGlobalCenter();
		CustomPoint impulse = *dest;
		impulse.x = impulse.x - pos.x; // TODO: EngineConnector axises
		impulse.y = impulse.y - pos.y;
		impulse.normalize();
		controller->getObject()->applyLinearImpulse(&impulse);
	}

	return true;
}

CustomPoint* UserControlBehavior::getDestination()
{
	return gamepad->getTouch();
}

int UserControlBehavior::getForce()
{
	return 10;
}
