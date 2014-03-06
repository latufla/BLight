#include "ObjectBase.h"
#include "PhEngineConnector.h"
#include "EngineConnector.h"

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
	delete shape;
}

void ObjectBase::init( int id, string name )
{
	this->id = id;
	this->name = name;
	energy = 20;
}

ObjectBase::operator string()
{
	return string(typeid(*this).name()) + " id: " + to_string((long long)id) + ", "
		+ "name:" + name; 
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

CustomPoint& ObjectBase::getPosition()
{
	PhEngineConnector::getInstance().getPosition(this, position);
	return position;
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

void ObjectBase::applyLinearImpulse( const CustomPoint& impulse )
{
	PhEngineConnector::getInstance().applyLinearImpulse(this, impulse);
}

void ObjectBase::setLinearDamping( float damping )
{
	PhEngineConnector::getInstance().setLinearDamping(this, damping);
}

CustomPoint& ObjectBase::getGlobalCenter()
{
	PhEngineConnector::getInstance().getGlobalCenter(this, globalCenter);
	return globalCenter;
}

void ObjectBase::applyForce(const CustomPoint& force)
{
	PhEngineConnector::getInstance().applyForce(this, force);
}

void ObjectBase::setLinearVelocity(const CustomPoint& vel)
{
	PhEngineConnector::getInstance().setLinearVelocity(this, vel);
}

void ObjectBase::setSensor(bool val)
{
	PhEngineConnector::getInstance().setSensor(this, val);
}
