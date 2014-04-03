#pragma once
#include "BehaviorBase.h"

template<typename T> BehaviorBase* createInstance() { return new T; }

class BehaviorsFactory
{
public:
	static BehaviorBase* create(string);
	static BehaviorType getType(string);

private:
	static void init();
	
	static map <string,  BehaviorBase*(*)()> nameToInstance;
	static map <string,  BehaviorType> nameToType;
	
	static bool inited;
};

