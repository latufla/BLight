#pragma once
#include "ObjectBase.h"
#include <vector>
class Field
{
public:
	Field(void);
	~Field(void);

	ObjectBase* createObject(int, string, int, pair<float, float>);

protected:
	vector<ObjectBase*> objects; 
};

