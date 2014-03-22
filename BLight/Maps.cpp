#include "Maps.h"


vector<ControllerBase*> Maps::createDemoMap(FieldController& field)
{
	vector<ControllerBase*> res;

	ObjectInfo* heroInfo = Infos::createHero();
	ControllerBase* hero = field.createObjectController(1, *heroInfo, CustomPoint(1.0f, 10.0f));
	delete heroInfo;
	res.push_back(hero);	
	
	ObjectInfo* aiDummyInfo = Infos::createEnemy();
	ControllerBase* aiDummy = field.createObjectController(2, *aiDummyInfo, CustomPoint(40.0f, 10.0f));
	delete aiDummyInfo;
	res.push_back(aiDummy);
	
	ObjectInfo* chargerInfo = Infos::createCharger();
	ControllerBase* charger = field.createObjectController(3, *chargerInfo, CustomPoint(5.0f, 20.0f));
	delete chargerInfo;
	res.push_back(charger);

	ObjectInfo* energyPackInfo = Infos::createSmallEnergyPack();
	ControllerBase* energyPack = field.createObjectController(4, *energyPackInfo, CustomPoint(20.0f, 30.0f));
	delete energyPackInfo;
	res.push_back(energyPack);

	energyPackInfo = Infos::createMediumEnergyPack();
	energyPack = field.createObjectController(5, *energyPackInfo, CustomPoint(40.0f, 30.0f));
	delete energyPackInfo;
	res.push_back(energyPack);
	
	return res;
}
