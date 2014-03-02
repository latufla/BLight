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
	bool onBeginInteraction(ObjectBase*);
	bool onEndInteraction(ObjectBase*);

protected:
	bool doStep(int);

	ObjectBase* chargingObject;
	TextBase debugEnergyText;
};

