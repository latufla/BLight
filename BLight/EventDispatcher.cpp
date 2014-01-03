#include "EventDispatcher.h"


EventDispatcher::EventDispatcher(void)
{
}

EventDispatcher::EventDispatcher( int id )
{
	this->id = id;
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
