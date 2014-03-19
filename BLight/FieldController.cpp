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

ControllerBase* FieldController::createObjectController( int id, const ObjectInfo& info, const CustomPoint& pos)
{
	ControllerBase* c = createObjectController(id, info.name, info.physicType, pos);
	ObjectBase* obj = c->getObject();
	obj->setShape(info.shape->clone());
	obj->setDensity(info.density);
	obj->setFriction(info.friction);
	obj->setRestitution(info.restitution);
	obj->setLinearDamping(info.linearDamping);

	for (auto it = info.behaviors.cbegin(); it < info.behaviors.cend(); it++){
		c->addBehavior((*it)->clone());
	}

	// and ai too
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
			field.destroyObject(c->getObject());
			delete c;
		}			
		return res;
	}), controllers.end());
}
