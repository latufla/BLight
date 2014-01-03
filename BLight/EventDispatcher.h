#pragma once
class EventDispatcher
{
public:
	EventDispatcher(void);
	EventDispatcher(int);
	~EventDispatcher(void);
	
	bool operator == (EventDispatcher); // not virtual, only for dispatchers cmp
	virtual int getId();

protected:
	int id;
};

