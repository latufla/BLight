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
	float getForce();

	BehaviorType getType(){return USER_CONTROL;};

private:	
	bool doStep(int);

	GamepadBehavior* gamepad;
};

