#pragma once
#include "ObjectBase.h"
#include "Command.h"

class ApplyCommand : public Command
{
public:
	ApplyCommand(void);
	~ApplyCommand(void);

	bool canExecute();
	void execute();

	void setUp(BehaviorBase*, ObjectBase*, int*, int);

protected:
	ObjectBase* target;
	int* prop;
	int applyValue;
};

