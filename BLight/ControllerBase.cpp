#include "ControllerBase.h"
#include "BehaviorBase.h"
#include "EventHeap.h"

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
	cout << "\n" + string(__FUNCTION__) + " " + string(*this);
	
	for (auto it = behaviors->cbegin(); it != behaviors->cend(); it++){
		(*it)->stop();
		delete (*it);
	}

	EventHeap::getInstance().removeEventListener(object);

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

	EventHeap::getInstance().addEventListener(object, view, view->updateListener);
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

bool ControllerBase::startBehaviors(string cName)
{
	for (auto it = behaviors->cbegin(); it != behaviors->cend(); it++){
		if(cName == (*it)->getClassName())
			(*it)->start(this);
	}
	return true;
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
		(*it)->doStep(stepInMSec);
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
