#pragma once
#include "stdafx.h"
#include "EventDispatcher.h"
#include <utility>
#include <map>

using namespace std;

class ObjectBase : public EventDispatcher
{
public:
	ObjectBase(void);
	ObjectBase(int, string);

	~ObjectBase(void);

	operator string();
	bool operator == (ObjectBase);
	
	int getId();
	void setId(int);

	string getName();
	void setName(string);

	bool fireUpdates();

	// Ph
	// initial
	void setBoxShape(float, float);	
	void setDensity(float);
	void setFriction(float);
	void setRestitution(float);
	// end initial
	// end Ph

protected:
	void init(int, string);

	string name;

};

