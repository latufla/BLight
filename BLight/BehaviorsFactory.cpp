#include "BehaviorsFactory.h"
#include "UserControlBehavior.h"
#include "MoveBehavior.h"
#include "AttackBehavior.h"
#include "AIControlBehavior.h"
#include "ChargePackBehavior.h"
#include "ChargerBehavior.h"
#include "DeathBehavior.h"
#include "SpawnerBehavior.h"

bool BehaviorsFactory::inited = false;

map <string, BehaviorBase*(*)()> BehaviorsFactory::nameToInstance;
map <string,  BehaviorType> BehaviorsFactory::nameToType;

BehaviorBase* BehaviorsFactory::create(string name)
{
	if(!inited)
		init();

	return nameToInstance[name]();
}

BehaviorType BehaviorsFactory::getType(string name)
{
	if(!inited)
		init();

	return nameToType[name];
}

void BehaviorsFactory::init()
{
	nameToInstance["UserControlBehavior"] = &createInstance<UserControlBehavior>;
	nameToType["UserControlBehavior"] = CONTROL_BEHAVIOR;

	nameToInstance["AIControlBehavior"] = &createInstance<AIControlBehavior>;
	nameToType["AIControlBehavior"] = CONTROL_BEHAVIOR;

	nameToInstance["AttackBehavior"] = &createInstance<AttackBehavior>;
	nameToType["AttackBehavior"] = ATTACK_BEHAVIOR;
	
	nameToInstance["ChargePackBehavior"] = &createInstance<ChargePackBehavior>;
	nameToType["ChargePackBehavior"] = CHARGE_PACK_BEHAVIOR;

	nameToInstance["ChargerBehavior"] = &createInstance<ChargerBehavior>;
	nameToType["ChargerBehavior"] = CHARGER_BEHAVIOR;

	nameToInstance["DeathBehavior"] = &createInstance<DeathBehavior>;
	nameToType["DeathBehavior"] = DEATH_BEHAVIOR;

	nameToInstance["MoveBehavior"] = &createInstance<MoveBehavior>;
	nameToType["MoveBehavior"] = MOVE_BEHAVIOR;

	nameToInstance["SpawnerBehavior"] = &createInstance<SpawnerBehavior>;
	nameToType["SpawnerBehavior"] = SPAWNER_BEHAVIOR;

	inited = true;
}


