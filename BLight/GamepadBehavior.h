#pragma once
#include "stdafx.h"
#include "BehaviorBase.h"
#include "EngineConnector.h"

class GamepadBehavior : public BehaviorBase
{
public:
	GamepadBehavior(void);
	~GamepadBehavior(void);

	CustomPoint* getTouch();

private:
	CustomPoint* touch;
};

