#include "GamepadBehavior.h"

GamepadBehavior::GamepadBehavior(void)
{
	touch = new CustomPoint();
}


GamepadBehavior::~GamepadBehavior(void)
{
	delete touch;
}

CustomPoint* GamepadBehavior::getTouch()
{
	if(!EngineConnector::isLeftMouseButtonPressed())
		return nullptr;		
	
	CustomPoint pos = EngineConnector::getMousePosition();
	touch->x = pos.x;
	touch->y = pos.y;
	return touch;
}


