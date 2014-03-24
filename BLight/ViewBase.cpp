#include "ViewBase.h"
#include "Config.h"

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
		Config::engine->drawShape((CustomPolygon*)sp);
	else if(CustomShape::isCircle(sp))
		Config::engine->drawShape((CustomCircle*)sp);
}
