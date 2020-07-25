#pragma once
#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <iterator>
#include <string>

//#include "SUBSYSTEM_CLASSES.h"
//#include "Inventory.h"//вызывает огромное количество ошибок
/*#include "SkillStock.h"
#include "BattleSystem.h"
*/
#include "Сharacteristics.h"
#include "SkillStock.h"
#include "BattleSystem.h"
#include "Inventory.h"
class Equipment;
#include "Equipment.h"

void CQACount(maincharacter& mainCharacter);// необходимое объявление

class Actors
{
public:
	Actors()
	{

	}
};

class maincharacter : public Actors
{
public:
	maincharacter()
	{
		setLevelsOfExperience(levelsOfExperience);
	}

	std::string roleType;
private:
	std::string location;
public:
	int characterLevel = 0;

	Characteristics characteristics; //характеристики персонажа
	Inventory inventory; //инвентарь персонажа
	SkillStock skills; //способности персонажа
	Equipment equipment; //снаряжение персонажа

private:
	int countOfExperience = 0;
	double levelsOfExperience[100]{};
	void setLevelsOfExperience(double levelsOfExperience[]) // ! настройка количества опыта, необоходимого для каждого уровня !
	{
		levelsOfExperience[0] = 100;
		int helpCount = 56;
		for (int i = 1; i < 100; i++)
		{
			levelsOfExperience[i] = levelsOfExperience[i - 1] + helpCount;
			helpCount = (helpCount + (i / 2) * 27);
		}
		/*for (int i = 0; i < 100; i++) //debug
		{
			std::cout << "Уровень " << (i + 1) << "Кол-во опыта " << std::fixed << std::setprecision(0) << levelsOfExperience[i] << std::endl;
		}
		system("pause");*/
	}
	void setLevelOfCharacter()
	{
		if (countOfExperience >= levelsOfExperience[characterLevel]) //проверка, имеется ли необходимое количество опыта у персонажа
		{
			characterLevel += 1;
			std::cout << "Поздравляем с получением " << characterLevel << " уровня!" << std::endl;
		}
	}

	int initialHitPoints = 21; //Начальные значения
	int initialManaPoints = 4;
	int initialPhysDamage = 20;
	int initialMagDamage = 0;
	int initialActionPoints = 3;

public:

	void setCountOfExperience(int incCountOfExperience) //получение персонажем опыта
	{
		countOfExperience += incCountOfExperience;
		std::cout << "Вы получили " << incCountOfExperience << " опыта\n";
		system("pause");
		system("cls");
		setLevelOfCharacter();
	}

	int GetCountOfExperience() //получение персонажем опыта
	{
		return countOfExperience;
	}

	void ShowCountOfExperience()
	{
		std::cout << "Количество опыта: " << levelsOfExperience[characterLevel] << "/" << levelsOfExperience[(characterLevel + 1)] << std::endl;
	}

	void characterUpdate(maincharacter& mainCharacter)
	{
		setLevelOfCharacter();
		//CQACount(mainCharacter); не вариант, так как ошибка линковки (два файла вызывают друг друга)
		//InfluenceOfEffects() InfluenceOfEffectsTurnBegin() / InfluenceOfEffectsTurnEnd()
	}

	int GetInitialHitPoints()
	{
		return initialHitPoints;
	}
	int GetInitialManaPoints()
	{
		return initialManaPoints;
	}
	int GetInitialPhysDamage()
	{
		return initialPhysDamage;
	}
	void SetInitialPhysDamage(int initialPhysDamage)
	{
		this->initialPhysDamage = initialPhysDamage;
	}
	int GetInitialMagDamage()
	{
		return initialMagDamage;
	}
	void SetInitialMagDamage(int initialMagDamage)
	{
		this->initialMagDamage = initialMagDamage;
	}
	void SetInitialActionPoints(int initialActionPoints) //можно убрать, так как имеется постоянное значение
	{
		this->initialActionPoints = initialActionPoints;
	}
	std::string GetLocation()
	{
		return this->location;
	}
	void SetLocation(std::string location)
	{
		this->location = location;
	}

private:

	void StandartAttack(maincharacter& mainCharacter, std::vector<Enemy>& enemies);//стандартное од для оружия + определение вынесено в Skills.cpp

	void EnemyInfo(std::vector<Enemy>& enemies);

public:

	void MaincharacterInfo(maincharacter& mainCharacter);

	void APRegen()
	{
		this->characteristics.actionPoints = this->characteristics.maxActionPoints;
	}

	void MaincharacterTurn(maincharacter& mainCharacter, std::vector<Enemy>& enemies)
	{
		system("cls");
		for (int goOut = 0; (mainCharacter.characteristics.actionPoints > 0) || (goOut != 1);)
		{
			if (!enemies.empty())
			{
				std::cout << "Ваш ход" << std::endl;
				std::cout << "1 - Атака оружием\n2 - Способности\n3 - Бездействие\n4 - Окно персонажа\n5 - Инвентарь\n6 - Осмотр противника" << std::endl;
				int choose;
				std::cin >> choose;
				switch (choose)
				{
				case 1:
				{
					system("cls");
					mainCharacter.StandartAttack(mainCharacter, enemies);
					EnemyDeath(mainCharacter, enemies);

					break;
				}
				case 2:
				{
					system("cls");
					mainCharacter.skills.maincharacterSkillsUse(mainCharacter, enemies);
					EnemyDeath(mainCharacter, enemies);

					break;
				}
				case 3:
				{
					system("cls");
					goOut = 1;
					mainCharacter.characteristics.actionPoints = 0;
					EnemyDeath(mainCharacter, enemies);
					break;
				}
				case 4:
				{
					system("cls");
					mainCharacter.MaincharacterInfo(mainCharacter);

					break;
				}
				case 5:
				{
					system("cls");
					mainCharacter.inventory.InventoryShow();

					break;
				}
				case 6:
				{
					system("cls");
					mainCharacter.EnemyInfo(enemies);

					break;
				}
				default:
				{
					std::cout << "Я не понимаю..." << std::endl;
					system("pause");
					system("cls");
					break;
				}
				}
			}
			else break;
		}
	}

};

class _
{
public:
	int hpMultiplier = 10; //оставил ВОВОЧКЕ БЛЯТЬ ЕСЛИ ЧТО
	int mpMultiplier = 8;
	int addHpMultiplier = 3;
	int addMpMultiplier = 2;

	int physicalStrength = 0;
	int physicalStability = 0;
	int magicalStrength = 0;
	int magicalStability = 0;
	int agility = 0;
	int rhetoric = 0;
	int luck = 0;
	int spirit = 0;
	int endurance = 0;
private:
};

class Warrior //характеристики игров1
	
{
public:
	int hpMultiplier = 29;
	int mpMultiplier = 11;
	int addHpMultiplier = 7;
	int addMpMultiplier = 3;

	int physicalStrength = 6;
	int physicalStability = 14;
	int magicalStrength = 1;
	int magicalStability = 3;
	int agility = 2;
	int rhetoric = 1;
	int luck = 2;
	int spirit = 2;
	int endurance = 5;
private:
};

class Archer
{
public:
	int hpMultiplier = 18;
	int mpMultiplier = 16;
	int addHpMultiplier = 4;
	int addMpMultiplier = 4;

	int physicalStrength = 13;
	int physicalStability = 4;
	int magicalStrength = 4;
	int magicalStability = 1;
	int agility = 7;
	int rhetoric = 2;
	int luck = 4;
	int spirit = 4;
	int endurance = 3;
private:
};

class Thief
{
public:
	int hpMultiplier = 22;
	int mpMultiplier = 15;
	int addHpMultiplier = 5;
	int addMpMultiplier = 4;

	int physicalStrength = 12;
	int physicalStability = 1;
	int magicalStrength = 3;
	int magicalStability = 1;
	int agility = 15;
	int rhetoric = 3;
	int luck = 5;
	int spirit = 2;
	int endurance = 5;
private:
};

class Novice
{
public:
	int hpMultiplier = 15;
	int mpMultiplier = 26;
	int addHpMultiplier = 3;
	int addMpMultiplier = 5;

	int physicalStrength = 5;
	int physicalStability = 2;
	int magicalStrength = 11;
	int magicalStability = 3;
	int agility = 3;
	int rhetoric = 1;
	int luck = 5;
	int spirit = 7;
	int endurance = 4;
private:
};

class Mage
{
public:
	int hpMultiplier = 16;
	int mpMultiplier = 31;
	int addHpMultiplier = 4;
	int addMpMultiplier = 7;

	int physicalStrength = 1;
	int physicalStability = 2;
	int magicalStrength = 21;
	int magicalStability = 3;
	int agility = 1;
	int rhetoric = 4;
	int luck = 2;
	int spirit = 10;
	int endurance = 1;
private:
};