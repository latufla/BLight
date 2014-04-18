#pragma once
#include "stdafx.h"
#include <vector>
#include "ObjectInfo.h"
#include "yaml-cpp/yaml.h"
#include "MapInfo.h"
#include "QuestInfo.h"

using namespace YAML;

bool has(const Node& n, string name);

class YamlConnector
{
public:
	
	static YamlConnector& getInstance()
	{
		static YamlConnector instance;
		return instance;
	}

    vector<ObjectInfo*>* createInfos(string);
	vector<QuestInfo*>* createQuestInfos(string);
	MapInfo* createMap(string);

private:
	YamlConnector(void) {};               
	YamlConnector(YamlConnector const&);              
	void operator=(YamlConnector const&);

	CustomShape* createShape(const Node&);
	Info* createBehaviorInfo(const Node&);
	CommandType createCommandType(const Node&);
	DropInfo* createDropInfo(const Node&);
};


template<typename T> bool is(const Node& n){
	try{
		T val;
		n >> val;
		return true;
	}catch(const InvalidScalar& e){e;}

	return false;
}

template<typename T> bool is(const Node& n, string name){
	const Node* vNode = n.FindValue(name);
	if(vNode == nullptr)
		return false;
	
	try{
		T val;
		*vNode >> val;
		return true;
	}
	catch(const InvalidScalar& e){e;}

	return false;
}

template<typename T> T get(const Node& n){
	T val;
	n >> val;
	return val;
}
