#pragma once
#include "BehaviorBase.h"
#include "Command.h"
#include "DropInfo.h"

class ChargeCommand : public Command
{
public:
	ChargeCommand(void);
	~ChargeCommand(void);

	bool canExecute();
	void execute();

	void setUp(BehaviorBase*, ObjectBase*);
	
	CommandType getType(){return CHARGE_COMMAND;}

protected:
	bool canShowPopUp();
};

