#pragma once
#include "stdafx.h"
#include "CustomShape.h"
#include "BehaviorBase.h"
#include "Command.h"
#include "DropInfo.h"

class ObjectInfo : public Info
{
public:
	ObjectInfo(void);
	~ObjectInfo(void);

	bool canApplyCommand(CommandType, string) const;

	int physicType;
	CustomShape* shape;
	float density;
	float friction;
	float restitution;
	float linearDamping;
	
	vector<Info*> behaviors;
	map<CommandType, vector<string>> applicableCommands;

	map<CommandType, DropInfo*> drop;

	bool displayStatus;
};

