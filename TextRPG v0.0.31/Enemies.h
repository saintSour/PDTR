#pragma once
#include <string>

#include "Roles.h"

class Enemy : public Actors
{
public:
	std::string enemyType;

	Enemy()
	{
		this->maxHitPoints = 0;
		this->hitPoints = 0;
		this->maxManaPoints = 0;
		this->manaPoints = 0;
		this->maxActionPoints = 0;
		this->physicalDamage = 0;
		this->magicalDamage = 0;
		this->blockChance = 0;
		this->dodgeChance = 0;
		this->accuracy = 0;
		this->criticalChance = 0;
		this->criticalChanceRate = 0;
		this->initiative = 0;

		this->enteringPhrase = "";
	}

	int level;
	int experience;

	int maxHitPoints;
	int hitPoints = maxHitPoints;
	int maxManaPoints;
	int manaPoints = maxManaPoints;
	int maxActionPoints;

	int physicalDamage;
	int magicalDamage;

	double blockChance;
	double dodgeChance;
	double accuracy;

	double criticalChance;
	double criticalChanceRate;

	int initiative;
	std::string enteringPhrase; //для генератора фраз и изменения в зависимости от противника

	std::vector<void (*)(Enemy&, maincharacter&)> skillStock; //ячейки для скиллов

	/*void standartPhysAttack(Enemy& attacker, maincharacter& defender)
	{
		srand(10);
		if (attacker.accuracy <= (size_t(rand() % 100 + 1)))
		{
			std::cout << attacker.enemyType << " бьёт по Вам и наносит " << attacker.physicalDamage << " урона" << std::endl;
			//вывод текста об успешном нанесении урона
			defender.hitPoints -= attacker.physicalDamage;
			std::cout << "Главный герой" << " HP " << defender.hitPoints << " MP " << defender.manaPoints << std::endl;
			std::cout << attacker.enemyType << " HP " << attacker.hitPoints << " MP " << attacker.manaPoints << std::endl;
			system("pause");
			system("cls");
		}
	}*/
};

class Melee //Типы врагов
{

};

class Ranger
{

};

class enemyHog //Представители врагов
{
public:
	std::string delegateType = "Hog";
	int level = 1;
	int experience = 21;

	int maxHitPoints = 27;
	int maxManaPoints = 0;
	int maxActionPoints = 3; //реализовать в Update()

	int physicalDamage = 9;
	int magicalDamage = 0;

	double blockChance = 6.7;
	double dodgeChance = 0.5;
	double accuracy = 49.0;

	double criticalChance = 2.1;
	double criticalChanceRate = 1.3;
	
	int initiative = 3;
};

class enemySnake
{
public:
	std::string delegateType = "Snake";
	int level = 3;
	int experience = 43;

	int maxHitPoints = 45;
	int maxManaPoints = 0;
	int maxActionPoints = 4;

	int physicalDamage = 14;
	int magicalDamage = 0;

	double blockChance = 0.3;
	double dodgeChance = 7.9;
	double accuracy = 54.0;

	double criticalChance = 4.1;
	double criticalChanceRate = 1.4;

	int initiative = 4;
};

class enemyGoblin
{
public:
	std::string delegateType = "Goblin";
	int level = 5;
	int experience = 78;

	int maxHitPoints = 67;
	int maxManaPoints = 0;
	int maxActionPoints = 4;

	int physicalDamage = 19;
	int magicalDamage = 0;

	double blockChance = 0.3;
	double dodgeChance = 7.0;
	double accuracy = 50.0;

	double criticalChance = 5.1;
	double criticalChanceRate = 1.3;

	int initiative = 4;
};

Enemy SpawnRandomEnemy();

Enemy SpawnRandomEnemy(std::string EnemyType);

Enemy SpawnEnemy(std::string EnemyDelegate);