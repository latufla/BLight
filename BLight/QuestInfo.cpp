#include "QuestInfo.h"


QuestInfo::QuestInfo(void)
{
}


QuestInfo::~QuestInfo(void)
{
	for (auto it = goals.cbegin(); it != goals.cend(); it++){
		delete (*it);
	}
	goals.clear();
}
