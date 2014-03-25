#include "Infos.h"
#include "UserControlBehavior.h"
#include "MoveBehavior.h"
#include "AIControlBehavior.h"
#include "SimpleDropBehavior.h"
#include "ChargerBehavior.h"
#include "SpawnerBehavior.h"

ObjectInfo* Infos::getHeroInfo()
{
	static ObjectInfo* info = new ObjectInfo();
	info->name = "hero";
	info->physicType = 2;
	info->shape = new CustomCircle(CustomPoint(0.0f, 0.0f), 1.0f);
	info->density = 1.0f;
	info->friction = 0.3f;
	info->restitution = .5f;
	info->linearDamping = 1.0f;

	info->behaviors.push_back(new UserControlBehavior());
	info->behaviors.push_back(new MoveBehavior());
	return info;
}

ObjectInfo* Infos::getEnemyInfo()
{
	static ObjectInfo* info = new ObjectInfo();
	info->name = "aiDummy";
	info->physicType = 2;
	info->shape = new CustomCircle(CustomPoint(0.0f, 0.0f), 1.0f);
	info->density = 1.0f;
	info->friction = 0.3f;
	info->restitution = .5f;
	info->linearDamping = 1.0f;

	info->behaviors.push_back(new AIControlBehavior());
	info->behaviors.push_back(new MoveBehavior());
	return info;
}

ObjectInfo* Infos::getSmallEnergyPackInfo()
{
	static ObjectInfo* info = new ObjectInfo();
	info->name = "pack +20";
	info->physicType = 0;
	info->shape = new CustomPolygon(1.0f, 1.0f); 

	info->behaviors.push_back(new SimpleDropBehavior(20));
	info->behaviors.push_back(new SimpleDropBehavior(40));
	return info;
}

ObjectInfo* Infos::getMediumEnergyPackInfo()
{
	static ObjectInfo* info = new ObjectInfo();
	info = new ObjectInfo();
	info->name = "pack +30";
	info->physicType = 0;
	info->shape = new CustomPolygon(2.0f, 2.0f); 

	info->behaviors.push_back(new SimpleDropBehavior(30));
	return info;
}

ObjectInfo* Infos::getChargerInfo()
{
	static ObjectInfo* info = new ObjectInfo();
	info->name = "charger";
	info->physicType = 0;
	info->shape = new CustomPolygon(4.0f, 4.0f); 

	info->behaviors.push_back(new ChargerBehavior());
	return info;
}

ObjectInfo* Infos::getEnemySpawnerInfo()
{
	ObjectInfo* eInfo = getEnemyInfo(); 
	static ObjectInfo* info = new ObjectInfo();
	info->name = "spawner";
	info->physicType = 0;
	info->shape = new CustomPolygon(3.0f, 3.0f); 

	info->behaviors.push_back(new SpawnerBehavior(eInfo));
	return info;
}
