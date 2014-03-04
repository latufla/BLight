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
#include "Scene.h"
#include "SimpleDropBehavior.h"
#include "FieldController.h"

void mainLoop(int);

FieldController* field;

int _tmain(int argc, _TCHAR* argv[])
{ 
	field = new FieldController();

	ControllerBase* obstacle = field->createObjectController(1, "gBox", 0, CustomPoint(0.1f, 0.1f));

	CustomPolygon* poly = new CustomPolygon(5.0f, 1.0f);
	ObjectBase* object = obstacle->getObject(); 
	object->setShape((CustomShape*)poly);
	Scene::getInstance().addChild(obstacle->getView());


	ControllerBase* charger = field->createObjectController(2, "sBox", 0, CustomPoint(5.0f, 20.0f));

	poly = new CustomPolygon(4.0f, 4.0f);
	object = charger->getObject();
	object->setShape((CustomShape*)poly);
	object->setSensor(true);
	charger->addBehavior(new ChargerBehavior());
	Scene::getInstance().addChild(charger->getView());
	
	
	ControllerBase* hero = field->createObjectController(3, "dBox", 2, CustomPoint(1.0f, 10.0f));

	CustomCircle* circle = new CustomCircle(CustomPoint(0.0f, 0.0f), 1.0f);
	object = hero->getObject();
	object->setShape((CustomShape*)circle);
	object->setDensity(1.0f);
	object->setFriction(0.3f);
	object->setRestitution(.5f);
	object->setLinearDamping(1.0f);

	hero->addBehavior(new UserControlBehavior());
	hero->addBehavior(new MoveBehavior());
	Scene::getInstance().addChild(hero->getView());


	ControllerBase* energyPack = field->createObjectController(2, "eBox", 0, CustomPoint(20.0f, 30.0f));

	poly = new CustomPolygon(1.0f, 1.0f);
	object = energyPack->getObject();
	object->setShape((CustomShape*)poly);
	energyPack->addBehavior(new SimpleDropBehavior(20));
	Scene::getInstance().addChild(energyPack->getView());

	
	field->startBehaviors();
	EngineConnector::start(&mainLoop);
	
	return 0; 
}

void mainLoop(int elapsedTime)
{
  	// EngineConnector::printDebug(to_string(long long(elapsedTime)));

	// behaviors
	field->doBehaviorsStep(elapsedTime);

	// phys
	PhEngineConnector::getInstance().doStep(elapsedTime);

	// draw stuff
	Scene::getInstance().draw();
}