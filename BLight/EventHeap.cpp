#include "EventHeap.h"

template<class D, class R>
void EventHeap<D, R>::addEventListener(D* dispatcher, R* receiver, std::function<void(void*)> listener, EventType typeId)
{	
	EventData<D, R> eData;
	eData.typeId = typeId;
	eData.dispatcher = dispatcher;
	eData.receiver = receiver;
	eData.listener = listener;
	events.push_back(eData);
}

template<class D, class R>
void EventHeap<D, R>::removeEventListener(D* dispatcher)
{
	events.erase(remove_if(events.begin(), events.end(), [dispatcher](const EventData<D,R>& eData) -> bool{
		D* dsp = eData.dispatcher;
		return *dsp == *dispatcher;
	}), events.end());
}

template<class D, class R>
void EventHeap<D, R>::dispatch(D* dispatcher, EventType typeId)
{
	for (auto it = events.cbegin(); it != events.cend(); it++){
		D* dsp = (*it).dispatcher;
		int id = (*it).typeId;
		if(*dsp == *dispatcher && id == typeId){
			auto listener = (*it).listener;
			R* receiver = (*it).receiver;
			if(receiver != nullptr && listener != nullptr)
				listener(dispatcher);
		}
	}		
}



