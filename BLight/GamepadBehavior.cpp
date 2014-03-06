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
	EngineConnector& ec = EngineConnector::getInstance();
	if(!ec.isLeftMouseButtonPressed())
		return nullptr;		
	
	CustomPoint pos = ec.getMousePosition();
	touch->x = pos.x;
	touch->y = pos.y;
	return touch;
}


