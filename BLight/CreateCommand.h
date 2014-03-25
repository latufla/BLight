#pragma once
#include "BehaviorBase.h"
#include "ObjectInfo.h"
#include "Config.h"

class CreateCommand
{
public:
	CreateCommand(void);
	~CreateCommand(void);

	bool tryToExecute();
	bool canExecute();
	void execute();

	void setUp(BehaviorBase*, ObjectInfo*);

protected:
	BehaviorBase* caller;
	ObjectInfo* creature;

	static int id;
};

