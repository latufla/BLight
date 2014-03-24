#include "ObjectBase.h"
#include "Config.h"

int ObjectBase::count = 0;

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
	count--;
	delete shape;
}

void ObjectBase::init( int id, string name )
{
	this->id = id;
	this->name = name;
	energy = 20;

	count++;
}

ObjectBase::operator string()
{
	return string(typeid(*this).name()) + " id: " + to_string((long long)id) + ", "
		+ "name:" + name; 
}


void ObjectBase::setDensity(float d)
{
	Config::phEngine->setDensity(this, d);
}

void ObjectBase::setFriction(float f)
{
	Config::phEngine->setFriction(this, f);
}

void ObjectBase::setRestitution(float r)
{
	Config::phEngine->setResitution(this, r);
}

CustomPoint& ObjectBase::getPosition()
{
	Config::phEngine->getPosition(this, position);
	return position;
}

float ObjectBase::getRotation()
{
	return Config::phEngine->getRotation(this);
}


void ObjectBase::setShape(CustomShape* val)
{
	this->shape = val;
	if(CustomShape::isPolygon(shape))
		Config::phEngine->setShape(this, (CustomPolygon*)shape);
	else if(CustomShape::isCircle(shape))
		Config::phEngine->setShape(this, (CustomCircle*)shape);
}

CustomShape* ObjectBase::getShape()
{
	if(CustomShape::isPolygon(shape))
		return Config::phEngine->getShape(this, (CustomPolygon*)shape);
	else if(CustomShape::isCircle(shape))
		return Config::phEngine->getShape(this, (CustomCircle*)shape);

	return nullptr;
}

void ObjectBase::applyLinearImpulse( const CustomPoint& impulse )
{
	Config::phEngine->applyLinearImpulse(this, impulse);
}

void ObjectBase::setLinearDamping( float damping )
{
	Config::phEngine->setLinearDamping(this, damping);
}

CustomPoint& ObjectBase::getGlobalCenter()
{
	Config::phEngine->getGlobalCenter(this, globalCenter);
	return globalCenter;
}

void ObjectBase::applyForce(const CustomPoint& force)
{
	Config::phEngine->applyForce(this, force);
}

void ObjectBase::setLinearVelocity(const CustomPoint& vel)
{
	Config::phEngine->setLinearVelocity(this, vel);
}

void ObjectBase::setSensor(bool val)
{
	Config::phEngine->setSensor(this, val);
}

bool ObjectBase::contains(const CustomPoint& p)
{
	return Config::phEngine->contains(this, p);
}
