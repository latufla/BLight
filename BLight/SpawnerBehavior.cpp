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
	this->creature = Infos::getInstance().getObjectInfoBy(sInfo->creature); 
	this->spawnPosition.set(sInfo->spawnX, sInfo->spawnY);
	
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
		CustomPoint pos = controller->getObject()->getPosition();
		pos.moveBy(spawnPosition);
		create.setUp(this, creature, pos);
		if(create.tryToExecute()){
			time = 0;
			return true;
		}
	}

	return false;
}
