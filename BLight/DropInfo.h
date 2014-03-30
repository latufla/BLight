#pragma once
#include "stdafx.h"
#include <map>

class DropInfo
{
public:
	static string const ENERGY;
	static string const XP;

	DropInfo(void);
	~DropInfo(void);
	
	map<string, int> caller;
	map<string, int> target;
};

