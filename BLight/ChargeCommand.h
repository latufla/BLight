#pragma once
#include "BehaviorBase.h"
#include "Command.h"

class ChargeCommand : public Command
{
public:
	ChargeCommand(void);
	~ChargeCommand(void);

	bool canExecute();
	void execute();

	void setUp(BehaviorBase*, ObjectBase*, int);

	CommandType getType(){return CHARGE_COMMAND;}

protected:
	int charge;
};

