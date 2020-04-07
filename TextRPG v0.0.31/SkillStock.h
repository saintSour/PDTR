#pragma once

#include "Skills.h"

//
class maincharacter;
class Enemy;
//

class SkillStock
{
public: SkillStock()
{

}
private:
	std::vector<void (*)(maincharacter&)> skillStock;
public:
	void GetSkill()
	{
		this->skillStock.push_back(BandageWounds);
	}
	void UseSkill(maincharacter& mainCharacter)
	{
		this->skillStock[0](mainCharacter);
	}
};