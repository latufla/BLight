#pragma once
#include "stdafx.h"
#include "IDrawable.h"
#include "ControllerBase.h"
#include "TextBase.h"
#include "CustomPoint.h"

class SceneController : public IDrawable
{
public:
	static SceneController& getInstance() {
		static SceneController instance;
		return instance;
	}
		
	void init();

	void draw();

	void addChild(IDrawable*);
	void removeChild(IDrawable*);
	
	TextBase* getEnergyText() { return &energyText;}

protected:	
	SceneController() {};               
	SceneController(SceneController const&);              
	void operator=(SceneController const&);

	vector<IDrawable*> drawList;
	
	TextBase energyText;
};

