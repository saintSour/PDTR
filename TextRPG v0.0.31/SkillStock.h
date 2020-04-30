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

	void UseSkill(maincharacter& mainCharacter)
	{
		const int requiredAP = 0; // Трата ОД в мирное время || Она всегда равна нулю
		//for (int goOut = 0; goOut == 0;)
		//{
			std::cout << "Какую способность применить?" << std::endl;
			for (int i = 0; i < this->secondTypeSkills.size(); i++)
			{
				std::cout << (i+1) << ") " << this->secondTypeSkills[i].GetName() << std::endl;
			}

			int choose;
			std::cin >> choose;
			if ((choose > this->secondTypeSkills.size()) || (choose < 1)) { system("cls"); std::cout << "Я не понимаю..." << std::endl; system("pause"); system("cls"); }
			else 
			{ 
				system("cls");
				this->secondTypeSkills[(choose - 1)].UseSkill(mainCharacter, this->secondTypeSkills[0].GetRequiredMana(), requiredAP); 
			}
			//goOut = 1;
		//}
	}

	void UseSkill(maincharacter& mainCharacter, std::vector<Enemy>& enemies)
	{
		for (int goOut = 0; goOut == 0;)
		{
			std::cout << "Какую способность применить?" << std::endl << "1 - Способность Атаки\n2 - Способность Защиты\n" << std::endl;
			int i;
			std::cin >> i;
			switch (i)
			{
			case 1:
			{
				system("cls");
				this->firstTypeSkills[0].UseSkill(mainCharacter, this->firstTypeSkills[0].GetRequiredMana(), this->firstTypeSkills[0].GetRequiredAP(), enemies);//
				goOut = 1;
				break;
			}
			case 2:
			{
				system("cls");
				this->secondTypeSkills[0].UseSkill(mainCharacter, this->secondTypeSkills[0].GetRequiredMana(), this->secondTypeSkills[0].GetRequiredAP());//
				goOut = 1;
				break;
			}
			default:
			{
				std::cout << "Я не понимаю... " << std::endl;
				break;
			}
			}
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