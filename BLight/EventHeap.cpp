#include "EventHeap.h"

void EventHeap::addEventListener(EventDispatcher* dispatcher, void* receiver, function<void(EventDispatcher*)> listener, EventType typeId)
{	
	EventData eData;
	eData.typeId = typeId;
	eData.dispatcher = dispatcher;
	eData.receiver = receiver;
	eData.listener = listener;
	events.push_back(eData);
}

void EventHeap::removeEventListener(EventDispatcher* dispatcher)
{
	events.erase(remove_if(events.begin(), events.end(), [dispatcher](const EventData& eData) -> bool{
		EventDispatcher* dsp = eData.dispatcher;
		return *dsp == *dispatcher;
	}), events.end());
}

void EventHeap::dispatch(EventDispatcher* dispatcher, EventType typeId)
{
	for (auto it = events.cbegin(); it != events.cend(); it++){
		EventDispatcher* dsp = (*it).dispatcher;
		int id = (*it).typeId;
		if(*dsp == *dispatcher && id == typeId){
			auto listener = (*it).listener;
			if(listener != nullptr)
				listener(dispatcher);
		}
	}		
}



