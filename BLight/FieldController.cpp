#include "FieldController.h"


FieldController::FieldController(void)
{
	field = new Field();
	controllers = new vector<ControllerBase*>();
}


FieldController::~FieldController(void)
{
}

ControllerBase* FieldController::createObjectController(int id, string name, int oType, CustomPoint pos)
{
	ObjectBase* obj = field->createObject(id, name, oType, pos);
	ControllerBase* c = new ControllerBase(obj);
	controllers->push_back(c);
	return c;
}

bool FieldController::startBehaviors()
{
	__super::startBehaviors();
	for(auto it = controllers->cbegin(); it < controllers->cend(); it++){
		(*it)->startBehaviors();
	}
	return true;
}

bool FieldController::stopBehaviors()
{
	__super::stopBehaviors();
	for(auto it = controllers->cbegin(); it < controllers->cend(); it++){
		(*it)->stopBehaviors();
	}
	return true;
}

bool FieldController::doBehaviorsStep(int step)
{
	__super::doBehaviorsStep(step);
	for(auto it = controllers->cbegin(); it < controllers->cend(); it++){
		(*it)->doBehaviorsStep(step);
	}
	return true;
}
