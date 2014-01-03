#pragma once
#include <map>
#include <vector>
#include <functional>

using namespace std;

enum EventType{DEFAULT, CHANGE};

template<class D,class R>
class EventData
{
public:
	EventType typeId;
	D* dispatcher;
	R* receiver;
	std::function<void(void*, void*)> listener;
};

template<class D, class R> // Dispatcher, Receiver
class EventHeap
{
public:

	static EventHeap& getInstance()
	{
		static EventHeap instance;
		return instance;
	}

	void addEventListener(D*, R*, std::function<void(void*, void*)>, EventType = CHANGE);
	void removeEventListener(D*);

	void dispatch(D*, EventType = CHANGE);	

private:
	EventHeap() {};               
	EventHeap(EventHeap const&);              
	void operator=(EventHeap const&);

	vector<EventData<D, R>> events;
};


