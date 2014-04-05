#pragma once
#include "BehaviorBase.h"
#include "Info.h"

template<typename T, typename P> P* createInstance() { return new T; }
template<typename T, typename P> P* createInstance(Info* info) { return new T(info); }

class BehaviorsFactory
{
public:
	static BehaviorBase* create(Info*);
	static Info* createInfo(string);

	static BehaviorType getType(string);

private:
	static void init();
	
	static map <string,  BehaviorBase*(*)(Info*)> nameToInstance;
	static map <string,  BehaviorType> nameToType;
	static map <string,  Info*(*)()> nameToInfo;

	static bool inited;
};

