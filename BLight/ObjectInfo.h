#pragma once
#include "stdafx.h"
#include "CustomShape.h"
#include "BehaviorBase.h"
#include "Command.h"
#include "DropInfo.h"

class ObjectInfo
{
public:
	ObjectInfo(void);
	~ObjectInfo(void);

	bool canApplyCommand(CommandType);

	int id;
	string name;
	int physicType;
	CustomShape* shape;
	float density;
	float friction;
	float restitution;
	float linearDamping;
	
	vector<BehaviorBase*> behaviors;
	vector<CommandType> applicableCommands;

	map<CommandType, DropInfo*> drop;

};

