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

void mainLoop(int);

ObjectBase* obstacle;
ObjectBase* charger;
ObjectBase* hero;
ObjectBase* energyPack;

ControllerBase* obstacleC;
ControllerBase* chargerC;
ControllerBase* heroC;
ControllerBase* energyPackC;

Field* field;

int _tmain(int argc, _TCHAR* argv[])
{ 
	field = new Field();
	PhEngineConnector::getInstance().init(field); // should be earlier all object bases

	obstacle = field->createObject(1, "gBox", 0, CustomPoint(0.1f, 0.1f));	

	CustomPolygon* poly = new CustomPolygon(5.0f, 1.0f);
	obstacle->setShape((CustomShape*)poly);
	obstacleC = new ControllerBase(obstacle);
	obstacleC->startBehaviors();
	Scene::getInstance().addChild(obstacleC);


	charger = field->createObject(2, "sBox", 0, CustomPoint(5.0f, 20.0f));	

	poly = new CustomPolygon(4.0f, 4.0f);
	charger->setShape((CustomShape*)poly);
	charger->setSensor(true);
	chargerC = new ControllerBase(charger);
	chargerC->addBehavior(new ChargerBehavior());
	chargerC->startBehaviors();
	Scene::getInstance().addChild(chargerC);

	hero = field->createObject(3, "dBox", 2, CustomPoint(1.0f, 10.0f));

	CustomCircle* circle = new CustomCircle(CustomPoint(0.0f, 0.0f), 1.0f);
	hero->setShape((CustomShape*)circle);
	hero->setDensity(1.0f);
	hero->setFriction(0.3f);
	hero->setRestitution(.5f);
	hero->setLinearDamping(1.0f);

	heroC = new ControllerBase(hero);
	heroC->addBehavior(new UserControlBehavior());
	heroC->addBehavior(new MoveBehavior());
	heroC->startBehaviors();
	Scene::getInstance().addChild(heroC);

	
	energyPack = field->createObject(2, "eBox", 0, CustomPoint(20.0f, 30.0f));	

	poly = new CustomPolygon(1.0f, 1.0f);
	energyPack->setShape((CustomShape*)poly);
	energyPackC = new ControllerBase(energyPack);
	energyPackC->addBehavior(new SimpleDropBehavior(20));
	energyPackC->startBehaviors();
	Scene::getInstance().addChild(energyPackC);

	EngineConnector::start(&mainLoop);
	
	return 0; 
}

void mainLoop(int elapsedTime)
{
  	// EngineConnector::printDebug(to_string(long long(elapsedTime)));

	// behaviors
	obstacleC->doBehaviorsStep(elapsedTime);
	heroC->doBehaviorsStep(elapsedTime);
	chargerC->doBehaviorsStep(elapsedTime);

	// phys
	PhEngineConnector::getInstance().doStep(elapsedTime);

	// draw stuff
	Scene::getInstance().draw();
}