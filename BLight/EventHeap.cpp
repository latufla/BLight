#include "EventHeap.h"

template<class I, class L>
void EventHeap<I, L>::registerObject( I* obj, L* view, void (L::*listener)(I*), EventType typeId)
{	
	EventData<I, L> eData;
	eData.typeId = typeId;
	eData.invoker = obj;
	eData.reciever = view;
	eData.listener = listener;
	events.push_back(eData);
}

template<class I, class L>
void EventHeap<I, L>::fire(I* obj, EventType typeId)
{
	for (auto it = events.cbegin(); it != events.cend(); it++){
		I* invoker = (*it).invoker;
		int id = (*it).typeId;
		if(*invoker == *obj && id == typeId){
			void (L::*listener)(I*) = (*it).listener;
			L* reciever = (*it).reciever;
			if(reciever != nullptr && listener != nullptr)
				(reciever->*listener)(obj);
		}
	}		
}

template<class I, class L>
void EventHeap<I, L>::unregisterObject( I* obj)
{
	events.erase(remove_if(events.begin(), events.end(), [obj](const EventData<I,L>& eData) -> bool{
		I* invoker = eData.invoker;
		return *invoker == *obj;
	}), events.end());
}



