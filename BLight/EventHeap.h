#pragma once
#include "ObjectBase.h"
#include "ViewBase.h"
#include "ClanLib\Core\Signals\signal_v1.h"

using namespace std;
using namespace clan;

class EventHeap
{
public:
	EventHeap(void);
	~EventHeap(void);

	static void registerObject(ObjectBase*, ViewBase*);
	static void fire(ObjectBase*);
	static void unregisterObject(ObjectBase*);
	
	static SlotContainer slots;
	static map<ObjectBase*, clan::Signal_v1<ObjectBase*>> signals;

private:
};
