#pragma once
#include "stdafx.h"
#include "EventHeap.h"
#include "ObjectBase.h"
#include "ViewBase.h"

class BehaviorBase;
enum BehaviorType;

class ControllerBase
{
public:
	ControllerBase(void);
	ControllerBase(ObjectBase*);
	~ControllerBase(void);
	
	bool addBehavior(BehaviorBase*);
	bool removeBehavior(BehaviorBase*);
	
	BehaviorBase* getBehaviorBy(BehaviorType);	
	
	bool startBehaviors();
	bool stopBehaviors();
	bool doBehaviorsStep(int);

	void draw();

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
};

