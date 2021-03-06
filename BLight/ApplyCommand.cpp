#include "ApplyCommand.h"


ApplyCommand::ApplyCommand(void)
{

}

ApplyCommand::~ApplyCommand(void)
{
}


void ApplyCommand::setUp(BehaviorBase* caller, ObjectBase* target, int* prop, int applyValue)
{
	this->caller = caller;
	this->target = target;
	this->prop = prop;
	this->applyValue = applyValue;
}


bool ApplyCommand::canExecute()
{
	BehaviorType bType = caller->getType();
	if(prop == target->getEnergyProp()){
		switch(bType){
			case CHARGER_BEHAVIOR:
				return *prop < 100;
			case SIMPLE_DROP_BEHAVIOR:
				return true;
		}
	}
	return false;
}

void ApplyCommand::execute()
{
	*prop += applyValue;
}