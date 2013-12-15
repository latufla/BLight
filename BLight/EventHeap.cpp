#include "EventHeap.h"

template<class I, class L>
void EventHeap<I, L>::registerObject( I* obj, L* view, void (L::*listen)(I*))
{	
	recievers[obj] = view;
	listeners[obj] = listen;
}

template<class I, class L>
void EventHeap<I, L>::fire(I* obj)
{
	void (L::*listener)(I*) = listeners[obj];
	L* reciever = recievers[obj];
	
	if(reciever != nullptr && listener != nullptr)
		(reciever->*listener)(obj);
}

template<class I, class L>
void EventHeap<I, L>::unregisterObject( I* obj)
{
	recievers.erase(obj);
	listeners.erase(obj);
}



