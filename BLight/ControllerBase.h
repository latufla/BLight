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
	
	virtual bool startBehaviors();
	virtual bool stopBehaviors();
	virtual bool doBehaviorsStep(int);

	operator string();

	int getId();
	void setId(int);

	string getName();
	void setName(string);

	ObjectBase* getObject();
	ViewBase* getView() const { return view; }
	
protected:
	void init(int, string);

	int id;
	string name;
	ObjectBase* object; // gets ownership
	ViewBase* view; // gets ownership
	
	vector<BehaviorBase*> *behaviors; // gets ownership
};

