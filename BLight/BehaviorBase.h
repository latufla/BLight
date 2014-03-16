#pragma once
#include "stdafx.h"
#include "ObjectBase.h"
#include "ControllerBase.h"

enum BehaviorType{NONE_BEHAVIOR, GAMEPAD_BEHAVIOR, CONTROL_BEHAVIOR, MOVE_BEHAVIOR, CHARGER_BEHAVIOR, SIMPLE_DROP_BEHAVIOR};

class BehaviorBase
{
public:
	 BehaviorBase(void);
	 BehaviorBase(int, string);
	virtual ~BehaviorBase(void);

	static int count;

	virtual bool start(ControllerBase*);
	virtual bool stop();
	virtual bool tryDoStep(int); // frame behavior

	// event behavior	
	virtual bool onBeginInteraction(ObjectBase*){return false;}; 
	virtual bool onEndInteraction(ObjectBase*){return false;};

	virtual operator string();

	virtual ControllerBase* getController(){return controller;}

	virtual bool getEnabled(){return enabled;}

	virtual int getId(){return id;}
	virtual void setId(int val){id = val;}

	virtual string getName(){return name;}
	virtual void setName(string val){name = val;}
	
	virtual BehaviorType getType(){return NONE_BEHAVIOR;}
	
protected:
	virtual void init(int, string);
	virtual bool doStep(int);
	virtual bool canDoStep();

	int id;
	string name;
	ControllerBase* controller; // no ownership
	bool enabled;
};

