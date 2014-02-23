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
	int getForce();

private:
	GamepadBehavior* gamepad;

};

