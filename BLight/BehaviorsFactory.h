#pragma once
#include "BehaviorBase.h"

template<typename T> BehaviorBase* createInstance() { return new T; }

class BehaviorsFactory
{
public:
	static BehaviorBase* create(string);

private:
	static void initMap();
	
	static map <string,  BehaviorBase*(*)()> nameToBehavior;
	static bool mapped;
};

