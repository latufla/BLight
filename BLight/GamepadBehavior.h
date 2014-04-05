#pragma once
#include "stdafx.h"
#include "BehaviorBase.h"

class GamepadBehavior : public BehaviorBase
{
public:
	GamepadBehavior(void);
	~GamepadBehavior(void);

	CustomPoint* getOverPoint();
	CustomPoint* getTouch();
	
	BehaviorType getType(){return GAMEPAD_BEHAVIOR;}

private:
	CustomPoint touch;
	CustomPoint overPoint;
};

