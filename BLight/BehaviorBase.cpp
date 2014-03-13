#include "BehaviorBase.h"

int BehaviorBase::count = 0;

BehaviorBase::BehaviorBase(void)
{
	init(0, "dummy");
}

BehaviorBase::BehaviorBase( int id, string name)
{
	init(id, name);
}

BehaviorBase::~BehaviorBase(void)
{
	count--;
}

void BehaviorBase::init( int id, string name )
{
	this->id = id;
	this->name = name;
	enabled = false;

	count++;
}


bool BehaviorBase::start( ControllerBase* c)
{
	controller = c;
	enabled = true;

	return true;
}

bool BehaviorBase::stop()
{
	controller = nullptr;
	enabled = false;

	return true;
}


bool BehaviorBase::tryDoStep( int stepInMSecs )
{
	return canDoStep() ? doStep(stepInMSecs) : false;
}

bool BehaviorBase::canDoStep()
{
	return enabled;
}

bool BehaviorBase::doStep(int)
{
	return true;
}

BehaviorBase::operator string()
{
	return string(typeid(*this).name()) + " id: " + to_string((long long)id)
		+ ", name: " + name 
		+ ", enabled: " + to_string((long long)enabled); 
}
