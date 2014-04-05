#pragma once
#include "BehaviorBase.h"
#include "Info.h"

template<typename T, typename P> P* createInstance() { return new T; }
template<typename T, typename P> P* createInstance(Info* info) { return new T(info); }

class BehaviorsFactory
{
public:
	static const string USER_CONTROL_BEHAVIOR;
	static const string AI_CONTROL_BEHAVIOR;
	static const string ATTACK_BEHAVIOR;
	static const string CHARGE_PACK_BEHAVIOR;
	static const string CHARGER_BEHAVIOR;
	static const string DEATH_BEHAVIOR;
	static const string MOVE_BEHAVIOR;
	static const string SPAWNER_BEHAVIOR;

	static BehaviorBase* create(Info*);
	static Info* createInfo(string);

private:
	static void init();

	static map <string,  Info*(*)()> nameToInfo;
	static map <string,  BehaviorBase*(*)(Info*)> nameToInstance;

	static bool inited;
};

