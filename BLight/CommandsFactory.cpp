#include "CommandsFactory.h"
#include "AttackCommand.h"
#include "ChargeCommand.h"
#include "CreateCommand.h"
#include "DestroyCommand.h"


bool CommandsFactory::inited = false;

map <string,  Command*(*)()> CommandsFactory::nameToInstance;
map <string,  CommandType> CommandsFactory::nameToType;

Command* CommandsFactory::create(string name)
{
	if(!inited)
		init();

	return nameToInstance[name]();
}

CommandType CommandsFactory::getType(string name)
{
	if(!inited)
		init();

	return nameToType[name];
}

void CommandsFactory::init()
{
	nameToInstance["AttackCommand"] = &createInstance<AttackCommand>;
	nameToType["AttackCommand"] = ATTACK_COMMAND;

	nameToInstance["ChargeCommand"] = &createInstance<ChargeCommand>;
	nameToType["ChargeCommand"] = CHARGE_COMMAND;

	nameToInstance["CreateCommand"] = &createInstance<CreateCommand>;
	nameToType["CreateCommand"] = CREATE_COMMAND;

	nameToInstance["DestroyCommand"] = &createInstance<DestroyCommand>;
	nameToType["DestroyCommand"] = DESTROY_COMMAND;

	inited = true;
}
