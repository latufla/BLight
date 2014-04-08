#pragma once
#include "BehaviorBase.h"
#include "ObjectInfo.h"
#include "Config.h"
#include "Command.h"

class CreateCommand : public Command
{
public:
	CreateCommand(void);
	~CreateCommand(void);

	bool canExecute();
	void execute();

	void setUp(BehaviorBase*, ObjectInfo*, const CustomPoint&);
	ControllerBase* getCreature() const { return creature; }

	CommandType getType(){return CREATE_COMMAND;}

protected:
	ObjectInfo* info;
	ControllerBase* creature;
	CustomPoint position;
	
	static int id; // TODO: fix this dirt
};

