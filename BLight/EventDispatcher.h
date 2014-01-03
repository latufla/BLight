#pragma once
class EventDispatcher
{
public:
	EventDispatcher(void);
	EventDispatcher(int id);
	~EventDispatcher(void);
	
	bool operator == (EventDispatcher); // not virtual, only for dispatchers cmp
	virtual int getId();

protected:
	int id;
};

