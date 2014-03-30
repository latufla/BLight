#include "ControllerBase.h"
#include "BehaviorBase.h"
#include "Config.h"
#include "StatusViewManager.h"

int ControllerBase::count = 0;

ControllerBase::ControllerBase(void) : object (nullptr)
{
	init(0, "dummy");
}

ControllerBase::ControllerBase( ObjectBase* object )
{
	this->object = object; 
	init(object->getId(), object->getName());	
}


void ControllerBase::setToDestroy(bool val)
{
	toDestroy = val;
	stopBehaviors();
}

ControllerBase::~ControllerBase(void)
{
	cout << "\n" + string(__FUNCTION__) + "\n" + string(*this);
	count--;

	delete object;

 	for (auto it = behaviors.cbegin(); it != behaviors.cend(); it++){
 		delete (*it);
 	}
	behaviors.clear();

	Config::scene->removeChild(view);
	delete view;

	StatusViewManager::getInstance().removeStatusView(this);
}

void ControllerBase::init( int id, string name)
{
	this->id = id;
	this->name = name;
	toDestroy = false;

	view = new ViewBase();
	view->setObject(object);

	count++;
	cout << "\n=>" + string(*this);
}

void ControllerBase::addBehavior( BehaviorBase* b)
{
	behaviors.push_back(b);
}

// remove b or exact one
void ControllerBase::removeBehavior( BehaviorBase* b)
{
	behaviors.erase(remove_if(behaviors.begin(), behaviors.end(), [b](BehaviorBase* bhr) -> bool{
		return b == bhr;
	}), behaviors.end());
}

bool ControllerBase::startBehaviors()
{
	for (auto it = behaviors.cbegin(); it != behaviors.cend(); it++){
		(*it)->start(this);
	}
	return true;
}


BehaviorBase* ControllerBase::getBehaviorBy(BehaviorType bType)
{
	for (auto it = behaviors.cbegin(); it != behaviors.cend(); it++){
		if((*it)->getType() == bType)
			return *it;
	}
	return nullptr;
}


bool ControllerBase::stopBehaviors()
{
	for (auto it = behaviors.cbegin(); it != behaviors.cend(); it++){
		(*it)->stop();
	}
	return true;
}

bool ControllerBase::doBehaviorsStep( int stepInMSec )
{
	for (auto it = behaviors.cbegin(); it != behaviors.cend(); it++){
		(*it)->tryDoStep(stepInMSec);
	}
	return true;
}


ControllerBase::operator string()
{
	string res = string(typeid(*this).name()) 
		+ " id: " + to_string((long long)id) 
		+ ", name: " + name
		+ (object != nullptr ? (",\n object: " + string(*object)) : "")
		+ ",\n behaviors: [ ";
	for (auto it = behaviors.cbegin(); it != behaviors.cend(); it++){
		res += "\n{";
		res += (**it);
		res += "}, ";
	}
	res.erase(res.size() - 1, 2); // sizeof(char)
	res += " ]\n";
	return res;
}
