#include "stdafx.h"
#include "ObjectBase.h"
#include "BehaviorBase.h"
#include "ControllerBase.h"
#include "StubBehavior.h"
#include "EngineConnector.h"
#include "PhEngineConnector.h"

void mainLoop(int);

ObjectBase* obj1 = new ObjectBase(1, "obj1");
StubBehavior* b1 = new StubBehavior(1, "move");
ControllerBase* c = new ControllerBase(obj1);

ObjectBase* obj2 = new ObjectBase(2, "obj2");
StubBehavior* b2 = new StubBehavior(2, "sleep");
ControllerBase* c2 = new ControllerBase(obj2);

PhEngineConnector phEC;
int _tmain(int argc, _TCHAR* argv[])
{ 
	c->addBehavior(b1);
	c->startBehaviors();
	
	c2->addBehavior(b2);
	c2->startBehaviors();

	phEC.init();

	EngineConnector::start(&mainLoop);
	
	return 0; 
}

void mainLoop(int elapsedTime)
{
 	EngineConnector::printDebug(to_string(long long(elapsedTime)));
 	
	// behaviors
	c->doBehaviorsStep(elapsedTime);
 	c2->doBehaviorsStep(elapsedTime);

	// phys
	phEC.doStep(elapsedTime);

	// draw stuff
}