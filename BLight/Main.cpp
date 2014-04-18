#include "stdafx.h"
#include "ControllerBase.h"
#include "DebuggerBehavior.h"
#include "Infos.h"
#include "LevelManager.h"
#include "PopupManager.h"
#include "StatusViewManager.h"
#include "Config.h"
#include "QuestManager.h"

void mainLoop(int);
void applyAdditionalSettings(ControllerBase*);

int _tmain(int argc, _TCHAR* argv[])
{ 
	Config::engine = &EngineConnector::getInstance();
	Config::phEngine = &PhEngineConnector::getInstance();

	Config::scene = &SceneController::getInstance();
	Config::scene->init();
	
	Config::managers.push_back((IManager*)&PopupManager::getInstance());
	Config::managers.push_back((IManager*)&StatusViewManager::getInstance());
	Config::managers.push_back((IManager*)&QuestManager::getInstance());
	Config::managers.push_back((IManager*)&LevelManager::getInstance());

	Config::field = &FieldController::getInstance();
	Config::field->setName("field");
	Config::field->addBehavior(new DebuggerBehavior());
	Config::field->init();
	
	Infos::getInstance().init("config/");		
	QuestManager::getInstance().init(Infos::getInstance());
 	LevelManager::getInstance().init(*Config::scene, *Config::field, Infos::getInstance());

	Config::field->startBehaviors();

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

