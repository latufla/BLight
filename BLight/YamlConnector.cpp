#include "YamlConnector.h"
#include <fstream>
#include "BehaviorsFactory.h"
#include "CommandsFactory.h"
#include "MapInfo.h"
#include "CustomCircle.h"
#include "CustomPolygon.h"

bool has(const Node& n, string name){
	return n.FindValue(name) != nullptr; 
}

vector<ObjectInfo*>* YamlConnector::createInfos(string path)
{
	ifstream stream;
	stream.open(path);
	if (!stream.is_open())	
		return nullptr;
	
	vector<ObjectInfo*>* res = new vector<ObjectInfo*>();
	Parser parser(stream);
	Node doc;
	if(!parser.GetNextDocument(doc))
		return nullptr;

	for(auto it=doc.begin(); it != doc.end(); ++it) {
		ObjectInfo* info = new ObjectInfo();
		
		it.first() >> info->name;

		const Node& item = it.second();
		info->id = get<int>(item["id"]);
		info->physicType = get<int>(item["physicType"]);

		info->shape = createShape(item["shape"]);

		info->density = is<float>(item, "density") ? get<float>(item["density"]) : 0.0f; 
		info->friction = is<float>(item, "friction") ? get<float>(item["friction"]) : 0.0f; 
		info->restitution = is<float>(item, "restitution") ? get<float>(item["restitution"]) : 0.0f; 
		info->linearDamping = is<float>(item, "linearDamping") ? get<float>(item["linearDamping"]) : 0.0f; 
		info->displayStatus = is<bool>(item, "displayStatus") ? get<bool>(item["displayStatus"]) : false; 
		
		const Node* behaviors = item.FindValue("behaviors");
		if(behaviors != nullptr && behaviors->Type() == NodeType::Sequence){
			for(auto it = behaviors->begin(); it != behaviors->end(); ++it){
				info->behaviors.push_back(createBehaviorInfo(*it));
			}
		}

		const Node* applicableCommands = item.FindValue("applicableCommands");
		if(applicableCommands != nullptr && applicableCommands->Type() == NodeType::Sequence){
			for(auto it = applicableCommands->begin(); it != applicableCommands->end(); ++it){
				const Node* commanders = it->FindValue("commanders");
				if(commanders == nullptr || commanders->Type() != NodeType::Sequence)
					continue;

				CommandType command = createCommandType(*it);				
				for(auto st = commanders->begin(); st != commanders->end(); ++st){
					info->applicableCommands[command].push_back(get<string>(*st));
				}
			}
		}

		const Node* drop = item.FindValue("drop");
		if(drop != nullptr && drop->Type() == NodeType::Sequence){
			for(auto it = drop->begin(); it != drop->end(); ++it){
				info->drop[createCommandType(*it)] = createDropInfo(*it);
			}
		}
		res->push_back(info);
	}

	stream.close();
	return res;
}

CustomShape* YamlConnector::createShape(const Node& shape)
{
	CustomShape* res = nullptr;

	string sName = get<string>(shape["name"]);
	if(sName == "circle"){
		res  = new CustomCircle(CustomPoint(0.0f, 0.0f), get<float>(shape["radius"]));
	}else if(sName == "polygon"){
		float width = get<float>(shape["width"]);
		float height = get<float>(shape["height"]);
		res = new CustomPolygon(width, height);
	}
	return res;
}

Info* YamlConnector::createBehaviorInfo(const Node& b)
{
	Info* bInfo = BehaviorsFactory::createInfo(get<string>(b["name"]));
	for(auto it = b.begin(); it != b.end(); ++it){		
		string pName;
		it.first() >> pName;
		const Node& val = it.second();
		if(is<int>(val))
			bInfo->update(pName, get<int>(val));
		if(is<float>(val))
			bInfo->update(pName, get<float>(val));
		if(is<string>(val))
			bInfo->update(pName, get<string>(val));
	}
	return bInfo;
}

CommandType YamlConnector::createCommandType(const Node& n)
{
	if(!is<string>(n, "name"))	
		return NONE_COMMAND;

	return CommandsFactory::getType(get<string>(n["name"]));
}

DropInfo* YamlConnector::createDropInfo(const Node& d)
{
	DropInfo* info = new DropInfo();
	
	string caller = DropInfo::CALLER;
	string target = DropInfo::TARGET;
	string player = DropInfo::PLAYER;
	string energy = DropInfo::ENERGY;
	string xp = DropInfo::XP;
	
	if(has(d, caller)){
		if(is<int>(d[caller], energy))
			info->caller[energy] = get<int>(d[caller][energy]);
		
		if(is<int>(d[caller], xp))
			info->caller[xp] = get<int>(d[caller][xp]);
	}

	if(has(d, target)){
		if(is<int>(d[target], energy))
			info->target[energy] = get<int>(d[target][energy]);

		if(is<int>(d[target], xp))
			info->target[xp] = get<int>(d[target][xp]);
	}

	if(has(d, player)){
		if(is<int>(d[player], energy))
			info->player[energy] = get<int>(d[player][energy]);

		if(is<int>(d[player], xp))
			info->player[xp] = get<int>(d[player][xp]);
	}

	return info;
}

MapInfo* YamlConnector::createMap(string path)
{
	ifstream stream;
	stream.open(path);
	if (!stream.is_open())	
		return nullptr;

	Parser parser(stream);
	Node doc;
	if(!parser.GetNextDocument(doc) || doc.Type() != NodeType::Sequence)
		return nullptr;
	
	MapInfo* mapInfo = new MapInfo();
	for(auto it = doc.begin(); it != doc.end(); ++it){
		string name = get<string>((*it)["name"]);
		int id = get<int>((*it)["id"]);
		CustomPoint pos(get<float>((*it)["x"]), get<float>((*it)["y"]));
		mapInfo->infoNameToData[name] = pair<int, CustomPoint>(id, pos);
	}
	stream.close();
	return mapInfo;
}

vector<QuestInfo*>* YamlConnector::createQuestInfos(string path)
{
	ifstream stream;
	stream.open(path);
	if (!stream.is_open())	
		return nullptr;

	Parser parser(stream);
	Node doc;
	if(!parser.GetNextDocument(doc))
		return nullptr;

	vector<QuestInfo*>* quests = new vector<QuestInfo*>();
	for(auto it = doc.begin(); it != doc.end(); ++it){
		QuestInfo* info = new QuestInfo();
		it.first() >> info->name;

		const Node& item = it.second();
		info->id = get<int>(item["id"]);	

		const Node& goals = item["goals"];
		for(auto qt = goals.begin(); qt != goals.end(); ++qt){
			QuestGoalInfo* goalInfo = new QuestGoalInfo();
			goalInfo->command = get<string>((*qt)["command"]);  
			goalInfo->target = get<string>((*qt)["target"]);  
			goalInfo->count = get<unsigned int>((*qt)["count"]);  
			info->goals.push_back(goalInfo);
		}		
		quests->push_back(info);
	}
	return quests;
}
