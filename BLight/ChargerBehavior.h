#pragma once
#include "BehaviorBase.h"
#include "EngineConnector.h"
#include "PhEngineConnector.h"

// charges main hero energy
class ChargerBehavior : public BehaviorBase
{
public:
	ChargerBehavior(void);
	~ChargerBehavior(void);

	bool start(ControllerBase*);
	bool stop();
	bool doStep(int);
	bool onBeginInteraction(ObjectBase*, ObjectBase*);
	bool onEndInteraction(ObjectBase*, ObjectBase*);

protected:
	ObjectBase* chargingObject;
};

