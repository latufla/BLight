#include "PopupManager.h"

void PopupManager::add(PopupText* p)
{
	popUps.push_back(p);
	SceneController::getInstance().addChild(p);
}

bool PopupManager::doStep(int step)
{
	popUps.erase(remove_if(popUps.begin(), popUps.end(), [](PopupText* p) -> bool{
		bool res = p->getToDestroy();

		if(res){
			SceneController::getInstance().removeChild(p);
			delete p;
		}
		
		return res;
	}), popUps.end());

	return true;
}
