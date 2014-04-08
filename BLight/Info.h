#pragma once
#include "stdafx.h"

class Info
{
public:
	Info(void);
	~Info(void);

	int id;
	string name;

	virtual int& operator[](string){return id;}

	virtual void update(string, int){};
	virtual void update(string, float){};
	virtual void update(string, string){};
};
