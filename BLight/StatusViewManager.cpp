#include "StatusViewManager.h"

void StatusViewManager::addStatusView(ControllerBase* c)
{
	TextBase* p = new TextBase();
	p->setText(c->getName() + to_string(long long(c->getObject()->getEnergy())));
	p->setCharacterSize(14);
	p->getPosition().set(c->getObject()->getGlobalCenter());
	SceneController::getInstance().addChild(p);
	controllerToStatusView[c] = p;
}

bool StatusViewManager::doStep(int step)
{
	for(auto it = controllerToStatusView.cbegin(); it != controllerToStatusView.cend(); it++){
		ControllerBase* c = (*it).first; 
		(*it).second->setText(c->getName() + "\nenergy: " + to_string(long long(c->getObject()->getEnergy())));
		
		CustomPoint& pos = c->getObject()->getGlobalCenter();
		(*it).second->getPosition().set(pos.x + 1.0f, pos.y + 2.0f);
	}
	return true;
}

