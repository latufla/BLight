#include "JsonConnector.h"
#include "CustomCircle.h"
#include "BehaviorsFactory.h"
#include "CommandsFactory.h"

ObjectInfo* JsonConnector::createInfoFromJson(FILE* file)
{
	if(file == nullptr)
		return nullptr;
	
	rapidjson::FileStream is(file);
	rapidjson::Document d;
	if(d.ParseStream<0>(is).HasParseError())
		return nullptr;

	ObjectInfo* info = new ObjectInfo();
	rapidjson::Value& items = d["items"];
	if(!items.IsArray())
		return nullptr;

	rapidjson::SizeType id = 0;
	rapidjson::Value& item = items[id];
	if(!item.IsObject())
		return nullptr;

	info->id = item["id"].GetInt();
	info->name = item["name"].GetString();
	info->physicType = item["physicType"].GetInt();

	info->shape = new CustomCircle(CustomPoint(0.0f, 0.0f), (float)item["shape"]["radius"].GetDouble());

	info->density = (float)item["density"].GetDouble();
	info->friction = (float)item["friction"].GetDouble();
	info->restitution = (float)item["restitution"].GetDouble();
	info->linearDamping = (float)item["linearDamping"].GetDouble();
	
	rapidjson::Value& behaviors = item["behaviors"];
	if(behaviors.IsArray()){
		for (rapidjson::SizeType i = 0; i < behaviors.Size(); i++)
			info->behaviors.push_back(createBehaviorBy(behaviors[i]));
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
	
	return info;
}

BehaviorBase* JsonConnector::createBehaviorBy(rapidjson::Value& b)
{
	if(!b.IsObject())
		return nullptr;

	return BehaviorsFactory::create(b["name"].GetString());
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



