#include "StatusViewManager.h"
#include "Config.h"

void StatusViewManager::addStatusView(ControllerBase* c)
{
	TextBase* p = new TextBase();
	p->setText(c->getName() + to_string(long long(c->getObject()->getEnergy())));
	p->setCharacterSize(14);
	p->getPosition().set(c->getObject()->getGlobalCenter());
	Config::scene->addChild(p);
	controllerToStatusView[c] = p;
}

void StatusViewManager::removeStatusView(ControllerBase* c)
{
	Config::scene->removeChild(controllerToStatusView[c]);	
	delete controllerToStatusView[c];
	
	auto it = controllerToStatusView.find(c);
	controllerToStatusView.erase(it);
}


bool StatusViewManager::doStep(int step)
{
	for(auto it = controllerToStatusView.cbegin(); it != controllerToStatusView.cend(); it++){
		ControllerBase* c = (*it).first; 
		
		(*it).second->setText(c->getName() + "\nenergy: " 
			+ to_string(long long(c->getObject()->getEnergy())) + "\nxp: " 
			+ to_string(long long(c->getObject()->getXp())));
		
		CustomPoint& pos = c->getObject()->getGlobalCenter();
		(*it).second->getPosition().set(pos.x + 1.0f, pos.y + 2.0f);
	}
	return true;
}

