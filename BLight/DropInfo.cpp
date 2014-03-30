#include "DropInfo.h"

string const DropInfo::ENERGY = "energy";
string const DropInfo::XP = "xp";

DropInfo::DropInfo(void)
{
	caller[ENERGY] = 0;
	caller[XP] = 0;

	target[ENERGY] = 0;
	target[XP] = 0;
}

DropInfo::~DropInfo(void)
{
}


