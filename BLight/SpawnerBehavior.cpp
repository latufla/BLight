#include "SpawnerBehavior.h"
#include "StatusViewManager.h"
#include "SpawnerBehaviorInfo.h"
#include "Infos.h"

SpawnerBehavior::SpawnerBehavior(void)
{
	this->intervalMSec = 5000;
	this->chance = 1000;
	this->creature = Infos::getInfoBy("enemy"); 

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
