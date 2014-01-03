#pragma once
#include <vector>
#include <functional>
#include <algorithm>

#include "EventDispatcher.h"

using namespace std;

enum EventType{DEFAULT, CHANGE};

class EventData
{
public:
	EventType typeId;
	EventDispatcher* dispatcher;
	void* receiver;
	function<void(EventDispatcher*)> listener;
};

class EventHeap
{
public:

	static EventHeap& getInstance()
	{
		static EventHeap instance;
		return instance;
	}

	void addEventListener(EventDispatcher*, void*, function<void(EventDispatcher*)>, EventType = CHANGE);
	void removeEventListener(EventDispatcher*);

	void dispatch(EventDispatcher*, EventType = CHANGE);	

private:
	EventHeap() {};               
	EventHeap(EventHeap const&);              
	void operator=(EventHeap const&);

	vector<EventData> events;
};


