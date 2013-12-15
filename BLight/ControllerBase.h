#pragma once
#include "stdafx.h"
#include "ObjectBase.h"
#include "ViewBase.h"

class BehaviorBase;

class ControllerBase
{
public:
	ControllerBase(void);
	ControllerBase(ObjectBase*);
	~ControllerBase(void);
	
	bool addBehavior(BehaviorBase*);
	bool removeBehavior(BehaviorBase*);
	bool startBehaviors();
	bool startBehaviors(string className);	
	bool stopBehaviors();
	bool doBehaviorsStep(int);

	operator string();

	int getId();
	void setId(int);

	string getName();
	void setName(string);

	ObjectBase* getObject();

protected:
	void init(int, string);

	int id;
	string name;
	ObjectBase* object; // gets ownership
	ViewBase* view; // gets ownership

	vector<BehaviorBase*> *behaviors; // gets ownership
	
	clan::Slot updateConnector;
};

