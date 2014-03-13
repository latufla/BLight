#include "ViewBase.h"

int ViewBase::count = 0;

ViewBase::ViewBase(void) : object(nullptr)
{
	count++;
}

ViewBase::~ViewBase(void)
{
	count--;
}


void ViewBase::draw()
{	
	if(object == nullptr)
		return;

	CustomShape* sp = object->getShape();
	if(CustomShape::isPolygon(sp))
		EngineConnector::getInstance().drawShape((CustomPolygon*)sp);
	else if(CustomShape::isCircle(sp))
		EngineConnector::getInstance().drawShape((CustomCircle*)sp);
}
