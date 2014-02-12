#include "stdafx.h"
#include "ObjectBase.h"
#include "BehaviorBase.h"
#include "ControllerBase.h"
#include "StubBehavior.h"
#include "EngineConnector.h"
#include "PhEngineConnector.h"
#include "CustomCircle.h"

void mainLoop(int);

// ObjectBase* obj1 = new ObjectBase(1, "obj1");
// StubBehavior* b1 = new StubBehavior(1, "move");
// ControllerBase* c = new ControllerBase(obj1);
// 
// ObjectBase* obj2 = new ObjectBase(2, "obj2");
// StubBehavior* b2 = new StubBehavior(2, "sleep");
// ControllerBase* c2 = new ControllerBase(obj2);

ObjectBase* groundBox;
ObjectBase* dynamicBox;
ControllerBase* groundBoxC;
ControllerBase* dynamicBoxC;

Field* field;

int _tmain(int argc, _TCHAR* argv[])
{ 
// 	c->addBehavior(b1);
// 	c->startBehaviors();
// 	
// 	c2->addBehavior(b2);
// 	c2->startBehaviors();

	field = new Field();
	PhEngineConnector::getInstance().init(field); // should be earlier all object bases

	pair<float, float> pos(1.0f, 2.0f);
	groundBox = field->createObject(1, "gBox", 0, pos);
	
// 	vector<CustomPoint>* poly = new vector<CustomPoint>();
// 	poly->push_back(CustomPoint(0.0f, 0.0f));
// 	poly->push_back(CustomPoint(5.0f, 0.0f));
// 	poly->push_back(CustomPoint(5.0f, 1.0f));
// 	poly->push_back(CustomPoint(0.0f, 1.0f));
// 	groundBox->setPolygonShape(poly);



	CustomPolygon* poly = new CustomPolygon(5.0f, 1.0f);
	groundBox->setShape((CustomShape*)new CustomPolygon(5.0f, 1.0f));
	

	groundBoxC = new ControllerBase(groundBox);

	pair<float, float> pos2(1.0f, 10.0f);
	dynamicBox = field->createObject(2, "dBox", 2, pos2);

	//dynamicBox->setShape((CustomShape*)new CustomPolygon(1.0f, 1.0f));
	CustomCircle* circle = new CustomCircle();
	circle->setRadius(1.0f);
	circle->setPosition(CustomPoint(0.0f, 0.0f));
	dynamicBox->setShape((CustomShape*)circle);
	//delete poly;
	dynamicBox->setDensity(1.0f);
	dynamicBox->setFriction(0.3f);
	dynamicBox->setRestitution(.5f);
	dynamicBoxC = new ControllerBase(dynamicBox);

	EngineConnector::start(&mainLoop);
	
	return 0; 
}

void mainLoop(int elapsedTime)
{
  	// EngineConnector::printDebug(to_string(long long(elapsedTime)));

	// behaviors
 	// c->doBehaviorsStep(elapsedTime);
 	// c2->doBehaviorsStep(elapsedTime);

	// phys
	PhEngineConnector::getInstance().doStep(elapsedTime);

	CustomPoint position = dynamicBox->getPosition();
	float angle = dynamicBox->getRotation();
 	
	// draw stuff
	groundBoxC->draw();
	dynamicBoxC->draw();
}