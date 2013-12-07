#include "StubBehavior.h"


StubBehavior::StubBehavior(void)
{
}

StubBehavior::StubBehavior( int id, string name)
{
	init(id, name);
}


StubBehavior::~StubBehavior(void)
{
}

bool StubBehavior::doStep( int stepInMSecs )
{
	__super::doStep(stepInMSecs);

	ObjectBase* obj = controller->getObject();
	if(obj != nullptr)
		obj->fireUpdates();
	
	return true;
}

