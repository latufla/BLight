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
#include "Maps.h"

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

	vector<ControllerBase*> mapInfo = Maps::createDemoMap(field);
	for(auto it = mapInfo.cbegin(); it != mapInfo.cend(); it++){
		scene.addChild((*it)->getView());
	}

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

