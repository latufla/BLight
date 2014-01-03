#pragma once
#include "stdafx.h"

enum EventType{DEFAULT, CHANGE};

template<class D,class R>
class CustomEvent
{
public:
	CustomEvent(void);
	CustomEvent(EventType, D*, R*, void (R::*listener)(D*));
	~CustomEvent(void);

	EventType typeId;
	D* dispatcher;
	R* receiver;
	void (R::*listener)(D*);

	bool dispatch();
};

template<class D,class R>
CustomEvent<D, R>::CustomEvent( void )
{

}

template<class D,class R>
CustomEvent<D, R>::CustomEvent( EventType, D*, R*, void (R::*listener)(D*) )
{
	typeId = eType;
	this->dispatcher = dispatcher;
	this->receiver = receiver;
	this->listener = listener;
}

template<class D, class R>
CustomEvent<D, R>::~CustomEvent( void )
{

}

template<class D,class R>
bool CustomEvent<D, R>::dispatch()
{
	if(dispatcher == nullptr || receiver == nullptr || listener == nullptr)
		return false;

	(reciever->*listener)(dispatcher);
	return true;
}


