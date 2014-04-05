#include "SpawnerBehavior.h"
#include "StatusViewManager.h"
#include "SpawnerBehaviorInfo.h"
#include "Infos.h"

SpawnerBehavior::SpawnerBehavior(void)
{
	this->intervalMSec = 0;
	this->chance = 0;
	this->creature = nullptr;

	time = 0;
}

SpawnerBehavior::SpawnerBehavior(Info* info)
{
	SpawnerBehaviorInfo* sInfo = (SpawnerBehaviorInfo*) info;
	this->intervalMSec = sInfo->intervalMSec;
	this->chance = sInfo->chance;
	this->creature = Infos::getInfoBy(sInfo->creature); 

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
