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
	
	vector<ObjectInfo*>* createInfosFromJson(FILE*);
	vector<ControllerBase*>* createMapFromJson(FILE*);

private:
	JsonConnector(void) {};               
	JsonConnector(JsonConnector const&);              
	void operator=(JsonConnector const&);

	CustomShape* createShape(rapidjson::Value&);
	Info* createBehaviorInfo(rapidjson::Value&);
	CommandType createCommandType(rapidjson::Value&);
	DropInfo* createDropInfo(rapidjson::Value&);
};

