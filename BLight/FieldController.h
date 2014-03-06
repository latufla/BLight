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

	ControllerBase* createObjectController(int, string, int, const CustomPoint&);

	vector<ControllerBase*>& getControllers(){ return controllers; }
	Field& getField() { return field; }

protected:
	FieldController() {};               
	FieldController(FieldController const&);              
	void operator=(FieldController const&);

	Field field;
	vector<ControllerBase*> controllers;
};

