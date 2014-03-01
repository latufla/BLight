#pragma once
#include "stdafx.h"
#include "ObjectBase.h"
#include "ControllerBase.h"

enum BehaviorType{INVALID, GAMEPAD, USER_CONTROL, MOVE};

class BehaviorBase
{
public:
	 BehaviorBase(void);
	 BehaviorBase( int, string );
	~BehaviorBase(void);

	virtual bool start(ControllerBase*);
	virtual bool stop();
	virtual bool doStep(int); // frame behavior

	// event behavior	
	virtual bool onBeginInteraction(ObjectBase*){return false;}; 
	virtual bool onEndInteraction(ObjectBase*){return false;};

	virtual bool operator == (BehaviorBase);
	virtual operator string();

	virtual ControllerBase* getController();

	virtual bool getEnabled();

	virtual int getId();
	virtual void setId(int);

	virtual string getName();
	virtual void setName(string);
	
	virtual BehaviorType getType(){return INVALID;};

protected:
	virtual void init(int, string);
	
	int id;
	string name;
	ControllerBase* controller; // get`s no ownership
	bool enabled;
};

