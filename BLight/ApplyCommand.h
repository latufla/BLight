#pragma once
#include "ObjectBase.h"
#include "BehaviorBase.h"
class ApplyCommand
{
public:
	ApplyCommand(void);
	~ApplyCommand(void);

	bool tryToExecute();
	bool canExecute();
	void execute();

	void setUp(BehaviorBase*, ObjectBase*, int*, int);

protected:
	BehaviorBase* caller;
	ObjectBase* target;
	int* prop;
	int applyValue;
};

