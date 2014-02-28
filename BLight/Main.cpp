#include "stdafx.h"
#include "ObjectBase.h"
#include "BehaviorBase.h"
#include "ControllerBase.h"
#include "EngineConnector.h"
#include "PhEngineConnector.h"
#include "CustomCircle.h"
#include "UserControlBehavior.h"
#include "MoveBehavior.h"

void mainLoop(int);

ObjectBase* groundBox;
ObjectBase* dynamicBox;
ControllerBase* groundBoxC;
ControllerBase* dynamicBoxC;

Field* field;

int _tmain(int argc, _TCHAR* argv[])
{ 
	field = new Field();
	PhEngineConnector::getInstance().init(field); // should be earlier all object bases

	groundBox = field->createObject(1, "gBox", 0, CustomPoint(0.1f, 0.1f));	
	
	CustomPolygon* poly = new CustomPolygon(5.0f, 1.0f);
	groundBox->setShape((CustomShape*)poly);
	groundBoxC = new ControllerBase(groundBox);

	dynamicBox = field->createObject(2, "dBox", 2, CustomPoint(1.0f, 10.0f));

	CustomCircle* circle = new CustomCircle(CustomPoint(0.0f, 0.0f), 1.0f);
	dynamicBox->setShape((CustomShape*)circle);
	dynamicBox->setDensity(1.0f);
	dynamicBox->setFriction(0.3f);
	dynamicBox->setRestitution(.5f);
	dynamicBox->setLinearDamping(1.0f);

	dynamicBoxC = new ControllerBase(dynamicBox);
	dynamicBoxC->addBehavior(new UserControlBehavior());
	dynamicBoxC->addBehavior(new MoveBehavior());
	dynamicBoxC->startBehaviors();

	EngineConnector::start(&mainLoop);
	
	return 0; 
}

void mainLoop(int elapsedTime)
{
  	// EngineConnector::printDebug(to_string(long long(elapsedTime)));

	// behaviors
	dynamicBoxC->doBehaviorsStep(elapsedTime);

	// phys
	PhEngineConnector::getInstance().doStep(elapsedTime);

	CustomPoint position = dynamicBox->getPosition();
	float angle = dynamicBox->getRotation();
 	
	// draw stuff
	groundBoxC->draw();
	dynamicBoxC->draw();
}