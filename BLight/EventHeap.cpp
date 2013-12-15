#include "EventHeap.h"

template<class I, class L>
void EventHeap<I, L>::registerObject( I* obj, L* view, void (L::*listen)(I*))
{	
	Signal_v1<I*> signal;
	slots.connect(signal, view, listen);
	signals[obj] = signal;
}

template<class I, class L>
void EventHeap<I, L>::fire(I* obj)
{
	Signal_v1<I*>* signal = &signals[obj];

	if(signal != nullptr)
		signal->invoke(obj);
}

template<class I, class L>
void EventHeap<I, L>::unregisterObject( I* obj)
{
	signals.erase(obj);
}



