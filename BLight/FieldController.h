#pragma once
#include "Field.h"
#include "ControllerBase.h"

class FieldController : ControllerBase
{
public:
	static FieldController& getInstance() {
		static FieldController instance;
		return instance;
	}

	void init();

	bool startBehaviors();
	bool stopBehaviors();
	bool doBehaviorsStep(int);

	ControllerBase* createObjectController(int, string, int, CustomPoint);

	vector<ControllerBase*>* getControllers() const { return controllers; }
	Field* getField() const { return field; }

protected:
	FieldController() {};               
	FieldController(FieldController const&);              
	void operator=(FieldController const&);

	Field* field;
	vector<ControllerBase*>* controllers;
};

