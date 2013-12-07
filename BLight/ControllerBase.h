#pragma once
#include "stdafx.h"
#include "ObjectBase.h"

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

protected:
	void init(int, string);

private:
	int id;
	string name;
	ObjectBase* object; 
	vector<BehaviorBase*> *behaviors; // gets ownership
};

