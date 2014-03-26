#pragma once
#include "Command.h"

class DestroyCommand : public Command
{
public:
	DestroyCommand(void);
	~DestroyCommand(void);

	bool canExecute();
	void execute();

	void setUp(BehaviorBase*, ControllerBase*);

protected:
	ControllerBase* target;
};

