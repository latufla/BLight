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

void mainLoop(int);


int _tmain(int argc, _TCHAR* argv[])
{ 
	SceneController& scene = SceneController::getInstance();
	scene.init();

	FieldController& field = FieldController::getInstance();
	field.init();
	

	ControllerBase* obstacle = field.createObjectController(1, "gBox", 0, CustomPoint(0.1f, 0.1f));

	CustomPolygon* poly = new CustomPolygon(5.0f, 1.0f);
	ObjectBase* object = obstacle->getObject(); 
	object->setShape((CustomShape*)poly);
	scene.addChild(obstacle->getView());


	ControllerBase* charger = field.createObjectController(2, "sBox", 0, CustomPoint(5.0f, 20.0f));

	poly = new CustomPolygon(4.0f, 4.0f);
	object = charger->getObject();
	object->setShape((CustomShape*)poly);
	object->setSensor(true);
	charger->addBehavior(new ChargerBehavior());
	scene.addChild(charger->getView());
	
	
	ControllerBase* hero = field.createObjectController(3, "dBox", 2, CustomPoint(1.0f, 10.0f));

	CustomCircle* circle = new CustomCircle(CustomPoint(0.0f, 0.0f), 1.0f);
	object = hero->getObject();
	object->setShape((CustomShape*)circle);
	object->setDensity(1.0f);
	object->setFriction(0.3f);
	object->setRestitution(.5f);
	object->setLinearDamping(1.0f);
	
	scene.getEnergyText().setText("Energy: " + to_string(long long(object->getEnergy())));

	hero->addBehavior(new UserControlBehavior());
	hero->addBehavior(new MoveBehavior());
	scene.addChild(hero->getView());


	ControllerBase* energyPack = field.createObjectController(2, "eBox", 0, CustomPoint(20.0f, 30.0f));

	poly = new CustomPolygon(1.0f, 1.0f);
	object = energyPack->getObject();
	object->setShape((CustomShape*)poly);
	energyPack->addBehavior(new SimpleDropBehavior(20));
	scene.addChild(energyPack->getView());

	
	field.startBehaviors();
	EngineConnector::getInstance().init(&mainLoop);
	
	return 0; 
}

void mainLoop(int elapsedTime)
{
	FieldController::getInstance().doBehaviorsStep(elapsedTime);
	PhEngineConnector::getInstance().doStep(elapsedTime);	
	SceneController::getInstance().draw();
}