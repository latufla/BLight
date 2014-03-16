#include "AIBlackboard.h"


AIBlackboard::AIBlackboard(void)
{
	moveTo = nullptr;
	moveForce = 10.0f;

	target = nullptr;
	action = NONE_ACTION;
}


AIBlackboard::~AIBlackboard(void)
{
	delete moveTo;
}
