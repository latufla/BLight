#include "Maps.h"
#include "StatusViewManager.h"


vector<ControllerBase*> Maps::createDemoMap(FieldController& field)
{
	vector<ControllerBase*> res;

	Infos::init();

	ObjectInfo* heroInfo = Infos::getInfoBy(Infos::HERO);
	ControllerBase* hero = field.createObjectController(1, *heroInfo, CustomPoint(1.0f, 10.0f));
	res.push_back(hero);	
	
	ObjectInfo* aiSpawnerInfo = Infos::getInfoBy(Infos::ENEMY_SPAWNER);
	ControllerBase* aiSpawner = field.createObjectController(2, *aiSpawnerInfo, CustomPoint(40.0f, 10.0f));
	res.push_back(aiSpawner);

// 	
// 	ObjectInfo* chargerInfo = Infos::getInfoBy(Infos::CHARGER);
// 	ControllerBase* charger = field.createObjectController(3, *chargerInfo, CustomPoint(5.0f, 20.0f));
// 	res.push_back(charger);
// 
// 	ObjectInfo* energyPackInfo = Infos::getInfoBy(Infos::SMALL_ENERGY_PACK);
// 	ControllerBase* energyPack = field.createObjectController(4, *energyPackInfo, CustomPoint(20.0f, 30.0f));
// 	res.push_back(energyPack);
// 
// 	energyPackInfo = Infos::getInfoBy(Infos::MEDIUM_ENERGY_PACK);
// 	energyPack = field.createObjectController(5, *energyPackInfo, CustomPoint(40.0f, 30.0f));
// 	res.push_back(energyPack);
	
	return res;
}
