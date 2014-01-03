#include "ViewBase.h"
#include "EngineConnector.h"

ViewBase::ViewBase(void)
{
	ViewBase* self = this;
	updateListener = [self](EventDispatcher* obj) { 
		self->update((ObjectBase*)obj);
	};
}


ViewBase::~ViewBase(void)
{
}

void ViewBase::update(ObjectBase* obj)
{
	EngineConnector::printDebug("update view with: " + string(*obj));
}


