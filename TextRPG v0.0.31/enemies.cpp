#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

#include "Enemies.h"

void GetRandomEnemyType(std::string &enemyType)
{
	srand(time(NULL));
	int typesCount = 2; //количество типов противников
	int typeID = rand() % typesCount + 1; //случайный выбор ID, соответсвующего типу нового противника

	switch (typeID)
	{
	case 1:
		enemyType = "Melee";
		break;
	case 2:
		enemyType = "Ranger";
		break;
	}
}

void GetRandomEnemyDelegate(std::string& enemyType, std::string& enemyDelegate) //выбор случайного представителя по полученному типу
{
	srand(time(NULL));
	int delegatesCount = 3;
	int delegateID = rand() % delegatesCount + 1;
	if (enemyType == "Melee") {
		switch (delegateID)
		{
		case 1:
			enemyDelegate = "Hog";
			break;
		case 2:
			enemyDelegate = "Snake";
			break;
		case 3:
			enemyDelegate = "Goblin";
			break;
		}
	}
	if (enemyType == "Ranger")
	{
		switch (delegateID)
		{
		case 1:
			enemyDelegate = "Hog";
			break;
		case 2:
			enemyDelegate = "Snake";
			break;
		case 3:
			enemyDelegate = "Goblin";
			break;
		}
	}
}

Enemy SpawnNewEnemyWithParametrs(std::string enemyDelegate) //присваивание параметров новому противнику, исходя из классов
{
	Enemy enemy;
	if (enemyDelegate == "Hog")
	{
		enemyHog enemyDelegate;
		enemy.enemyType = enemyDelegate.delegateType;
		enemy.level = enemyDelegate.level;
		enemy.experience = enemyDelegate.experience;

		enemy.maxHitPoints = enemyDelegate.maxHitPoints;
		enemy.hitPoints = enemyDelegate.maxHitPoints;
		enemy.maxManaPoints = enemyDelegate.maxManaPoints;
		enemy.manaPoints = enemyDelegate.maxManaPoints;
		enemy.maxActionPoints = enemyDelegate.maxActionPoints;

		enemy.physicalDamage = enemyDelegate.physicalDamage;
		enemy.magicalDamage = enemyDelegate.magicalDamage;

		enemy.blockChance = enemyDelegate.blockChance;
		enemy.dodgeChance = enemyDelegate.dodgeChance;
		enemy.accuracy = enemyDelegate.accuracy;

		enemy.criticalChance = enemyDelegate.criticalChance;
		enemy.criticalChanceRate = enemyDelegate.criticalChanceRate;

		enemy.initiative = enemyDelegate.initiative;
	}
	if (enemyDelegate == "Snake")
	{
		enemySnake enemyDelegate;
		enemy.enemyType = enemyDelegate.delegateType;
		enemy.level = enemyDelegate.level;
		enemy.experience = enemyDelegate.experience;

		enemy.maxHitPoints = enemyDelegate.maxHitPoints;
		enemy.hitPoints = enemyDelegate.maxHitPoints;
		enemy.maxManaPoints = enemyDelegate.maxManaPoints;
		enemy.manaPoints = enemyDelegate.maxManaPoints;
		enemy.maxActionPoints = enemyDelegate.maxActionPoints;

		enemy.physicalDamage = enemyDelegate.physicalDamage;
		enemy.magicalDamage = enemyDelegate.magicalDamage;

		enemy.blockChance = enemyDelegate.blockChance;
		enemy.dodgeChance = enemyDelegate.dodgeChance;
		enemy.accuracy = enemyDelegate.accuracy;

		enemy.criticalChance = enemyDelegate.criticalChance;
		enemy.criticalChanceRate = enemyDelegate.criticalChanceRate;

		enemy.initiative = enemyDelegate.initiative;
	}
	if (enemyDelegate == "Goblin")
	{
		enemyGoblin enemyDelegate;
		enemy.enemyType = enemyDelegate.delegateType;
		enemy.level = enemyDelegate.level;
		enemy.experience = enemyDelegate.experience;

		enemy.maxHitPoints = enemyDelegate.maxHitPoints;
		enemy.hitPoints = enemyDelegate.maxHitPoints;
		enemy.maxManaPoints = enemyDelegate.maxManaPoints;
		enemy.manaPoints = enemyDelegate.maxManaPoints;
		enemy.maxActionPoints = enemyDelegate.maxActionPoints;

		enemy.physicalDamage = enemyDelegate.physicalDamage;
		enemy.magicalDamage = enemyDelegate.magicalDamage;

		enemy.blockChance = enemyDelegate.blockChance;
		enemy.dodgeChance = enemyDelegate.dodgeChance;
		enemy.accuracy = enemyDelegate.accuracy;

		enemy.criticalChance = enemyDelegate.criticalChance;
		enemy.criticalChanceRate = enemyDelegate.criticalChanceRate;

		enemy.initiative = enemyDelegate.initiative;
	}
	return enemy;
}

Enemy SpawnRandomEnemy()
{
	std::string enemyType;
	std::string enemyDelegate;
	GetRandomEnemyType(enemyType);
	GetRandomEnemyDelegate(enemyType, enemyDelegate);
	Enemy enemy = SpawnNewEnemyWithParametrs(enemyDelegate);
	return enemy;
}

Enemy SpawnRandomEnemy(std::string EnemyType)
{
	std::string enemyDelegate;;
	GetRandomEnemyDelegate(EnemyType, enemyDelegate);
	Enemy enemy = SpawnNewEnemyWithParametrs(enemyDelegate);
	return enemy;
}

Enemy SpawnEnemy(std::string EnemyDelegate)
{
	Enemy enemy = SpawnNewEnemyWithParametrs(EnemyDelegate);
	return enemy;
}