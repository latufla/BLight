#include "stdafx.h"
#include "ObjectBase.h"
#include "BehaviorBase.h"
#include "ControllerBase.h"
#include "StubBehavior.h"
#include "EngineConnector.h"

EngineConnector engineConnector;
void mainLoop(int);

ObjectBase* obj1 = new ObjectBase(1, "obj1");
StubBehavior* b1 = new StubBehavior(1, "move");
ControllerBase* c = new ControllerBase(obj1);


ObjectBase* obj2 = new ObjectBase(2, "obj2");
StubBehavior* b2 = new StubBehavior(2, "sleep");
ControllerBase* c2 = new ControllerBase(obj2);

int _tmain(int argc, _TCHAR* argv[])
{ 
	c->addBehavior(b1);
	c->startBehaviors();
	
	c2->addBehavior(b2);
	c2->startBehaviors();

	engineConnector.start(&mainLoop);
	
	return 0; 
}

void mainLoop(int elapsedTime)
{
	c->doBehaviorsStep(elapsedTime);
	c2->doBehaviorsStep(elapsedTime);
}


// TODO: deprecate
// void initialTests()
// {
// 	ObjectBase* obj1 = new ObjectBase();
// 	obj1->setId(1);
// 	obj1->setName("obj1");
// 
// 	ObjectBase* obj2 = new ObjectBase(2, "obj2");
// 
// 	
// 	BehaviorBase* b1 = new BehaviorBase(1, "move");
// 	b1->doStep(17);
// 	b1->onInteraction(obj1, obj2);
// 
// 	BehaviorBase* b2 = new BehaviorBase(2, "shoot");
// 	
// 	ControllerBase* c = new ControllerBase(obj1);
// 	c->addBehavior(b1);
// 	c->addBehavior(b2);
// 
// 	c->removeBehavior(b2);
// 
// 	StubBehavior* b3 = new StubBehavior(3, "cry");
// 	c->addBehavior(b3);
// 
// 	c->startBehaviors(StubBehavior::GetFullClassName());
// 	
// 	delete obj2;
// 	delete b2;
// 	delete c;
/*}*/