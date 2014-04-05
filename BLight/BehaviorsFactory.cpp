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

const string BehaviorsFactory::USER_CONTROL_BEHAVIOR = "UserControlBehavior";
const string BehaviorsFactory::AI_CONTROL_BEHAVIOR = "AIControlBehavior";
const string BehaviorsFactory::ATTACK_BEHAVIOR = "AttackBehavior";
const string BehaviorsFactory::CHARGE_PACK_BEHAVIOR = "ChargePackBehavior";
const string BehaviorsFactory::CHARGER_BEHAVIOR = "ChargerBehavior";
const string BehaviorsFactory::DEATH_BEHAVIOR = "DeathBehavior";
const string BehaviorsFactory::MOVE_BEHAVIOR = "MoveBehavior";
const string BehaviorsFactory::SPAWNER_BEHAVIOR = "SpawnerBehavior";

bool BehaviorsFactory::inited = false;

map <string,  Info*(*)()> BehaviorsFactory::nameToInfo;
map <string, BehaviorBase*(*)(Info*)> BehaviorsFactory::nameToInstance;

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

	return nameToInstance[info->name](info);
}

void BehaviorsFactory::init()
{
	nameToInfo[USER_CONTROL_BEHAVIOR] = &createInstance<Info, Info>;
	nameToInstance[USER_CONTROL_BEHAVIOR] = &createInstance<UserControlBehavior, BehaviorBase>;

	nameToInfo[AI_CONTROL_BEHAVIOR] = &createInstance<Info, Info>;
	nameToInstance[AI_CONTROL_BEHAVIOR] = &createInstance<AIControlBehavior, BehaviorBase>;

	nameToInfo[ATTACK_BEHAVIOR] = &createInstance<Info, Info>;
	nameToInstance[ATTACK_BEHAVIOR] = &createInstance<AttackBehavior, BehaviorBase>;
	
	nameToInfo[CHARGE_PACK_BEHAVIOR] = &createInstance<Info, Info>;
	nameToInstance[CHARGE_PACK_BEHAVIOR] = &createInstance<ChargePackBehavior, BehaviorBase>;

	nameToInfo[CHARGER_BEHAVIOR] = &createInstance<Info, Info>;
	nameToInstance[CHARGER_BEHAVIOR] = &createInstance<ChargerBehavior, BehaviorBase>;

	nameToInfo[DEATH_BEHAVIOR] = &createInstance<Info, Info>;
	nameToInstance[DEATH_BEHAVIOR] = &createInstance<DeathBehavior, BehaviorBase>;

	nameToInfo[MOVE_BEHAVIOR] = &createInstance<Info, Info>;
	nameToInstance[MOVE_BEHAVIOR] = &createInstance<MoveBehavior, BehaviorBase>;

	nameToInfo[SPAWNER_BEHAVIOR] = &createInstance<SpawnerBehaviorInfo, Info>;
	nameToInstance[SPAWNER_BEHAVIOR] = &createInstance<SpawnerBehavior, BehaviorBase>;

	inited = true;
}
