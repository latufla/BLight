#include "stdafx.h"
#include "ObjectBase.h"
#include "BehaviorBase.h"
#include "ControllerBase.h"
#include "StubBehavior.h"
#include "EngineConnector.h"
#include "PhEngineConnector.h"

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

	pair<float, float> pos(0.0f, -10.0f);
	groundBox = field->createObject(1, "gBox", 0, pos);
	groundBox->setBoxShape(50.0f, 10.0f);

	pair<float, float> pos2(0.0f, 4.0f);
	dynamicBox = field->createObject(2, "dBox", 2, pos2);
	dynamicBox->setBoxShape(1.0f, 1.0f);
	dynamicBox->setDensity(1.0f);
	dynamicBox->setFriction(0.3f);
	dynamicBox->setRestitution(1.0f);

	auto vxs = dynamicBox->getVertexes();
	printf("vertexes:\n");
	for (auto it = vxs.cbegin(); it != vxs.cend(); it++){
		EngineConnector::printDebug((CustomPoint)*it);
	}

	EngineConnector::start(&mainLoop);
	
	return 0; 
}

void mainLoop(int elapsedTime)
{
//  	EngineConnector::printDebug(to_string(long long(elapsedTime)));

	// behaviors
// 	c->doBehaviorsStep(elapsedTime);
// 	c2->doBehaviorsStep(elapsedTime);

	// phys
	PhEngineConnector::getInstance().doStep(elapsedTime);

	CustomPoint position = dynamicBox->getPosition();
	float angle = dynamicBox->getRotation();
 	printf("position: %4.2f %4.2f %4.2f\n", position.x, position.y, angle);

	auto vxs = dynamicBox->getVertexes();
	printf("vertexes:\n");
	for (auto it = vxs.cbegin(); it != vxs.cend(); it++){
		EngineConnector::printDebug((CustomPoint)*it);
	}

	// draw stuff
}