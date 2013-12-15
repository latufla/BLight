#pragma once
#include "ObjectBase.h"
#include "ViewBase.h"
#include <map>

using namespace std;

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
	void fire(I*);
	void unregisterObject(I*);
	
	map<I*, L*> recievers;
	map<I*, void (L::*)(I*)> listeners;

private:
	EventHeap() {};               
	EventHeap(EventHeap const&);              
	void operator=(EventHeap const&); 
};


