#include "stdafx.h"
#include "ObjectBase.h"
#include "BehaviorBase.h"
#include "ControllerBase.h"
#include "EngineConnector.h"
#include "PhEngineConnector.h"
#include "CustomCircle.h"
#include "UserControlBehavior.h"
#include "MoveBehavior.h"
#include "ChargerBehavior.h"
#include "SceneController.h"
#include "SimpleDropBehavior.h"
#include "FieldController.h"
#include "DebuggerBehavior.h"
#include "AIControlBehavior.h"
#include "JsonConnector.h"
#include "Infos.h"

void mainLoop(int);

int _tmain(int argc, _TCHAR* argv[])
{ 
// 	FILE * pFile = fopen ("config/game_objects.json" , "r");
// 	JsonConnector::getInstance().createInfoFromJson(pFile);

	SceneController& scene = SceneController::getInstance();
	scene.init();

	FieldController& field = FieldController::getInstance();
	field.setName("field");
	field.addBehavior(new DebuggerBehavior());
	field.init();

	
	ObjectInfo* heroInfo = Infos::createHero();
	ControllerBase* hero = field.createObjectController(1, *heroInfo, CustomPoint(1.0f, 10.0f));
	delete heroInfo;
	scene.getEnergyText().setText("Energy: " + to_string(long long(hero->getObject()->getEnergy())));	
	scene.addChild(hero->getView());
	
	ObjectInfo* aiDummyInfo = Infos::createEnemy();
	ControllerBase* aiDummy = field.createObjectController(2, *aiDummyInfo, CustomPoint(40.0f, 10.0f));
	delete aiDummyInfo;
	scene.addChild(aiDummy->getView());


	ObjectInfo* chargerInfo = Infos::createCharger();
	ControllerBase* charger = field.createObjectController(3, *chargerInfo, CustomPoint(5.0f, 20.0f));
	delete chargerInfo;
	scene.addChild(charger->getView());


	ObjectInfo* energyPackInfo = Infos::createSmallEnergyPack();
	ControllerBase* energyPack = field.createObjectController(4, *energyPackInfo, CustomPoint(20.0f, 30.0f));
	delete energyPackInfo;
	scene.addChild(energyPack->getView());
		
	energyPackInfo = Infos::createMediumEnergyPack();
	energyPack = field.createObjectController(5, *energyPackInfo, CustomPoint(40.0f, 30.0f));
	delete energyPackInfo;
	scene.addChild(energyPack->getView());


	field.startBehaviors();
	EngineConnector::getInstance().printDebugInstances();
	EngineConnector::getInstance().init(&mainLoop);

	return 0; 
}

void mainLoop(int elapsedTime)
{
	FieldController::getInstance().doBehaviorsStep(elapsedTime);
	PhEngineConnector::getInstance().doStep(elapsedTime);	
	SceneController::getInstance().draw();
}

