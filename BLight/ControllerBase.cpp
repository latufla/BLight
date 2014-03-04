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
	for (auto it = behaviors->cbegin(); it != behaviors->cend(); it++){
		(*it)->stop();
		delete (*it);
	}
	
	delete behaviors;
	delete object;
	delete view;
}

void ControllerBase::init( int id, string name)
{
	this->id = id;
	this->name = name;

	behaviors = new vector<BehaviorBase*>();
	
	view = new ViewBase();
	view->setObject(object);
}

bool ControllerBase::addBehavior( BehaviorBase* b)
{
	behaviors->push_back(b);
	return true;
}

// remove b or exact one
bool ControllerBase::removeBehavior( BehaviorBase* b)
{
	for (auto it = behaviors->cbegin(); it != behaviors->cend(); it++){
		if(*b == (**it)){
			behaviors->erase(it, it + 1);
			return true;
		}			
	}
	return false;
}

bool ControllerBase::startBehaviors()
{
	for (auto it = behaviors->cbegin(); it != behaviors->cend(); it++){
		(*it)->start(this);
	}
	return true;
}


BehaviorBase* ControllerBase::getBehaviorBy(BehaviorType bType)
{
	for (auto it = behaviors->cbegin(); it != behaviors->cend(); it++){
		if((*it)->getType() == bType)
			return *it;
	}
	return nullptr;
}


bool ControllerBase::stopBehaviors()
{
	for (auto it = behaviors->cbegin(); it != behaviors->cend(); it++){
		(*it)->stop();
	}
	return true;
}

bool ControllerBase::doBehaviorsStep( int stepInMSec )
{
	for (auto it = behaviors->cbegin(); it != behaviors->cend(); it++){
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
	for (auto it = behaviors->cbegin(); it != behaviors->cend(); it++){
		res += "{ ";
		res += (**it);
		res += " }, ";
	}
	res.erase(res.size() - 2, 2); // sizeof(char)
	res += " ]";
	return res;
}


int ControllerBase::getId()
{
	return id;
}

std::string ControllerBase::getName()
{
	return name;
}

void ControllerBase::setId( int val )
{
	this->id = val;
}

void ControllerBase::setName( string val )
{
	this->name = val;
}

ObjectBase* ControllerBase::getObject()
{
	return object;
}