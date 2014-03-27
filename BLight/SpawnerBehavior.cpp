#include "SpawnerBehavior.h"
#include "StatusViewManager.h"


SpawnerBehavior::SpawnerBehavior(void)
{
}

SpawnerBehavior::SpawnerBehavior(ObjectInfo* creature, int intervalMSec, int chance)
{
	this->creature = creature;
	this->intervalMSec = intervalMSec;
	this->chance = chance;

	time = 0;
}

SpawnerBehavior::~SpawnerBehavior(void)
{
}

bool SpawnerBehavior::doStep(int step)
{
	__super::doStep(step);

	time += step;
	if(time >= intervalMSec && rand() % 1000 <= chance){
		CreateCommand create;
		create.setUp(this, creature);
		if(create.tryToExecute()){
			StatusViewManager::getInstance().addStatusView(create.getCreature());
			time = 0;
			return true;
		}
	}

	return false;
}

BehaviorBase* SpawnerBehavior::clone()
{
	return new SpawnerBehavior(creature, intervalMSec, chance);
}


