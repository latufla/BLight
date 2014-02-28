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
	bool doStep(int);

	CustomPoint* getDestination();
	float getForce();

	BehaviorType getType(){return USER_CONTROL;};

private:
	GamepadBehavior* gamepad;

};

