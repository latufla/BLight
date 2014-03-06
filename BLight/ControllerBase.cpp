#include "ControllerBase.h"
#include "BehaviorBase.h"

ControllerBase::ControllerBase(void)
{
	init(0, "dummy");
}

ControllerBase::ControllerBase( ObjectBase* object )
{
	this->object = object; 
	init(object->getId(), object->getName());	
}

ControllerBase::~ControllerBase(void)
{
	for (auto it = behaviors.cbegin(); it != behaviors.cend(); it++){
		(*it)->stop();
		delete (*it);
	}
	
	delete object;
	delete view;
}

void ControllerBase::init( int id, string name)
{
	this->id = id;
	this->name = name;

	view = new ViewBase();
	view->setObject(object);
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
		+ ", name:" + name
		+ ", object: { " + string(*object) + " }" + 
		+ ", behaviors: [ ";
	for (auto it = behaviors.cbegin(); it != behaviors.cend(); it++){
		res += "{ ";
		res += (**it);
		res += " }, ";
	}
	res.erase(res.size() - 2, 2); // sizeof(char)
	res += " ]";
	return res;
}