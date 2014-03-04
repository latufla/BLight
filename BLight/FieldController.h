#pragma once
#include "Field.h"
#include "ControllerBase.h"

class FieldController : ControllerBase
{
public:
	FieldController(void);
	~FieldController(void);

	bool startBehaviors();
	bool stopBehaviors();
	bool doBehaviorsStep(int);

	ControllerBase* createObjectController(int, string, int, CustomPoint);

	vector<ControllerBase*>* getControllers() const { return controllers; }
	Field* getField() const { return field; }

protected:
	Field* field;

	vector<ControllerBase*>* controllers;
};

