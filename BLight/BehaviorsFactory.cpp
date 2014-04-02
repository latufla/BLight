#include "BehaviorsFactory.h"
#include "UserControlBehavior.h"
#include "MoveBehavior.h"
#include "AttackBehavior.h"

BehaviorBase* BehaviorsFactory::create(string name)
{
	if(name == "UserControlBehavior")
		return new UserControlBehavior();
	else if(name == "MoveBehavior")
		return new MoveBehavior();
	else if(name == "AttackBehavior")
		return new AttackBehavior();	
}
