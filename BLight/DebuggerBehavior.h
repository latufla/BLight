#pragma once
#include "BehaviorBase.h"
#include "EngineConnector.h"

class DebuggerBehavior : public BehaviorBase
{
public:
	DebuggerBehavior(void);
	~DebuggerBehavior(void);

	BehaviorBase* clone();

protected:
	bool doStep(int);	
	bool canDoStep();
	
	static const int DEBUG_STEP;
	int debugStep;
};

