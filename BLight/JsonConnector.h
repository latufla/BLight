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
	
private:
	JsonConnector(void) {};               
	JsonConnector(JsonConnector const&);              
	void operator=(JsonConnector const&);

	Info* createBehaviorInfoBy(rapidjson::Value&);
	CommandType createCommandTypeBy(rapidjson::Value&);
	DropInfo* createDropInfoBy(rapidjson::Value&);
};

