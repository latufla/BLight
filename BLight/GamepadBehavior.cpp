#include "GamepadBehavior.h"
#include "Config.h"

GamepadBehavior::GamepadBehavior(void)
{
}

GamepadBehavior::~GamepadBehavior(void)
{
}

BehaviorBase* GamepadBehavior::clone()
{
	return new GamepadBehavior();
}


CustomPoint* GamepadBehavior::getTouch()
{
	if(Config::engine->isLeftMouseButtonPressed())
		return getOverPoint();

	return nullptr;
}

CustomPoint* GamepadBehavior::getOverPoint()
{
	CustomPoint& pos = Config::engine->getMousePosition();
	touch.x = pos.x;
	touch.y = pos.y;
	return &touch;	
}


