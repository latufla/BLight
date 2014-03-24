#include "stdafx.h"
#include "ControllerBase.h"
#include "EngineConnector.h"
#include "PhEngineConnector.h"
#include "SceneController.h"
#include "FieldController.h"
#include "DebuggerBehavior.h"
#include "JsonConnector.h"
#include "Infos.h"
#include "Maps.h"
#include "PopupManager.h"
#include "StatusViewManager.h"
#include "Config.h"

void mainLoop(int);
void setUp(ControllerBase*);

int _tmain(int argc, _TCHAR* argv[])
{ 
// 	FILE * pFile = fopen ("config/game_objects.json" , "r");
// 	JsonConnector::getInstance().createInfoFromJson(pFile);
	
	Config::engine = &EngineConnector::getInstance();
	Config::phEngine = &PhEngineConnector::getInstance();

	SceneController& scene = SceneController::getInstance();
	scene.init();
	Config::scene = &SceneController::getInstance();

	Config::managers.push_back((IManager*)&PopupManager::getInstance());
	Config::managers.push_back((IManager*)&StatusViewManager::getInstance());

	FieldController& field = FieldController::getInstance();
	field.setName("field");
	field.addBehavior(new DebuggerBehavior());
	field.init();
	Config::field = &field;

	vector<ControllerBase*> mapInfo = Maps::createDemoMap(field);
	for(auto it = mapInfo.cbegin(); it != mapInfo.cend(); it++){
		scene.addChild((*it)->getView());
		setUp(*it);
	}

	field.startBehaviors();

	Config::engine->printDebugInstances();
	Config::engine->init(&mainLoop);

	return 0; 
}

void mainLoop(int elapsedTime)
{
	Config::field->doBehaviorsStep(elapsedTime);
	Config::phEngine->doStep(elapsedTime);	
	
	for(auto it = Config::managers.cbegin(); it != Config::managers.cend(); it++){
		(*it)->doStep(elapsedTime);
	}

	Config::scene->draw();
}

void setUp(ControllerBase* c)
{
	if(c->getName() == "aiDummy")
		StatusViewManager::getInstance().addStatusView(c);

	if(c->getName() == "hero"){
		Config::player = c;
		StatusViewManager::getInstance().addStatusView(c);
	}
}

