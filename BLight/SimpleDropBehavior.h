#pragma once
#include "ObjectBase.h"
#include "BehaviorBase.h"
#include "PhEngineConnector.h"
#include "ApplyCommand.h"

class SimpleDropBehavior : public BehaviorBase
{
public:
	SimpleDropBehavior(void);
	SimpleDropBehavior(int);

	~SimpleDropBehavior(void);

	bool start(ControllerBase*);
	bool stop();

	bool onBeginInteraction(ObjectBase*);

	BehaviorType getType() const {return SIMPLE_DROP_BEHAVIOR;}

protected:
	bool doStep(int);

	int drop;
	bool processed;
	
	ApplyCommand command;
};

