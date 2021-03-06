#pragma once
#include "stdafx.h"
#include "ObjectBase.h"
#include "IDrawable.h"

class ViewBase : public IDrawable
{
public:
	ViewBase(void);
	~ViewBase(void);

	static int count;

	void draw();

	void setObject(ObjectBase* val) { object = val; }
	
protected:
	ObjectBase* object;
};

