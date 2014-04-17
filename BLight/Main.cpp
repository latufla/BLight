#include "stdafx.h"
#include "ControllerBase.h"
#include "DebuggerBehavior.h"
#include "Infos.h"
#include "Maps.h"
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

	SceneController& scene = SceneController::getInstance();
	scene.init();
	Config::scene = &SceneController::getInstance();

	Config::managers.push_back((IManager*)&PopupManager::getInstance());
	Config::managers.push_back((IManager*)&StatusViewManager::getInstance());
	Config::managers.push_back((IManager*)&QuestManager::getInstance());

	QuestInfo* qInfo = new QuestInfo();
	qInfo->id = 0;
	qInfo->name = "quest1";
	QuestGoalInfo qGoalInfo;
	qGoalInfo.command = "AttackCommand";
	qGoalInfo.target = "enemy";
	qGoalInfo.count = 1;
	qInfo->goals.push_back(qGoalInfo);
	QuestBase* quest = new QuestBase(*qInfo);
	
	QuestManager::getInstance().add(quest);


	FieldController& field = FieldController::getInstance();
	field.setName("field");
	field.addBehavior(new DebuggerBehavior());
	field.init();
	Config::field = &field;

	vector<ControllerBase*>* mapInfo = Maps::createMap();
	for(auto it = mapInfo->cbegin(); it != mapInfo->cend(); it++){
		scene.addChild((*it)->getView());
		applyAdditionalSettings(*it);
	}
	delete mapInfo; // but not infos

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

void applyAdditionalSettings(ControllerBase* c)
{
	if(c->getName() == "player")
		Config::player = c;

	if(c->getDisplayStatus())
		StatusViewManager::getInstance().addStatusView(c);
}

