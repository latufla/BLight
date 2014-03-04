#pragma once
#include "stdafx.h"
#include "ObjectBase.h"
#include <functional>
#include "IDrawable.h"

class ViewBase : public IDrawable
{
public:
	ViewBase(void);
	~ViewBase(void);

	void draw();

	ObjectBase* getObject() const { return object; }
	void setObject(ObjectBase* val) { object = val; }
	
	// deprecate
	void update(ObjectBase*);
	std::function<void(EventDispatcher*)> getUpdateListener();
	//std::function<void(EventDispatcher*)> updateListener;

protected:
	ObjectBase* object;
};

