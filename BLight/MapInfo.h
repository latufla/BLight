#pragma once
#include "stdafx.h"
#include "CustomPoint.h"
#include <map>
#include "ObjectInfo.h"

class MapInfo : public Info
{
public:
	MapInfo(void);
	~MapInfo(void);

	map<string, pair<int, CustomPoint>> infoNameToData;
};

