#pragma once
#include "ObjectBase.h"
#include "BehaviorBase.h"
#include "PhEngineConnector.h"

class SimpleDropBehavior : public BehaviorBase
{
public:
	SimpleDropBehavior(void);
	SimpleDropBehavior(int);

	~SimpleDropBehavior(void);

	bool start(ControllerBase*);
	bool stop();

	bool onBeginInteraction(ObjectBase*);

protected:
	bool doStep(int);

	int drop;
	bool processed;
};

