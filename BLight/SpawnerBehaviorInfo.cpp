#include "SpawnerBehaviorInfo.h"

SpawnerBehaviorInfo::SpawnerBehaviorInfo(void) : Info()
{
	intervalMSec = 0;
	chance = 0;
	creature = "";
	spawnX = spawnY = 0.0f;
}

SpawnerBehaviorInfo::~SpawnerBehaviorInfo(void)
{
}
