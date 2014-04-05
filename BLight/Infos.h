#pragma once
#include "stdafx.h"
#include "ObjectInfo.h"

class Infos
{
public:
	static void init();

	static ObjectInfo* getInfoBy(string);

private:
	static map<string, ObjectInfo*> nameToInfo;
};

