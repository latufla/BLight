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

	void registerObject(I*, L*, void (L::*listen)(I*));
	void fire(I*, EventType = DEFAULT);
	void unregisterObject(I*);
	
	vector<EventData<I, L>> events;

	map<I*, L*> recievers;
	map<I*, void (L::*)(I*)> listeners;

private:
	EventHeap() {};               
	EventHeap(EventHeap const&);              
	void operator=(EventHeap const&);
};


