#pragma once

#include "Skills.h"

//
//
//
//

class Skill
{
private:
	std::string name;
	std::string description;
	int requiredMana;
	int requiredAP;
public:
	std::string GetName()
	{
		return this->name;
	}
	void SetName(std::string name)
	{
		this->name = name;
	}
	std::string GetDescription()
	{
		return this->description;
	}
	void SetDescription(std::string description)
	{
		this->description = description;
	}
	void SetRequiredMana(int mana)
	{
		this->requiredMana = mana;
	}
	int GetRequiredMana()
	{
		return this->requiredMana;
	}
	void SetRequiredAP(int AP)
	{
		this->requiredAP = AP;
	}
	int GetRequiredAP()
	{
		return this->requiredAP;
	}
};

class FTSkill : public Skill
{
public:
	void (*UseSkill)(maincharacter&, int, int, std::vector<Enemy>&);
};
class STSkill : public Skill
{
public:
	void (*UseSkill)(maincharacter&, int, int);
};

class SkillStock
{
public: SkillStock()
{

}
private:
	std::vector<FTSkill> firstTypeSkills;
	std::vector<STSkill> secondTypeSkills;

public:
	void GetSkill(std::string skillTitle)
	{
		FTSkill ftSkill;
		STSkill stSkill;
		int requiredMana;
		int requiredAP;
		if (skillTitle == "DoubleStrike")
		{
			requiredMana = 8;
			requiredAP = 3;
			ftSkill.SetName("Двойной удар");
			ftSkill.SetDescription("IN PROGRESS");
			ftSkill.SetRequiredMana(requiredMana);
			ftSkill.SetRequiredAP(requiredAP);
			ftSkill.UseSkill = DoubleStrike;
			this->firstTypeSkills.push_back(ftSkill);
		}

		if (skillTitle == "BandageWounds")
		{
			requiredMana = 4;
			requiredAP = 2;
			stSkill.SetName("Перевязать Раны");
			stSkill.SetDescription("IN PROGRESS");
			stSkill.SetRequiredMana(requiredMana);
			stSkill.SetRequiredAP(requiredAP);
			stSkill.UseSkill = BandageWounds;
			this->secondTypeSkills.push_back(stSkill);
		}
	}

	void maincharacterSkillsUse(maincharacter& mainCharacter, std::vector<Enemy>& enemies)
	{
		int choose;
		for (int goOut = 0; goOut != 1;)
		{
			system("cls");
			std::cout << "Способность какого типа мне применить?\n1 - Первый тип\n2 - Второй тип\n0 - Отмена" << std::endl;//назвать типы способности
			std::cin >> choose;

			switch (choose)
			{
			case 1:
			{
				UseSkill(mainCharacter, enemies);
				goOut = 1;
				break;
			}
			case 2:
			{
				UseSkill(mainCharacter);
				goOut = 1;
				break;
			}
			case 0:
			{
				goOut = 1;
				break;
			}
			default:
			{
				std::cout << "Не понимаю" << std::endl;
				system("pause");
				system("cls");
				break;
			}
			}
		}
	}

	void UseSkill_World(maincharacter& mainCharacter)
	{
		const int requiredAP = 0; // Трата ОД в мирное время || Она всегда равна нулю
		//for (int goOut = 0; goOut == 0;)
		//{
		system("cls");
		std::cout << "Какую способность применить?" << std::endl;
		for (int i = 0; i < this->secondTypeSkills.size(); i++)
		{
			std::cout << (i + 1) << ") " << this->secondTypeSkills[i].GetName() << std::endl;
		}

		int choose;
		std::cin >> choose;
		if ((choose > this->secondTypeSkills.size()) || (choose < 1)) { system("cls"); std::cout << "Я не понимаю..." << std::endl; system("pause"); system("cls"); }
		else
		{
			system("cls");
			this->secondTypeSkills[(choose - 1)].UseSkill(mainCharacter, this->secondTypeSkills[0].GetRequiredMana(), requiredAP);
		}
	}

	void UseSkill(maincharacter& mainCharacter)
	{
		system("cls");
		std::cout << "Какую способность применить?" << std::endl;
		for (int i = 0; i < this->secondTypeSkills.size(); i++)
		{
			std::cout << (i + 1) << ") " << this->secondTypeSkills[i].GetName() << std::endl;
		}

		int choose;
		std::cin >> choose;
		if ((choose > this->secondTypeSkills.size()) || (choose < 1)) { system("cls"); std::cout << "Я не понимаю..." << std::endl; system("pause"); system("cls"); }
		else 
		{ 
			system("cls");
			this->secondTypeSkills[(choose - 1)].UseSkill(mainCharacter, this->secondTypeSkills[(choose - 1)].GetRequiredMana(),this->secondTypeSkills[(choose - 1)].GetRequiredAP());
		}
	}

	void UseSkill(maincharacter& mainCharacter, std::vector<Enemy>& enemies)
	{
		system("cls");
		std::cout << "Какую способность применить?" << std::endl;
		for (int i = 0; i < this->firstTypeSkills.size(); i++)
		{
			std::cout << (i + 1) << ") " << this->firstTypeSkills[i].GetName() << std::endl;
		}

		int choose;
		std::cin >> choose;
		if ((choose > this->firstTypeSkills.size()) || (choose < 1)) { system("cls"); std::cout << "Я не понимаю..." << std::endl; system("pause"); system("cls"); }
		else
		{
			system("cls");
			this->firstTypeSkills[(choose - 1)].UseSkill(mainCharacter, this->firstTypeSkills[(choose - 1)].GetRequiredMana(), this->firstTypeSkills[(choose - 1)].GetRequiredAP(), enemies);
		}

	}
};

/*void SkillStock::GetSkill(std::string skillTitle)//непосредственное получение самого скилла ++ своеобразный вынесенный конструктор класса
{
	FTSkill ftSkill; 
	STSkill stSkill;
	int requiredMana;
	int requiredAP;
	if (skillTitle == "DoubleStrike")
	{
		requiredMana = 8;
		requiredAP = 3;
		ftSkill.SetName("DoubleStrike");
		ftSkill.SetDescription("IN PROGRESS");
		ftSkill.SetRequiredMana(requiredMana);
		ftSkill.SetRequiredAP(requiredAP);
		ftSkill.UseSkill = DoubleStrike;
		this->firstTypeSkills.push_back(ftSkill);
	}

	if (skillTitle == "BandageWounds")
	{
		requiredMana = 4;
		requiredAP = 2;
		stSkill.SetName("BandageWounds");
		stSkill.SetDescription("IN PROGRESS");
		stSkill.SetRequiredMana(requiredMana);
		stSkill.SetRequiredAP(requiredAP);
		stSkill.UseSkill = BandageWounds;
		this->secondTypeSkills.push_back(stSkill);
	}
}*/