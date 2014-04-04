#include "BehaviorsFactory.h"
#include "UserControlBehavior.h"
#include "MoveBehavior.h"
#include "AttackBehavior.h"
#include "AIControlBehavior.h"
#include "ChargePackBehavior.h"
#include "ChargerBehavior.h"
#include "DeathBehavior.h"
#include "SpawnerBehavior.h"
#include "SpawnerBehaviorInfo.h"

bool BehaviorsFactory::inited = false;

map <string,  Info*(*)()> BehaviorsFactory::nameToInfo;
map <string, BehaviorBase*(*)()> BehaviorsFactory::nameToInstance;
map <string,  BehaviorType> BehaviorsFactory::nameToType;

Info* BehaviorsFactory::createInfo(string name)
{
	if(!inited)
		init();

	Info* bInfo = nameToInfo[name]();
	bInfo->name = name;
	return bInfo;
}

BehaviorBase* BehaviorsFactory::create(Info* info)
{
	if(!inited)
		init();

	return nameToInstance[info->name]();
}

BehaviorType BehaviorsFactory::getType(string name)
{
	if(!inited)
		init();

	return nameToType[name];
}

void BehaviorsFactory::init()
{
	nameToInfo["UserControlBehavior"] = &createInstance<Info, Info>;
	nameToInstance["UserControlBehavior"] = &createInstance<UserControlBehavior, BehaviorBase>;
	nameToType["UserControlBehavior"] = CONTROL_BEHAVIOR;

	nameToInfo["AIControlBehavior"] = &createInstance<Info, Info>;
	nameToInstance["AIControlBehavior"] = &createInstance<AIControlBehavior, BehaviorBase>;
	nameToType["AIControlBehavior"] = CONTROL_BEHAVIOR;

	nameToInfo["AttackBehavior"] = &createInstance<Info, Info>;
	nameToInstance["AttackBehavior"] = &createInstance<AttackBehavior, BehaviorBase>;
	nameToType["AttackBehavior"] = ATTACK_BEHAVIOR;
	
	nameToInfo["ChargePackBehavior"] = &createInstance<Info, Info>;
	nameToInstance["ChargePackBehavior"] = &createInstance<ChargePackBehavior, BehaviorBase>;
	nameToType["ChargePackBehavior"] = CHARGE_PACK_BEHAVIOR;

	nameToInfo["ChargerBehavior"] = &createInstance<Info, Info>;
	nameToInstance["ChargerBehavior"] = &createInstance<ChargerBehavior, BehaviorBase>;
	nameToType["ChargerBehavior"] = CHARGER_BEHAVIOR;

	nameToInfo["DeathBehavior"] = &createInstance<Info, Info>;
	nameToInstance["DeathBehavior"] = &createInstance<DeathBehavior, BehaviorBase>;
	nameToType["DeathBehavior"] = DEATH_BEHAVIOR;

	nameToInfo["MoveBehavior"] = &createInstance<Info, Info>;
	nameToInstance["MoveBehavior"] = &createInstance<MoveBehavior, BehaviorBase>;
	nameToType["MoveBehavior"] = MOVE_BEHAVIOR;

	nameToInfo["SpawnerBehavior"] = &createInstance<SpawnerBehaviorInfo, Info>;
	nameToInstance["SpawnerBehavior"] = &createInstance<SpawnerBehavior, BehaviorBase>;
	nameToType["SpawnerBehavior"] = SPAWNER_BEHAVIOR;

	inited = true;
}

