#include "MoveBehavior.h"

MoveBehavior::MoveBehavior(void)
{
}


MoveBehavior::~MoveBehavior(void)
{
}

bool MoveBehavior::doStep(int step)
{
	__super::doStep(step);
	
	ControlBehavior* control = (ControlBehavior*)controller->getBehaviorBy(USER_CONTROL_BEHAVIOR);
	if(control == nullptr)
		return false;
	
	CustomPoint* dest = control->getMoveTo();	
	if(dest == nullptr)
		return false;

	CustomPoint& pos = controller->getObject()->getPosition();
	static CustomPoint force;
	force.x = dest->x - pos.x;
	force.y = dest->y - pos.y;
	
	if(shouldStop(force)){
		applyStoppage();
		return false;
	}

	force.normalize(control->getMoveForce());	
	controller->getObject()->applyForce(force);
	return true;
}

bool MoveBehavior::shouldStop(CustomPoint& force)
{
	return force.getLength() < .1f;
}

void MoveBehavior::applyStoppage()
{
	static CustomPoint vel(0.0f, 0.0f);
	controller->getObject()->setLinearVelocity(vel);	
}



