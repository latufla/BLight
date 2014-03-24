#include "GamepadBehavior.h"

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
	if(EngineConnector::getInstance().isLeftMouseButtonPressed())
		return getOverPoint();

	return nullptr;
}

CustomPoint* GamepadBehavior::getOverPoint()
{
	CustomPoint& pos = EngineConnector::getInstance().getMousePosition();
	touch.x = pos.x;
	touch.y = pos.y;
	return &touch;	
}


