#pragma once

#include "Skills.h"

//
//class maincharacter;
//class Enemy;
//

class SkillStock
{
public: SkillStock()
{

}
private:
	std::vector<void (*)(maincharacter&, std::vector<Enemy>&)> firstTypeSkills;
	std::vector<void (*)(maincharacter&)> secondTypeSkills;

	//std::vector<void (*)(maincharacter&, std::vector<Enemy>&), std::string> test;
public:
	void GetSkill(std::string skillTitle)
	{
		if (skillTitle == "BandageWounds") this->secondTypeSkills.push_back(BandageWounds);
		if (skillTitle == "DoubleStrike") this->firstTypeSkills.push_back(DoubleStrike);
	}
	void UseSkill(maincharacter& mainCharacter, std::vector<Enemy>& enemies)
	{
		for (int goOut = 0; goOut == 0;)
		{
			std::cout << "����� ����������� ���������?" << std::endl << "1 - ����������� �����\n2 - ����������� ������\n" << std::endl;
			int i;
			std::cin >> i;
			switch (i)
			{
			case 1:
			{
				system("cls");
				this->firstTypeSkills[0](mainCharacter, enemies);//
				goOut = 1;
				break;
			}
			case 2:
			{
				system("cls");
				this->secondTypeSkills[0](mainCharacter);//
				goOut = 1;
				break;
			}
			default:
			{
				std::cout << "� �� �������... " << std::endl;
				break;
			}
			}
		}
	}
};