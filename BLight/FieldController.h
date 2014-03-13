#pragma once
#include "Field.h"
#include "ControllerBase.h"

class FieldController : public ControllerBase
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
	void destroyObjectController(ControllerBase*);

	vector<ControllerBase*>& getControllers(){ return controllers; }
	Field& getField() { return field; }

protected:
	FieldController() {};               
	FieldController(FieldController const&);              
	void operator=(FieldController const&);

	void doDestroyStep();

	Field field;
	vector<ControllerBase*> controllers;
};

