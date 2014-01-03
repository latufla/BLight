#include "EventHeap.h"

void EventHeap::addEventListener(ObjectBase* dispatcher, void* receiver, function<void(ObjectBase*)> listener, EventType typeId)
{	
	EventData eData;
	eData.typeId = typeId;
	eData.dispatcher = dispatcher;
	eData.receiver = receiver;
	eData.listener = listener;
	events.push_back(eData);
}

void EventHeap::removeEventListener(ObjectBase* dispatcher)
{
	events.erase(remove_if(events.begin(), events.end(), [dispatcher](const EventData& eData) -> bool{
		ObjectBase* dsp = eData.dispatcher;
		return *dsp == *dispatcher;
	}), events.end());
}

void EventHeap::dispatch(ObjectBase* dispatcher, EventType typeId)
{
	for (auto it = events.cbegin(); it != events.cend(); it++){
		ObjectBase* dsp = (*it).dispatcher;
		int id = (*it).typeId;
		if(*dsp == *dispatcher && id == typeId){
			auto listener = (*it).listener;
			if(listener != nullptr)
				listener(dispatcher);
		}
	}		
}



