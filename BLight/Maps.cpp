#include "Maps.h"
#include "StatusViewManager.h"


vector<ControllerBase*> Maps::createDemoMap(FieldController& field)
{
	vector<ControllerBase*> res;

	ObjectInfo* heroInfo = Infos::getHeroInfo();
	ControllerBase* hero = field.createObjectController(1, *heroInfo, CustomPoint(1.0f, 10.0f));
	delete heroInfo;
	res.push_back(hero);	
	
	ObjectInfo* aiSpawnerInfo = Infos::getEnemySpawnerInfo();
	ControllerBase* aiSpawner = field.createObjectController(2, *aiSpawnerInfo, CustomPoint(40.0f, 10.0f));
	delete aiSpawnerInfo;
	res.push_back(aiSpawner);
	
	ObjectInfo* chargerInfo = Infos::getChargerInfo();
	ControllerBase* charger = field.createObjectController(3, *chargerInfo, CustomPoint(5.0f, 20.0f));
	delete chargerInfo;
	res.push_back(charger);

	ObjectInfo* energyPackInfo = Infos::getSmallEnergyPackInfo();
	ControllerBase* energyPack = field.createObjectController(4, *energyPackInfo, CustomPoint(20.0f, 30.0f));
	delete energyPackInfo;
	res.push_back(energyPack);

	energyPackInfo = Infos::getMediumEnergyPackInfo();
	energyPack = field.createObjectController(5, *energyPackInfo, CustomPoint(40.0f, 30.0f));
	delete energyPackInfo;
	res.push_back(energyPack);
	
	return res;
}
