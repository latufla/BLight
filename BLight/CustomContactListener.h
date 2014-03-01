#pragma once
#include "stdafx.h"
#include "Box2D\Dynamics\b2WorldCallbacks.h"
#include "BehaviorBase.h"

class PhEngineConnector;

class CustomContactListener : public b2ContactListener
{
public:
	CustomContactListener(void);
	~CustomContactListener(void);
	
	void BeginContact(b2Contact*);
	void EndContact(b2Contact*);

protected:
	map<BehaviorBase*, ObjectBase*>* filter(b2Contact*);
};

