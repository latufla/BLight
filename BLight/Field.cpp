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

ObjectBase* Field::createObject(int id, string name, int oType, pair<float, float> pos )
{
	ObjectBase* obj = new ObjectBase(id, name); 
	objects.push_back(obj);
	PhEngineConnector::getInstance().createBody(obj, oType, pos);
	return obj;
}
