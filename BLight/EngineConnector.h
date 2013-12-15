#pragma once
#include "stdafx.h"

class EngineConnector
{
public:
	EngineConnector(void);

	typedef int (MainFunction)(const vector<string>&);
	EngineConnector(MainFunction*);
 			
	~EngineConnector(void);

	void start(void(*)(int));

	static void printDebug(string);

protected:
	void init(int (*)(const vector<string>&));
};

