#pragma once
#include "stdafx.h"
#include "ControllerBase.h"
#include "Infos.h"
#include "FieldController.h"
#include "IManager.h"
#include "SceneController.h"

class LevelManager : public IManager
{
public:
	static LevelManager& getInstance() {
		static LevelManager instance;
		return instance;
	}
		
	void init(SceneController&, FieldController&, Infos&);

	bool doStep(int){ return true; }
	
protected:
	LevelManager(){};
	LevelManager(LevelManager const&);
	void operator=(LevelManager const&);

	~LevelManager();

	void applyAdditionalSettings(ControllerBase* c);
};
