#pragma once
#include "BehaviorBase.h"
#include "ApplyCommand.h"
#include "PopupManager.h"
#include "Config.h"

class SimpleDropBehavior : public BehaviorBase
{
public:
	SimpleDropBehavior(void);
	SimpleDropBehavior(int);

	~SimpleDropBehavior(void);
	
	BehaviorBase* clone();

	bool start(ControllerBase*);
	bool stop();

	bool onBeginInteraction(ObjectBase*);
	
	BehaviorType getType(){return SIMPLE_DROP_BEHAVIOR;}

protected:
	bool doStep(int);
	void showPopup(ControllerBase*);

	ObjectBase* target;

	int drop;
	ApplyCommand command;
	
};

