#include "CustomContactListener.h"
#include "PhEngineConnector.h"


CustomContactListener::CustomContactListener(void)
{
}


CustomContactListener::~CustomContactListener(void)
{
}

void CustomContactListener::BeginContact( b2Contact* contact)
{
	map<BehaviorBase*, ObjectBase*>* res = filter(contact);
	for (auto it = res->cbegin(); it != res->cend(); it++){
		it->first->onBeginInteraction(it->second);
	}
}

void CustomContactListener::EndContact( b2Contact* contact)
{
	map<BehaviorBase*, ObjectBase*>* res = filter(contact);
	for (auto it = res->cbegin(); it != res->cend(); it++){
		it->first->onEndInteraction(it->second);
	}
}

map<BehaviorBase*, ObjectBase*>* CustomContactListener::filter(b2Contact* contact)
{
	static map<BehaviorBase*, ObjectBase*> res;
	res.erase(res.cbegin(), res.cend());

	vector<BehaviorBase*>* receivers = &PhEngineConnector::getInstance().contactReceivers;
	map<b2Body*, ObjectBase*>* bodyToObject = &PhEngineConnector::getInstance().bodyToObject;

	b2Body* b1;
	b2Body* b2; 
	ObjectBase* obj1;
	ObjectBase* obj2;
	ObjectBase* receiver;
	ObjectBase* target = nullptr;
	for (auto it = receivers->cbegin(); it != receivers->cend(); it++, target = nullptr){
		b1 = contact->GetFixtureA()->GetBody();
		b2 = contact->GetFixtureB()->GetBody();

		obj1 = bodyToObject->at(b1);
		obj2 = bodyToObject->at(b2);

		receiver = (*it)->getController()->getObject();
		if(receiver == obj1)
			target = obj2;
		else if(receiver == obj2)
			target = obj1;

		if(target != nullptr)
			res[*it] = target;
	}
	return &res;
}

