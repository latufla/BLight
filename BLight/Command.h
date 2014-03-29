#pragma once
#include "BehaviorBase.h"

enum CommandType{
	NONE_COMMAND, 
	CREATE_COMMAND, 
	DESTROY_COMMAND, 
	APPLY_COMMAND, 
	ATTACK_COMMAND, 
	CHARGE_COMMAND
};

class Command
{
public:
	Command(void);
	~Command(void);

	virtual bool tryToExecute();
	virtual bool canExecute();
	virtual void execute();
	
	virtual CommandType getType(){return NONE_COMMAND;}

protected:
	BehaviorBase* caller;
	ObjectBase* target;
};

