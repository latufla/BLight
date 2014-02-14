#include "ViewBase.h"
#include "EngineConnector.h"

ViewBase::ViewBase(void)
{
// 	ViewBase* self = this;
// 	updateListener = [self](EventDispatcher* obj) { 
// 		self->update((ObjectBase*)obj);
// 	};
}


ViewBase::~ViewBase(void)
{
}

void ViewBase::draw(ObjectBase* obj)
{	
	CustomShape* sp = obj->getShape();
	if(CustomShape::isPolygon(sp))
		EngineConnector::drawShape((CustomPolygon*)sp);
	else if(CustomShape::isCircle(sp))
		EngineConnector::drawShape((CustomCircle*)sp);
}


void ViewBase::update(ObjectBase* obj)
{
	EngineConnector::printDebug("update view with: " + string(*obj));
}

std::function<void(EventDispatcher*)> ViewBase::getUpdateListener()
{
	ViewBase* self = this;
	return [self](EventDispatcher* obj) { 
		self->update((ObjectBase*)obj);
	};
}
