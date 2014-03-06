#pragma once
#include "stdafx.h"
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
	
	void addBehavior(BehaviorBase*);
	void removeBehavior(BehaviorBase*);
	
	BehaviorBase* getBehaviorBy(BehaviorType);	
	
	virtual bool startBehaviors();
	virtual bool stopBehaviors();
	virtual bool doBehaviorsStep(int);

	operator string();

	int getId(){return id;}
	void setId(int val){id = val;}

	string getName(){return name;}
	void setName(string val){name = val;}

	ObjectBase* getObject(){return object;}
	ViewBase* getView() const {return view;}
	
protected:
	void init(int, string);

	int id;
	string name;

	ObjectBase* object; // gets ownership
	ViewBase* view; // gets ownership
	
	vector<BehaviorBase*> behaviors; // gets ownership
};

