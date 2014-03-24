#include "Config.h"

EngineConnector* Config::engine = nullptr;
PhEngineConnector* Config::phEngine = nullptr;

SceneController* Config::scene = nullptr;
FieldController* Config::field = nullptr;

vector<IManager*> Config::managers;

ControllerBase* Config::player = nullptr;
