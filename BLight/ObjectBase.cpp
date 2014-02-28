#include "ObjectBase.h"
#include "EventHeap.h"
#include "PhEngineConnector.h"

ObjectBase::ObjectBase(void)
{
	init(0, "dummy");
}

ObjectBase::ObjectBase(int id, string name) : EventDispatcher(id)
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
	energy = 20;
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


void ObjectBase::setDensity(float d)
{
	PhEngineConnector::getInstance().setDensity(this, d);
}

void ObjectBase::setFriction(float f)
{
	PhEngineConnector::getInstance().setFriction(this, f);
}

void ObjectBase::setRestitution(float r)
{
	PhEngineConnector::getInstance().setResitution(this, r);
}

CustomPoint ObjectBase::getPosition()
{
	return PhEngineConnector::getInstance().getPosition(this);
}

float ObjectBase::getRotation()
{
	return PhEngineConnector::getInstance().getRotation(this);
}


void ObjectBase::setShape(CustomShape* val)
{
	this->shape = val;
	if(CustomShape::isPolygon(shape))
		PhEngineConnector::getInstance().setShape(this, (CustomPolygon*)shape);
	else if(CustomShape::isCircle(shape))
		PhEngineConnector::getInstance().setShape(this, (CustomCircle*)shape);
}

CustomShape* ObjectBase::getShape()
{
	if(CustomShape::isPolygon(shape))
		return PhEngineConnector::getInstance().getShape(this, (CustomPolygon*)shape);
	else if(CustomShape::isCircle(shape))
		return PhEngineConnector::getInstance().getShape(this, (CustomCircle*)shape);

	return nullptr;
}

void ObjectBase::applyLinearImpulse( CustomPoint* impulse )
{
	PhEngineConnector::getInstance().applyLinearImpulse(this, impulse);
}

void ObjectBase::setLinearDamping( float damping )
{
	PhEngineConnector::getInstance().setLinearDamping(this, damping);
}

CustomPoint ObjectBase::getGlobalCenter()
{
	return PhEngineConnector::getInstance().getGlobalCenter(this);
}

void ObjectBase::applyForce( CustomPoint* force)
{
	PhEngineConnector::getInstance().applyForce(this, force);
}

void ObjectBase::setLinearVelocity( CustomPoint* vel)
{
	PhEngineConnector::getInstance().setLinearVelocity(this, vel);
}

int ObjectBase::getEnergy()
{
	return energy;
}

void ObjectBase::setEnergy(int step)
{
	energy = step;
}
