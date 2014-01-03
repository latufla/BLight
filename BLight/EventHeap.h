#pragma once
#include <map>
#include <vector>
#include <functional>
#include "ObjectBase.h"

using namespace std;

enum EventType{DEFAULT, CHANGE};

class EventData
{
public:
	EventType typeId;
	ObjectBase* dispatcher;
	void* receiver;
	function<void(ObjectBase*)> listener;
};

class EventHeap
{
public:

	static EventHeap& getInstance()
	{
		static EventHeap instance;
		return instance;
	}

	void addEventListener(ObjectBase*, void*, function<void(ObjectBase*)>, EventType = CHANGE);
	void removeEventListener(ObjectBase*);

	void dispatch(ObjectBase*, EventType = CHANGE);	

private:
	EventHeap() {};               
	EventHeap(EventHeap const&);              
	void operator=(EventHeap const&);

	vector<EventData> events;
};


