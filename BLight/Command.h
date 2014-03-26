#pragma once
#include "BehaviorBase.h"
class Command
{
public:
	Command(void);
	~Command(void);

	virtual bool tryToExecute();
	virtual bool canExecute();
	virtual void execute();

protected:
	BehaviorBase* caller;
};

