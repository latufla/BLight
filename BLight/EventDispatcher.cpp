#include "EventDispatcher.h"


EventDispatcher::EventDispatcher(void)
{
}


EventDispatcher::~EventDispatcher(void)
{
}

int EventDispatcher::getId()
{
	return id;
}

bool EventDispatcher::operator==( EventDispatcher d)
{
	return this->id == d.getId();
}
