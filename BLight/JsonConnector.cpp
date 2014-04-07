#include "JsonConnector.h"
#include "CustomCircle.h"
#include "BehaviorsFactory.h"
#include "CommandsFactory.h"
#include "SpawnerBehaviorInfo.h"
#include "Config.h"

vector<ObjectInfo*>* JsonConnector::createInfosFromJson(FILE* file)
{
	if(file == nullptr)
		return nullptr;
	
	rapidjson::FileStream is(file);
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
		info->physicType = item["physicType"].GetInt();

		info->shape = createShapeBy(item["shape"]);
		
		info->density = (float)item["density"].GetDouble();
		info->friction = (float)item["friction"].GetDouble();
		info->restitution = (float)item["restitution"].GetDouble();
		info->linearDamping = (float)item["linearDamping"].GetDouble();
	
		rapidjson::Value& behaviors = item["behaviors"];
		if(behaviors.IsArray()){
			for (rapidjson::SizeType i = 0; i < behaviors.Size(); i++)
				info->behaviors.push_back(createBehaviorInfoBy(behaviors[i]));
		}

		rapidjson::Value& applicableCommands = item["applicableCommands"];
		if(applicableCommands.IsArray()){
			for (rapidjson::SizeType i = 0; i < applicableCommands.Size(); i++)
				info->applicableCommands.push_back(createCommandTypeBy(applicableCommands[i]));
		}

		rapidjson::Value& drop = item["drop"];
		if(drop.IsArray()){
			for (rapidjson::SizeType i = 0; i < drop.Size(); i++){
				info->drop[createCommandTypeBy(drop[i])] = createDropInfoBy(drop[i]);
			}
		}
	}

	return res;
}

CustomShape* JsonConnector::createShapeBy(rapidjson::Value& s){
	CustomShape* res = nullptr;
	string sName = s["name"].GetString();
	if(sName == "circle"){
		res = new CustomCircle(CustomPoint(0.0f, 0.0f), (float)s["radius"].GetDouble());
	} else if(sName == "polygon"){
		res = new CustomPolygon((float)s["width"].GetDouble(), (float)s["height"].GetDouble());
	}
	return res;
}

Info* JsonConnector::createBehaviorInfoBy( rapidjson::Value& b)
{
	if(!b.IsObject())
		return nullptr;

	Info* bInfo = BehaviorsFactory::createInfo(b["name"].GetString());
	
	if(bInfo->name == "SpawnerBehavior"){
		((SpawnerBehaviorInfo*)bInfo)->intervalMSec = b["intervalMSec"].GetInt();
		((SpawnerBehaviorInfo*)bInfo)->chance= b["chance"].GetInt();
		((SpawnerBehaviorInfo*)bInfo)->creature = b["creature"].GetString();
	}

	return bInfo;
}

CommandType JsonConnector::createCommandTypeBy(rapidjson::Value& c)
{
	if(!c.IsObject())
		return NONE_COMMAND;
	
	return CommandsFactory::getType(c["name"].GetString());
}

DropInfo* JsonConnector::createDropInfoBy(rapidjson::Value& d)
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


