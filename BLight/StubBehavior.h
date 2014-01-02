#pragma once
#include "BehaviorBase.h"

class StubBehavior : public BehaviorBase
{
public:
	StubBehavior(void);
	StubBehavior(int, string);
	~StubBehavior(void);

	bool doStep(int);
	
	static string GetFullClassName() {return "StubBehavior";} // TODO: fix this dirt 
	string getClassName(){return StubBehavior::GetFullClassName();}

};

