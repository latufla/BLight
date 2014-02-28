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
	vector<BehaviorBase*>* receivers = PhEngineConnector::getInstance().getContactReceivers();
	map<b2Body*, ObjectBase*>* bodyToObject = PhEngineConnector::getInstance().getBodyToObject();

	b2Body* b1;
	b2Body* b2; 
	for (auto it = receivers->cbegin(); it != receivers->cend(); it++){
		b1 = contact->GetFixtureA()->GetBody();
		b2 = contact->GetFixtureA()->GetBody();
		(*it)->onBeginInteraction(bodyToObject->at(b1), bodyToObject->at(b2));
	}
}

void CustomContactListener::EndContact( b2Contact* contact)
{
	vector<BehaviorBase*>* receivers = PhEngineConnector::getInstance().getContactReceivers();
	map<b2Body*, ObjectBase*>* bodyToObject = PhEngineConnector::getInstance().getBodyToObject();

	b2Body* b1;
	b2Body* b2; 
	for (auto it = receivers->cbegin(); it != receivers->cend(); it++){
		b1 = contact->GetFixtureA()->GetBody();
		b2 = contact->GetFixtureA()->GetBody();
		(*it)->onEndInteraction(bodyToObject->at(b1), bodyToObject->at(b2));
	}

}
