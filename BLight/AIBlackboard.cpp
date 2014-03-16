#include "AIBlackboard.h"


AIBlackboard::AIBlackboard(void)
{
	moveForce = 0.0f;
	target = nullptr;
	action = NONE_ACTION;
}


AIBlackboard::~AIBlackboard(void)
{
	delete moveTo;
}
