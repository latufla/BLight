#pragma once
#include "BehaviorBase.h"
#include "DropInfo.h"

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
	virtual bool canShowPopup();
	virtual void showPopup(const map<string, int>&, const CustomPoint&);

	BehaviorBase* caller;
	ObjectBase* target;
};

