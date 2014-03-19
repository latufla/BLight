#pragma once
#include "stdafx.h"
#include "rapidjson\rapidjson.h"
#include "rapidjson\document.h"
#include "rapidjson\filestream.h"
#include "ObjectInfo.h"

class JsonConnector
{
public:
	static JsonConnector& getInstance()
	{
		static JsonConnector instance;
		return instance;
	}
	
	ObjectInfo* createInfoFromJson(FILE*);
	
private:
	JsonConnector(void) {};               
	JsonConnector(JsonConnector const&);              
	void operator=(JsonConnector const&);

};

