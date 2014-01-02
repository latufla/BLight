#include "EventHeap.h"

template<class D, class R>
void EventHeap<D, R>::addEventListener(D* dispatcher, R* reciever, void (R::*listener)(D*), EventType typeId)
{	
	EventData<D, R> eData;
	eData.typeId = typeId;
	eData.dispatcher = dispatcher;
	eData.reciever = reciever;
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
			void (R::*listener)(D*) = (*it).listener;
			R* reciever = (*it).reciever;
			if(reciever != nullptr && listener != nullptr)
				(reciever->*listener)(dispatcher);
		}
	}		
}



