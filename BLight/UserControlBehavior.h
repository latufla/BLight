#pragma once
#include "ControlBehavior.h"
#include "CustomPoint.h"
#include "GamepadBehavior.h"

class UserControlBehavior : public ControlBehavior
{
public:
	UserControlBehavior(void);
	~UserControlBehavior(void);
	
	bool start(ControllerBase*);
	bool stop();
	
	CustomPoint* getDestination();
	float getForce(){return 15.0f;}

	BehaviorType getType(){return USER_CONTROL_BEHAVIOR;};

private:	
	bool doStep(int);

	GamepadBehavior gamepad;
};

