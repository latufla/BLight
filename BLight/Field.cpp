#include "Field.h"
#include "PhEngineConnector.h"
#include "ObjectBase.h"


Field::Field(void)
{
	PhEngineConnector::getInstance().init(this);
}


Field::~Field(void)
{
}

ObjectBase* Field::createObject(int id, string name, int oType, const CustomPoint& pos )
{
	ObjectBase* obj = new ObjectBase(id, name); 
	PhEngineConnector::getInstance().createBody(obj, oType, pos);
	return obj;
}

void Field::destroyObject(ObjectBase* obj)
{
	PhEngineConnector::getInstance().destroyBody(obj);
	delete obj;
}


