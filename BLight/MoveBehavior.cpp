#include "MoveBehavior.h"

MoveBehavior::MoveBehavior(void)
{
}


MoveBehavior::~MoveBehavior(void)
{
}

bool MoveBehavior::doStep(int step)
{
	if(!enabled)
		return false;

	__super::doStep(step);
	
	BehaviorBase* control = controller->getBehaviorBy(USER_CONTROL);
	if(control == nullptr)
		return false;
	
	CustomPoint* dest = ((ControlBehavior*)control)->getDestination();	
	if(dest == nullptr)
		return false;

	CustomPoint pos = controller->getObject()->getPosition();
	CustomPoint impulse = *dest;
	impulse.x = impulse.x - pos.x;
	impulse.y = impulse.y - pos.y;
	impulse.normalize();
	controller->getObject()->applyLinearImpulse(&impulse);		
	return true;
}
