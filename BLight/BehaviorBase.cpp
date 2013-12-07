#include "BehaviorBase.h"
#include <ClanLib/core.h>


BehaviorBase::BehaviorBase(void)
{
	init(0, "dummy");
}

BehaviorBase::BehaviorBase( int id, string name)
{
	init(id, name);
}

BehaviorBase::~BehaviorBase(void)
{
	cout << "\n" + string(__FUNCTION__) + " " + string(*this);
}

void BehaviorBase::init( int id, string name )
{
	this->id = id;
	this->name = name;
	enabled = false;
}


bool BehaviorBase::start( ControllerBase* c)
{
	controller = c;
	enabled = true;

	return true;
}

bool BehaviorBase::stop()
{
	controller = nullptr;
	enabled = false;

	return true;
}

bool BehaviorBase::doStep( int stepInMSecs )
{
//	cout << "\n" + string(__FUNCTION__) + " " + this->name + " " + to_string((long long)stepInMSecs);
	clan::Console::write_line(string(__FUNCTION__) + " " + this->name + " " + to_string((long long)stepInMSecs));
	return true;
}

bool BehaviorBase::onInteraction( ObjectBase* obj1, ObjectBase* obj2)
{
	cout << "\n" + string(__FUNCTION__) + " " + obj1->getName() + ", " + obj2->getName();
	return true;
}


bool BehaviorBase::operator ==(BehaviorBase obj)
{
	return this->id == obj.getId()
		&& this->name == obj.getName()
		&& this->enabled == obj.getEnabled(); // doubtful
}

BehaviorBase::operator string()
{
	return string(typeid(*this).name()) + " id: " + to_string((long long)id)
		+ ", name: " + name 
		+ ", enabled: " + to_string((long long)enabled); 
}


int BehaviorBase::getId()
{
	return id;
}

std::string BehaviorBase::getName()
{
	return name;
}

void BehaviorBase::setId( int val )
{
	this->id = val;
}

void BehaviorBase::setName( string val )
{
	this->name = val;
}

ControllerBase* BehaviorBase::getController()
{
	return controller;
}

bool BehaviorBase::getEnabled()
{
	return enabled;
}
