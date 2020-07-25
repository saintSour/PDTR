#include <cstring>

#include "Roles.h"
#include "Enemies.h"
#include "Attributes.h"



void MaxHitPointsCount(maincharacter& mainCharacter) //расчёт максимума хп (опционально-настраиваемо
{
	int initialHitPoints = mainCharacter.GetInitialHitPoints();
	int helpHp = 0;

	for ( int i = 0; i < mainCharacter.characterLevel; i++)
	{
		initialHitPoints = initialHitPoints + helpHp;
		helpHp = (mainCharacter.characteristics.hpMultiplier + (i / 10) * mainCharacter.characteristics.addHpMultiplier);
	}

	initialHitPoints = size_t(initialHitPoints + (initialHitPoints * (0.04 * mainCharacter.characteristics.physicalStability)) + (initialHitPoints * (0.015 * mainCharacter.characteristics.magicalStability)) + (initialHitPoints * (0.015 * mainCharacter.characteristics.endurance)));

	mainCharacter.characteristics.maxHitPoints = initialHitPoints;
}

void EnemyMaxHitPointsCount(Enemy& enemy)
{

}

void MaxManaPointsCount(maincharacter& mainCharacter) //расчёт максимума мп (опционально-настраиваемо
{
	int initialManaPoints = mainCharacter.GetInitialManaPoints();
	int helpMp = 0;

	for (int i = 0; i < mainCharacter.characterLevel; i++)
	{
		initialManaPoints = initialManaPoints + helpMp;
		helpMp = (mainCharacter.characteristics.mpMultiplier + (i / 10) * mainCharacter.characteristics.addMpMultiplier); //16
	}

	mainCharacter.characteristics.maxManaPoints = size_t(initialManaPoints + (initialManaPoints * (mainCharacter.characteristics.spirit * 0.04)));
}

void EnemyMaxManaPointsCount(Enemy& enemy)
{

}

void PhysMagDamageCount(maincharacter& mainCharacter) //расчёт максимума фд и мд (опционально-настраиваемо //К следующей обнове переделать
{
	int initialPhysDamage = mainCharacter.GetInitialPhysDamage();
	int initialMagDamage = mainCharacter.GetInitialMagDamage();
	/*int helpPD = 0;
	int helpMD = 0;

	for (int i = 0; i < mainCharacter.characterLevel; i++)
	{
		initialPhysDamage = initialPhysDamage + helpPD;
		initialMagDamage = initialMagDamage + helpMD;
		helpPD = (7 + (i / 10) * 4);
		helpMD = (7 + (i / 10) * 4);
	}*/

	initialPhysDamage = size_t(initialPhysDamage + (initialPhysDamage * 0.025 * mainCharacter.characteristics.physicalStrength)); // влияние экипировки + статы
	initialMagDamage = size_t(initialMagDamage + (initialMagDamage * 0.025 * mainCharacter.characteristics.magicalStrength));

	mainCharacter.characteristics.physicalDamage = initialPhysDamage;
	mainCharacter.characteristics.magicalDamage = initialMagDamage;
}

void EnemyPhysMagDamageCount(Enemy& enemy)
{

}

void MaxActionPointsCount(maincharacter& mainCharacter) //расчёт максимума од (опционально-настраиваемо
{
	int initialActionPoints = 3 + (mainCharacter.characterLevel / 5) + (mainCharacter.characteristics.agility / 15) + (mainCharacter.characteristics.spirit / 20) + (mainCharacter.characteristics.endurance / 20);

	mainCharacter.characteristics.maxActionPoints = initialActionPoints;
}

void EnemyMaxActionPointsCount(Enemy& enemy)
{

}

void MaxWeightCount(maincharacter& mainCharacter)
{
	int maxWeight = 35 + (mainCharacter.characteristics.physicalStrength * 2) + (mainCharacter.characteristics.physicalStability * 6);
	mainCharacter.characteristics.maxWeight = maxWeight;
}

void CriticalChanceCount(maincharacter& mainCharacter)
{
	double physCrit = (mainCharacter.characteristics.physicalStrength * 0.3); //на деле в процентах
	double magCrit = (mainCharacter.characteristics.magicalStrength * 0.3);
	double agilCrit = (mainCharacter.characteristics.agility * 1);
	double luckCrit = (mainCharacter.characteristics.luck * 0.2);
	if (physCrit > 35) physCrit = 35;
	if (magCrit > 35) magCrit = 35;
	if (agilCrit > 35) agilCrit = 35;
	if (luckCrit > 35) luckCrit = 35;
	mainCharacter.characteristics.criticalChance = (physCrit + magCrit + agilCrit + luckCrit);
}

void EnemyCriticalChanceCount(Enemy& enemy)
{

}

void BlockChanceCount(maincharacter& mainCharacter)
{
	double blockChance = (mainCharacter.characteristics.physicalStability * 0.3);//+ от снаряги
	if (blockChance > 35) blockChance = 35;
	mainCharacter.characteristics.blockChance = blockChance;
}

void BlockCount(maincharacter& mainCharacter)
{
	mainCharacter.characteristics.blockCount = 0;
}

void EnemyBlockChanceCount(Enemy& enemy)
{

}

void InitiativeCount(maincharacter& mainCharacter)
{ //доделать, ЕСЛИ ЧТО
	int initiative = (mainCharacter.characteristics.physicalStability / 4) + (mainCharacter.characteristics.magicalStability / 4);

	mainCharacter.characteristics.initiative = initiative;
}

void EnemyInitiativeCount(Enemy& enemy)
{

}

void VisibilityCount(maincharacter& mainCharacter)
{
	int visibility = (mainCharacter.characteristics.physicalStability / 15) + (mainCharacter.characteristics.physicalStrength / 20) - (mainCharacter.characteristics.agility / 15);

	mainCharacter.characteristics.visibility = visibility;
}

void DodgeChanceCount(maincharacter& mainCharacter)
{
	double agilChance = (mainCharacter.characteristics.agility * 0.5);
	if (agilChance > 40) agilChance = 40;
	mainCharacter.characteristics.dodgeChance = agilChance;
}

void EnemyDodgeChanceCount(Enemy& enemy)
{

}

void AccuracyCount(maincharacter& mainCharacter)
{
	double accuracy = (mainCharacter.characteristics.agility * 0.6) + (mainCharacter.characteristics.spirit * 0.2) + (mainCharacter.characteristics.endurance * 0.2);
	mainCharacter.characteristics.accuracy = accuracy;
}

void EnemyAccuracyCount(Enemy& enemy)
{

}

void RhetoricCount(maincharacter& mainCharacter)
{

}

void DropChanceCount(maincharacter& mainCharacter)
{
	double dropChance = (mainCharacter.characteristics.luck * 0.5);
	mainCharacter.characteristics.dropChance = dropChance;
}

void CQACount(maincharacter& mainCharacter) //завершить к следующему обновлению
{
	MaxHitPointsCount(mainCharacter);
	MaxManaPointsCount(mainCharacter);
	PhysMagDamageCount(mainCharacter);
	MaxActionPointsCount(mainCharacter);
	MaxWeightCount(mainCharacter);
	CriticalChanceCount(mainCharacter);
	BlockChanceCount(mainCharacter);
	BlockCount(mainCharacter);
	InitiativeCount(mainCharacter);
	VisibilityCount(mainCharacter);
	DodgeChanceCount(mainCharacter);
	AccuracyCount(mainCharacter);
	RhetoricCount(mainCharacter);
	DropChanceCount(mainCharacter);
}

void EnemyCQACount(Enemy& enemy) //завершить к следующему обновлению
{
	EnemyMaxHitPointsCount(enemy);
	EnemyMaxManaPointsCount(enemy);
	EnemyPhysMagDamageCount(enemy);
	EnemyMaxActionPointsCount(enemy);
	EnemyCriticalChanceCount(enemy);
	EnemyBlockChanceCount(enemy);
	EnemyInitiativeCount(enemy);
	EnemyDodgeChanceCount(enemy);
	EnemyAccuracyCount(enemy);
}

void CQADebug(maincharacter& mainCharacter)
{
	std::cout << "MaxHp " << mainCharacter.characteristics.maxHitPoints << std::endl;
	std::cout << "MaxMp " << mainCharacter.characteristics.maxManaPoints << std::endl;
	std::cout << "physdamage " << mainCharacter.characteristics.physicalDamage << std::endl;
	std::cout << "magdamage " << mainCharacter.characteristics.magicalDamage << std::endl;
	std::cout << "maxactionpoints " << mainCharacter.characteristics.maxActionPoints << std::endl;
	std::cout << "maxweight " << mainCharacter.characteristics.maxWeight << std::endl;
	std::cout << "critchance " << mainCharacter.characteristics.criticalChance << std::endl;
	std::cout << "blockchance " << mainCharacter.characteristics.blockChance << std::endl;
	std::cout << "initiative " << mainCharacter.characteristics.initiative << std::endl;
	std::cout << "visibility " << mainCharacter.characteristics.visibility << std::endl;
	std::cout << "dodgechance " << mainCharacter.characteristics.dodgeChance << std::endl;
	std::cout << "accuracy " << mainCharacter.characteristics.accuracy << std::endl;
	std::cout << "rhetoric " << mainCharacter.characteristics.rhetoric << std::endl;
	std::cout << "dropchance " << mainCharacter.characteristics.dropChance << std::endl;
}