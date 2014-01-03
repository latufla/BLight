#include "ObjectBase.h"
#include "EventHeap.h"

ObjectBase::ObjectBase(void)
{
	init(0, "dummy");
}

ObjectBase::ObjectBase( int id, string name)
{	
	init(id, name);
}

ObjectBase::~ObjectBase(void)
{

}

void ObjectBase::init( int id, string name )
{
	this->id = id;
	this->name = name;
}


bool ObjectBase::fireUpdates()
{
	EventHeap::getInstance().dispatch(this, CHANGE);
	return true;
}


bool ObjectBase::operator == (ObjectBase obj)
{
	return this->id == obj.getId() && this->name == obj.getName();
}

ObjectBase::operator string()
{
	return string(typeid(*this).name()) + " id: " + to_string((long long)id) + ", "
		+ "name:" + name; 
}


int ObjectBase::getId()
{
	return id;
}

std::string ObjectBase::getName()
{
	return name;
}

void ObjectBase::setId( int val )
{
	this->id = val;
}

void ObjectBase::setName( string val )
{
	this->name = val;
}



