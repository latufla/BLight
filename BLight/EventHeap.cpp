#include "EventHeap.h"

SlotContainer EventHeap::slots;
map<ObjectBase*, clan::Signal_v1<ObjectBase*>> EventHeap::signals;

EventHeap::EventHeap(void)
{
}


EventHeap::~EventHeap(void)
{
}

void EventHeap::registerObject( ObjectBase* obj, ViewBase* view)
{	
	Signal_v1<ObjectBase*> signal;
	slots.connect(signal, view, &ViewBase::update);
	signals[obj] = signal;
}

void EventHeap::fire(ObjectBase* obj)
{
	Signal_v1<ObjectBase*>* signal = &signals[obj];

	if(signal != nullptr)
		signal->invoke(obj);
}

void EventHeap::unregisterObject( ObjectBase* obj)
{
	signals.erase(obj);
}

