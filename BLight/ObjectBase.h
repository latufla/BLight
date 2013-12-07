#pragma once
#include "stdafx.h"
#include <ClanLib/core.h>

using namespace std;

class ObjectBase
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

	clan::Signal_v1<ObjectBase*> updateSignal;

protected:
	void init(int, string);

	int id;
	string name;
};

