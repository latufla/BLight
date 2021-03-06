#pragma once
#include "BehaviorBase.h"

class DebuggerBehavior : public BehaviorBase
{
public:
	DebuggerBehavior(void);
	~DebuggerBehavior(void);

protected:
	bool doStep(int);	
	bool canDoStep();
	
	static const int DEBUG_STEP;
	int debugStep;
};

