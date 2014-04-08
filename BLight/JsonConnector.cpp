#include "JsonConnector.h"
#include "CustomCircle.h"
#include "BehaviorsFactory.h"
#include "CommandsFactory.h"
#include "SpawnerBehaviorInfo.h"
#include "Config.h"
#include "Infos.h"
#include "MapInfo.h"

vector<ObjectInfo*>* JsonConnector::createInfosFromJson(FILE* json)
{
	if(json == nullptr)
		return nullptr;
	
	rapidjson::FileStream is(json);
	rapidjson::Document d;
	if(d.ParseStream<0>(is).HasParseError())
		return nullptr;

	rapidjson::Value& items = d["items"];
	if(!items.IsArray())
		return nullptr;

	vector<ObjectInfo*>* res = new vector<ObjectInfo*>();
	for (rapidjson::SizeType j = 0; j < items.Size(); j++){	
		
		ObjectInfo* info = new ObjectInfo();
		res->push_back(info);

		rapidjson::Value& item = items[j];
		if(!item.IsObject())
			return nullptr;

		info->id = item["id"].GetInt();
		info->name = item["name"].GetString();
		info->physicType = item.HasMember("physicType") ? item["physicType"].GetInt() : 0;

		info->shape = createShape(item["shape"]);
		
		info->density = item.HasMember("density") ? (float)item["density"].GetDouble() : 0.0f;
		info->friction = item.HasMember("friction") ? (float)item["friction"].GetDouble() : 0.0f;
		info->restitution = item.HasMember("restitution") ? (float)item["restitution"].GetDouble() : 0.0f;
		info->linearDamping = item.HasMember("linearDamping") ? (float)item["linearDamping"].GetDouble() : 0.0f;
	
		info->displayStatus = item.HasMember("displayStatus") ? item["displayStatus"].GetBool() : false; 

		rapidjson::Value& behaviors = item["behaviors"];
		if(behaviors.IsArray()){
			for (rapidjson::SizeType i = 0; i < behaviors.Size(); i++)
				info->behaviors.push_back(createBehaviorInfo(behaviors[i]));
		}

		rapidjson::Value& applicableCommands = item["applicableCommands"];
		if(applicableCommands.IsArray()){
			for (rapidjson::SizeType i = 0; i < applicableCommands.Size(); i++)
				info->applicableCommands.push_back(createCommandType(applicableCommands[i]));
		}

		rapidjson::Value& drop = item["drop"];
		if(drop.IsArray()){
			for (rapidjson::SizeType i = 0; i < drop.Size(); i++){
				info->drop[createCommandType(drop[i])] = createDropInfo(drop[i]);
			}
		}
	}

	return res;
}

CustomShape* JsonConnector::createShape(rapidjson::Value& s){
	CustomShape* res = nullptr;
	string sName = s["name"].GetString();
	if(sName == "circle"){
		res = new CustomCircle(CustomPoint(0.0f, 0.0f), (float)s["radius"].GetDouble());
	} else if(sName == "polygon"){
		res = new CustomPolygon((float)s["width"].GetDouble(), (float)s["height"].GetDouble());
	}
	return res;
}

Info* JsonConnector::createBehaviorInfo( rapidjson::Value& b)
{
	if(!b.IsObject())
		return nullptr;

	Info* bInfo = BehaviorsFactory::createInfo(b["name"].GetString());
	if(b.IsObject()){
		for(auto it = b.MemberBegin(); it != b.MemberEnd(); ++it){
			string pName = it->name.GetString();
			rapidjson::Value& val = it->value;
			if(val.IsInt())
				bInfo->update(pName, val.GetInt());
			else if(val.IsString())
				bInfo->update(pName, val.GetString());
			else if(val.IsDouble())
				bInfo->update(pName, (float)val.GetDouble());
		}
	}
	return bInfo;
}


CommandType JsonConnector::createCommandType(rapidjson::Value& c)
{
	if(!c.IsObject())
		return NONE_COMMAND;
	
	return CommandsFactory::getType(c["name"].GetString());
}

DropInfo* JsonConnector::createDropInfo(rapidjson::Value& d)
{
	if(!d.IsObject())
		return nullptr;

	DropInfo* info = new DropInfo();
	if(d.HasMember("caller")){
		if(d["caller"].HasMember("energy"))
			info->caller[DropInfo::ENERGY] = d["caller"]["energy"].GetInt();
	
		if(d["caller"].HasMember("xp"))
			info->caller[DropInfo::XP] = d["caller"]["xp"].GetInt();
	}
	
	if(d.HasMember("target")){
		if(d["target"].HasMember("energy"))
			info->target[DropInfo::ENERGY] = d["target"]["energy"].GetInt();

		if(d["target"].HasMember("xp"))
			info->target[DropInfo::XP] = d["target"]["xp"].GetInt();
	}

	return info;
}

MapInfo* JsonConnector::createMapFromJson(FILE* json)
{
	if(json == nullptr)
		return nullptr;

	rapidjson::FileStream is(json);
	rapidjson::Document d;
	if(d.ParseStream<0>(is).HasParseError())
		return nullptr;

	rapidjson::Value& items = d["items"];
	if(!items.IsArray())
		return nullptr;

	MapInfo* mapInfo = new MapInfo();
	for (rapidjson::SizeType i = 0; i < items.Size(); i++){
		string name = items[i]["name"].GetString();		
		int id = items[i]["id"].GetInt();
		CustomPoint pos(
			(float)items[i]["x"].GetDouble(), 
			(float)items[i]["y"].GetDouble()
			);
		mapInfo->infoNameToData[name] = pair<int, CustomPoint>(id, pos);	
	}
	return mapInfo;
}


