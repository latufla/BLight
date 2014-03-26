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

	void setUp(BehaviorBase*, ObjectInfo*);

protected:
	ObjectInfo* creature;

	static int id; // TODO: fix this dirt
};

