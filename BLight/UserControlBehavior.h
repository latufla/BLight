#pragma once
#include "ControlBehavior.h"
#include "CustomPoint.h"
#include "GamepadBehavior.h"

class UserControlBehavior : public ControlBehavior
{
public:
	UserControlBehavior(void);
	~UserControlBehavior(void);
	
	BehaviorBase* clone();

	bool start(ControllerBase*);
	bool stop();
	
	CustomPoint* getMoveTo();
	float getMoveForce(){return 15.0f;}

	ControllerBase* getTarget(){return target;}
	ControlAction getAction(){return action;}

	BehaviorType getType(){return CONTROL_BEHAVIOR;}

private:	
	bool doStep(int);

	GamepadBehavior gamepad;
	ControllerBase* target;
	ControlAction action;
};

