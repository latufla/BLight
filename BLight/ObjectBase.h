#pragma once
#include "stdafx.h"

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

protected:
	void init(int, string);

	int id;
	string name;
};

