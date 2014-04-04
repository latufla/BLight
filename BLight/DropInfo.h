#pragma once
#include "stdafx.h"
#include <map>
#include "Info.h"

class DropInfo : public Info
{
public:
	static string const ENERGY;
	static string const XP;

	DropInfo(void);
	~DropInfo(void);
	
	map<string, int> caller;
	map<string, int> target;
};

