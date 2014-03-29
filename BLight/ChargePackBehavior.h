#pragma once
#include "BehaviorBase.h"
#include "PopupManager.h"
#include "Config.h"

class ChargePackBehavior : public BehaviorBase
{
public:
	ChargePackBehavior(void);
	ChargePackBehavior(int);

	~ChargePackBehavior(void);
	
	BehaviorBase* clone();

	bool start(ControllerBase*);
	bool stop();

	bool onBeginInteraction(ObjectBase*);
	
	BehaviorType getType(){return CHARGE_PACK_BEHAVIOR;}

protected:
	bool doStep(int);
	void showPopup(ControllerBase*);

	ObjectBase* target;

	int drop;	
};

