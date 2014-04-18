#include "QuestManager.h"
#include "CommandsFactory.h"
#include "EngineConnector.h"


bool QuestManager::doStep(int step)
{
	for(auto it = quests.cbegin(); it != quests.cend(); ++it){
		for(auto st = targetToCommand.cbegin(); st != targetToCommand.cend(); ++st){
			for(auto qt = st->second.cbegin(); qt != st->second.cend(); ++qt){
				(*it)->notify(qt->first, st->first, qt->second);
				
				if((*it)->completed())
					completedQuests.push_back(*it);
			}
		}
	}

	for(auto it = completedQuests.cbegin(); it != completedQuests.cend(); ++it){
		auto cQuestIt = find(quests.begin(), quests.end(), *it);
		if(cQuestIt != quests.end()){
			quests.erase(cQuestIt);
			EngineConnector::getInstance().printDebug("" + (*it)->getName() + " completed");		
		}		
	}
	
	targetToCommand.clear(); // TODO: wonder 
	return true;
}

bool QuestManager::notify(CommandType command, string target)
{
	targetToCommand[target][command]++;
	return true;
}

bool QuestManager::add(QuestBase* quest)
{
	quests.push_back(quest);
	return true;
}
