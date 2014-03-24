#include "Field.h"
#include "ObjectBase.h"
#include "Config.h"


Field::Field(void)
{
	Config::phEngine->init(this);
}


Field::~Field(void)
{
}

ObjectBase* Field::createObject(int id, string name, int oType, const CustomPoint& pos )
{
	ObjectBase* obj = new ObjectBase(id, name); 
	Config::phEngine->createBody(obj, oType, pos);
	return obj;
}

void Field::destroyObject(ObjectBase* obj)
{
	Config::phEngine->destroyBody(obj);
}


