#pragma once
#include "ObjectBase.h"
class ApplyCommand
{
public:
	ApplyCommand(void);
	~ApplyCommand(void);

	bool tryToExecute();
	bool canExecute();
	void execute();

	void setUp(ObjectBase*, int*, int);

protected:
	ObjectBase* target;
	int* prop;
	int applyValue;
};

