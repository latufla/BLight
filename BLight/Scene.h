#pragma once
#include "stdafx.h"
#include "IDrawable.h"
#include "ControllerBase.h"
#include "TextBase.h"

class Scene : public IDrawable
{
public:
	static Scene& getInstance() {
		static Scene instance;
		return instance;
	}
		
	void draw();

	void addChild(ViewBase*);
	void addChild(TextBase*);

protected:	
	Scene() {};               
	Scene(Scene const&);              
	void operator=(Scene const&);

	vector<IDrawable*> drawList;
};

