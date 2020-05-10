#pragma once

#include <cstring>

#include "Skills.h"
#include "SkillStock.h"
#include "Roles.h"

class Damage
{
public:
	Damage()
	{
		count = 0;
		basicdamage = 0;
		type = "";
	}

	int count;
	int basicdamage;
	std::string type;
};