#pragma once
#include "BehaviorBase.h"
#include "Command.h"

class AttackCommand : public Command
{
public:
	AttackCommand(void);
	~AttackCommand(void);

	bool canExecute();
	void execute();

	void setUp(BehaviorBase*, ObjectBase*);

	CommandType getType(){return ATTACK_COMMAND;}

protected:
	bool canShowPopup();
};

