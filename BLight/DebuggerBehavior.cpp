#include "DebuggerBehavior.h"

const int DebuggerBehavior::DEBUG_STEP = 5;


DebuggerBehavior::DebuggerBehavior(void) : debugStep(DEBUG_STEP)
{
}


DebuggerBehavior::~DebuggerBehavior(void)
{
}

bool DebuggerBehavior::doStep(int step)
{
	__super::doStep(step);
	
	EngineConnector& ec = EngineConnector::getInstance();
	if(ec.isKeyPressed(EngineConnector::F))
		ec.printDebugInstances();
	else if(ec.isKeyPressed(EngineConnector::D))
		ec.printDebugControllers();

	debugStep = 0;

	return true;
}

bool DebuggerBehavior::canDoStep()
{
	return __super::canDoStep() && (debugStep++ >= DEBUG_STEP);
}

BehaviorBase* DebuggerBehavior::clone()
{
	return new DebuggerBehavior();
}
