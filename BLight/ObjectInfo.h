#pragma once
#include "stdafx.h"
#include "CustomShape.h"
#include "BehaviorBase.h"
#include "AINode.h"

class ObjectInfo
{
public:
	ObjectInfo(void);
	~ObjectInfo(void);
	
	string name;
	int physicType;
	CustomShape* shape;
	float density;
	float friction;
	float restitution;
	float linearDamping;
	
	vector<BehaviorBase*> behaviors;
	AINode ai;
};

