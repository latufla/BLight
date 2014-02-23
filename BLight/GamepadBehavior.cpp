#include "GamepadBehavior.h"

GamepadBehavior::GamepadBehavior(void)
{
}


GamepadBehavior::~GamepadBehavior(void)
{
}

bool GamepadBehavior::doStep(int step)
{
	if(!enabled)
		return false;

	__super::doStep(step);

	if(EngineConnector::isLeftMouseButtonPressed())
		EngineConnector::printDebug(EngineConnector::getMousePosition());

	return true;
}


