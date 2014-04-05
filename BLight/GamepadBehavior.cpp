#include "GamepadBehavior.h"
#include "Config.h"

GamepadBehavior::GamepadBehavior(void) : BehaviorBase()
{
}

GamepadBehavior::~GamepadBehavior(void)
{
}


CustomPoint* GamepadBehavior::getTouch()
{
	if(!Config::engine->isLeftMouseButtonPressed())
		return nullptr;

	CustomPoint& pos = Config::engine->getMousePosition();
	touch.x = pos.x;
	touch.y = pos.y;
	return &touch;
}

CustomPoint* GamepadBehavior::getOverPoint()
{
	CustomPoint& pos = Config::engine->getMousePosition();
	overPoint.x = pos.x;
	overPoint.y = pos.y;
	return &overPoint;	
}


