#pragma once
#include "ControllerBase.h"
#include "PhEngineConnector.h"
#include "FieldController.h"
#include "EngineConnector.h"
#include "SceneController.h"
#include "IManager.h"

// TODO: implement dtor for all static and clear Config
class Config
{
public:
	static EngineConnector* engine; 
	static PhEngineConnector* phEngine; 

	static SceneController* scene;
	static FieldController* field;

	static vector<IManager*> managers;

	static ControllerBase* player; 
};

