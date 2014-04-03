#include "BehaviorsFactory.h"
#include "UserControlBehavior.h"
#include "MoveBehavior.h"
#include "AttackBehavior.h"
#include "AIControlBehavior.h"
#include "ChargePackBehavior.h"
#include "ChargerBehavior.h"
#include "DeathBehavior.h"
#include "SpawnerBehavior.h"

bool BehaviorsFactory::mapped = false;
map <string, BehaviorBase*(*)()> BehaviorsFactory::nameToBehavior;

BehaviorBase* BehaviorsFactory::create(string name)
{
	if(!mapped)
		initMap();

	return nameToBehavior[name]();
}

void BehaviorsFactory::initMap()
{
	nameToBehavior["UserControlBehavior"] = &createInstance<UserControlBehavior>;
	nameToBehavior["AIControlBehavior"] = &createInstance<AIControlBehavior>;
	
	nameToBehavior["AttackBehavior"] = &createInstance<AttackBehavior>;
	nameToBehavior["ChargePackBehavior"] = &createInstance<ChargePackBehavior>;
	nameToBehavior["ChargerBehavior"] = &createInstance<ChargerBehavior>;
	nameToBehavior["DeathBehavior"] = &createInstance<DeathBehavior>;
	nameToBehavior["MoveBehavior"] = &createInstance<MoveBehavior>;
	nameToBehavior["SpawnerBehavior"] = &createInstance<SpawnerBehavior>;

	mapped = true;
}

