#pragma once
#include "CustomPoint.h"
#include "ControllerBase.h"
#include "Command.h"

class AIBlackboard
{
public:
	AIBlackboard(void);
	~AIBlackboard(void);

	CustomPoint* getMoveTo() {return moveTo;}
	void setMoveTo(CustomPoint* val){moveTo = val;}
	
	float getMoveForce() const { return moveForce; }
	void setMoveForce(float val) { moveForce = val; }
	
	ControllerBase* getTarget() const { return target; }
	void setTarget(ControllerBase* val) { target = val; }

	CommandType getCommand() const { return command; }
	void setCommand(CommandType val) { command = val; }

protected:
	CustomPoint* moveTo;
	float moveForce;
	
	ControllerBase* target;
	CommandType command;	
};

