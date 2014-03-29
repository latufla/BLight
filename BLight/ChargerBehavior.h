#pragma once
#include "BehaviorBase.h"
#include "ChargeCommand.h"

// charges main hero energy
class ChargerBehavior : public BehaviorBase
{
public:
	ChargerBehavior(void);
	~ChargerBehavior(void);

	BehaviorBase* clone();

	bool start(ControllerBase*);
	bool stop();
	bool onBeginInteraction(ObjectBase*);
	bool onEndInteraction(ObjectBase*);
	
	BehaviorType getType(){return CHARGER_BEHAVIOR;}
	
protected:
	bool doStep(int);

	ObjectBase* target;

	ChargeCommand command;
};

