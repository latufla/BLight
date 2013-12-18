#pragma once
#include "ObjectBase.h"
#include "ViewBase.h"
#include <map>

using namespace std;

enum EventType{DEFAULT, CHANGE};

template<class I,class L>
class EventData
{
public:
	EventType typeId;
	I* invoker;
	L* reciever;
	void (L::*listener)(I*);
};

template<class I, class L> // Invoker, Listener
class EventHeap
{
public:

	static EventHeap& getInstance()
	{
		static EventHeap instance;
		return instance;
	}

	void registerObject(I*, L*, void (L::*listen)(I*), EventType = CHANGE);
	void fire(I*, EventType = CHANGE);
	void unregisterObject(I*);
	
	vector<EventData<I, L>> events;

private:
	EventHeap() {};               
	EventHeap(EventHeap const&);              
	void operator=(EventHeap const&);
};


