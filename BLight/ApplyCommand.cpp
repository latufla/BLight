#include "ApplyCommand.h"
#include "SceneController.h"


ApplyCommand::ApplyCommand(void)
{

}

ApplyCommand::~ApplyCommand(void)
{
}


void ApplyCommand::setUp(ObjectBase* target, int* prop, int applyValue)
{
	this->target = target;
	this->prop = prop;
	this->applyValue = applyValue;
}


bool ApplyCommand::tryToExecute()
{
	if(canExecute()){
		execute();
		return true;
	}
	return false;
}

bool ApplyCommand::canExecute()
{
	return true;
}

void ApplyCommand::execute()
{
	*prop += applyValue;
	
	SceneController& scene = SceneController::getInstance();
 	if(prop == target->getEnergyProp()){
 		scene.getEnergyText().setText("Energy: " + to_string(long long(target->getEnergy())));
 	}
}
