#pragma once
#include "ObjectBase.h"
#include "ViewBase.h"
#include "ClanLib\Core\Signals\signal_v1.h"
#include "ClanLib\Core\Signals\slot_container.h"
#include <map>

using namespace std;
using namespace clan;

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
	
	SlotContainer slots;
	map<I*, clan::Signal_v1<I*>> signals;

private:
	EventHeap() {};               
	EventHeap(EventHeap const&);              
	void operator=(EventHeap const&); 
};


