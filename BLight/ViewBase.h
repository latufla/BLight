#pragma once
#include "stdafx.h"
#include "ObjectBase.h"
#include "IDrawable.h"
#include "EngineConnector.h"

class ViewBase : public IDrawable
{
public:
	ViewBase(void);
	~ViewBase(void);

	void draw();

	void setObject(ObjectBase* val) { object = val; }
	
protected:
	ObjectBase* object;
};

