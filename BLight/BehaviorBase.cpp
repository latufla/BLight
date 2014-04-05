#include "BehaviorBase.h"

int BehaviorBase::count = 0;


BehaviorBase::BehaviorBase( void )
{
	id = -1;
	name = "dummy";

	enabled = false;
	count++;
}

BehaviorBase::BehaviorBase(Info* info)
{
	id = -1;
	name = info->name;

	enabled = false;
	count++;
}

BehaviorBase::~BehaviorBase(void)
{
	count--;
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
