#pragma once
#include "stdafx.h"
#include "ObjectBase.h"
#include "ControllerBase.h"

class BehaviorBase
{
public:
	 BehaviorBase(void);
	 BehaviorBase( int, string );
	~BehaviorBase(void);

	virtual bool start(ControllerBase*);
	virtual bool stop();
	virtual bool doStep(int); // frame behavior
	virtual bool onInteraction(ObjectBase*, ObjectBase*); // event behavior	

	virtual bool operator == (BehaviorBase);
	virtual operator string();

	virtual ControllerBase* getController();

	virtual bool getEnabled();

	virtual int getId();
	virtual void setId(int);

	virtual string getName();
	virtual void setName(string);

	static string GetClassName() {return "BehaviorBase";} // TODO: fix this dirt 
	virtual string getClassName(){return BehaviorBase::GetClassName();}

protected:
	virtual void init(int, string);
	
	int id;
	string name;
	ControllerBase* controller; // get`s no ownership
	bool enabled;
};

