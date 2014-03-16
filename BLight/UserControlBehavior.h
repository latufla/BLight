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
	
	CustomPoint* getMoveTo();
	float getMoveForce(){return 15.0f;}

	ControllerBase* getTarget(){return nullptr;}
	ControlAction getAction(){return NONE_ACTION;}

	BehaviorType getType(){return CONTROL_BEHAVIOR;}

private:	
	bool doStep(int);

	GamepadBehavior gamepad;
};

