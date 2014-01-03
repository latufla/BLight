#pragma once
#include "stdafx.h"
#include "EventDispatcher.h"

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

protected:
	void init(int, string);

	string name;
};

