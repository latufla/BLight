#include "FieldController.h"


void FieldController::init()
{
}

ControllerBase* FieldController::createObjectController(int id, string name, int oType, const CustomPoint& pos)
{
	ObjectBase* obj = field.createObject(id, name, oType, pos);
	ControllerBase* c = new ControllerBase(obj);
	controllers.push_back(c);
	return c;
}

void FieldController::destroyObjectController(ControllerBase* c)
{
	c->setToDestroy(true);
}


bool FieldController::startBehaviors()
{
	__super::startBehaviors();
	for(auto it = controllers.cbegin(); it < controllers.cend(); it++){
		(*it)->startBehaviors();
	}
	return true;
}

bool FieldController::stopBehaviors()
{
	__super::stopBehaviors();
	for(auto it = controllers.cbegin(); it < controllers.cend(); it++){
		(*it)->stopBehaviors();
	}
	return true;
}

bool FieldController::doBehaviorsStep(int step)
{
	__super::doBehaviorsStep(step);
	for(auto it = controllers.cbegin(); it < controllers.cend(); it++){
		(*it)->doBehaviorsStep(step);
	}
	doDestroyStep();
	return true;
}

void FieldController::doDestroyStep()
{
	controllers.erase(remove_if(controllers.begin(), controllers.end(), [this](ControllerBase* c) -> bool{
 		bool res = c->getToDestroy();
 		if(res){
 			ObjectBase* obj = c->getObject();
			delete c;
			field.destroyObject(obj);
 		}			
		return res;
	}), controllers.end());
}
