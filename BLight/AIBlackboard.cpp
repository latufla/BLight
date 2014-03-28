#include "AIBlackboard.h"


AIBlackboard::AIBlackboard(void)
{
	moveTo = nullptr;
	moveForce = 10.0f;

	target = nullptr;
	command = NONE_COMMAND;
}


AIBlackboard::~AIBlackboard(void)
{
	delete moveTo;
}
