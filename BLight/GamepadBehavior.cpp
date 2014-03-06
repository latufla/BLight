#include "GamepadBehavior.h"

GamepadBehavior::GamepadBehavior(void)
{
}

GamepadBehavior::~GamepadBehavior(void)
{
}

CustomPoint* GamepadBehavior::getTouch()
{
	EngineConnector& ec = EngineConnector::getInstance();
	if(!ec.isLeftMouseButtonPressed())
		return nullptr;		
	
	CustomPoint& pos = ec.getMousePosition();
	touch.x = pos.x;
	touch.y = pos.y;
	return &touch;
}


