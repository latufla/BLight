#pragma once
#include "ObjectBase.h"
#include <vector>
class Field
{
public:
	Field(void);
	~Field(void);

	ObjectBase* createObject(int, string, int, const CustomPoint&);

protected:
	vector<ObjectBase*> objects; 
};

