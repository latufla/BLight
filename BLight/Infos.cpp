#include "Infos.h"
#include "UserControlBehavior.h"
#include "MoveBehavior.h"
#include "AIControlBehavior.h"
#include "ChargePackBehavior.h"
#include "ChargerBehavior.h"
#include "SpawnerBehavior.h"
#include "AttackBehavior.h"

const string Infos::HERO_NAME = "hero";
const string Infos::ENEMY_NAME = "enemy";
const string Infos::SMALL_ENERGY_PACK_NAME = "small_energy_pack";
const string Infos::MEDIUM_ENERGY_PACK_NAME = "medium_energy_pack";
const string Infos::CHARGER_NAME = "charger";
const string Infos::ENEMY_SPAWNER_NAME = "enemy_spawner";

map<int, ObjectInfo*> Infos::idToInfo;
map<string, ObjectInfo*> Infos::nameToInfo;

void Infos::init()
{
	getHeroInfo();
	getEnemySpawnerInfo();
	getChargerInfo();
	getSmallEnergyPackInfo();
	getMediumEnergyPackInfo();
}

ObjectInfo* Infos::getInfoBy(int id)
{
	return idToInfo[id];
}

ObjectInfo* Infos::getInfoBy(string name)
{
	return nameToInfo[name];
}

// TODO: cleanup
ObjectInfo* Infos::getHeroInfo()
{
	ObjectInfo* info = new ObjectInfo();
	info->id = HERO;
	info->name = HERO_NAME;

	idToInfo[info->id] = info;
	nameToInfo[info->name] = info;

	info->physicType = 2;
	info->shape = new CustomCircle(CustomPoint(0.0f, 0.0f), 1.0f);
	info->density = 1.0f;
	info->friction = 0.3f;
	info->restitution = .5f;
	info->linearDamping = 1.0f;

	info->behaviors.push_back(new UserControlBehavior());
	info->behaviors.push_back(new MoveBehavior());
	info->behaviors.push_back(new AttackBehavior());
	
	info->applicableCommands.push_back(CHARGE_COMMAND);

	return info;
}

ObjectInfo* Infos::getEnemyInfo()
{
	ObjectInfo* info = new ObjectInfo();
	info->id = ENEMY;
	info->name = ENEMY_NAME;

	idToInfo[info->id] = info;
	nameToInfo[info->name] = info;

	info->physicType = 2;
	info->shape = new CustomCircle(CustomPoint(0.0f, 0.0f), 1.0f);
	info->density = 1.0f;
	info->friction = 0.3f;
	info->restitution = .5f;
	info->linearDamping = 1.0f;

	info->behaviors.push_back(new AIControlBehavior());
	info->behaviors.push_back(new MoveBehavior());
	
	info->applicableCommands.push_back(ATTACK_COMMAND);
	info->applicableCommands.push_back(CHARGE_COMMAND);

	return info;
}

ObjectInfo* Infos::getSmallEnergyPackInfo()
{
	ObjectInfo* info = new ObjectInfo();
	info->id = SMALL_ENERGY_PACK;	
	info->name = SMALL_ENERGY_PACK_NAME;

	idToInfo[info->id] = info;
	nameToInfo[info->name] = info;

	info->physicType = 0;
	info->shape = new CustomPolygon(1.0f, 1.0f); 

	info->behaviors.push_back(new ChargePackBehavior(20));
	info->behaviors.push_back(new ChargePackBehavior(40));

	return info;
}

ObjectInfo* Infos::getMediumEnergyPackInfo()
{
	ObjectInfo* info = new ObjectInfo();
	info = new ObjectInfo();
	info->id = MEDIUM_ENERGY_PACK;
	info->name = MEDIUM_ENERGY_PACK_NAME;
	
	idToInfo[info->id] = info;
	nameToInfo[info->name] = info;

	info->physicType = 0;
	info->shape = new CustomPolygon(2.0f, 2.0f); 

	info->behaviors.push_back(new ChargePackBehavior(30));
	
	return info;
}

ObjectInfo* Infos::getChargerInfo()
{
	static ObjectInfo* info = new ObjectInfo();
	info->id = CHARGER;
	info->name = CHARGER_NAME;

	idToInfo[info->id] = info;
	nameToInfo[info->name] = info;

	info->physicType = 0;
	info->shape = new CustomPolygon(4.0f, 4.0f); 

	info->behaviors.push_back(new ChargerBehavior());
	
	return info;
}

ObjectInfo* Infos::getEnemySpawnerInfo()
{
	ObjectInfo* eInfo = getEnemyInfo(); 
	static ObjectInfo* info = new ObjectInfo();
	info->id = ENEMY_SPAWNER;
	info->name = ENEMY_SPAWNER_NAME;

	idToInfo[info->id] = info;
	nameToInfo[info->name] = info;

	info->physicType = 0;
	info->shape = new CustomPolygon(3.0f, 3.0f); 

	info->behaviors.push_back(new SpawnerBehavior(eInfo));
	return info;
}

