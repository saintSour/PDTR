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
		helpHp = (mainCharacter.hpMultiplier + (i / 10) * mainCharacter.addHpMultiplier);
	}

	initialHitPoints = size_t(initialHitPoints + (initialHitPoints * (0.04 * mainCharacter.physicalStability)) + (initialHitPoints * (0.015 * mainCharacter.magicalStability)) + (initialHitPoints * (0.015 * mainCharacter.endurance)));

	mainCharacter.maxHitPoints = initialHitPoints;
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
		helpMp = (mainCharacter.mpMultiplier + (i / 10) * mainCharacter.addMpMultiplier); //16
	}

	mainCharacter.maxManaPoints = size_t(initialManaPoints + (initialManaPoints * (mainCharacter.spirit * 0.04)));
}

void EnemyMaxManaPointsCount(Enemy& enemy)
{

}

void PhysMagDamageCount(maincharacter& mainCharacter) //расчёт максимума фд и мд (опционально-настраиваемо //К следующей обнове переделать
{
	int initialPhysDamage = mainCharacter.GetInitialPhysDamage();
	int initialMagDamage = mainCharacter.GetInitialMagDamage();
	int helpPD = 0;
	int helpMD = 0;

	/*for (int i = 0; i < mainCharacter.characterLevel; i++)
	{
		initialPhysDamage = initialPhysDamage + helpPD;
		initialMagDamage = initialMagDamage + helpMD;
		helpPD = (7 + (i / 10) * 4);
		helpMD = (7 + (i / 10) * 4);
	}*/

	initialPhysDamage = size_t(initialPhysDamage + (initialPhysDamage * 0.025 * mainCharacter.physicalStrength)); // влияние экипировки + статы
	initialMagDamage = size_t(initialMagDamage + (initialMagDamage * 0.025 * mainCharacter.magicalStrength));

	mainCharacter.physicalDamage = initialPhysDamage;
	mainCharacter.magicalDamage = initialMagDamage;
}

void EnemyPhysMagDamageCount(Enemy& enemy)
{

}

void MaxActionPointsCount(maincharacter& mainCharacter) //расчёт максимума од (опционально-настраиваемо
{
	int initialActionPoints = 3 + (mainCharacter.characterLevel / 5) + (mainCharacter.agility / 15) + (mainCharacter.spirit / 20) + (mainCharacter.endurance / 20);

	mainCharacter.maxActionPoints = initialActionPoints;
}

void EnemyMaxActionPointsCount(Enemy& enemy)
{

}

void MaxWeightCount(maincharacter& mainCharacter)
{
	int maxWeight = 35 + (mainCharacter.physicalStrength * 7);
	mainCharacter.maxWeight = maxWeight;
}

void CriticalChanceCount(maincharacter& mainCharacter)
{
	double physCrit = (mainCharacter.physicalStrength * 0.3); //на деле в процентах
	double magCrit = (mainCharacter.magicalStrength * 0.3);
	double agilCrit = (mainCharacter.agility * 1);
	double luckCrit = (mainCharacter.luck * 0.2);
	if (physCrit > 35) physCrit = 35;
	if (magCrit > 35) magCrit = 35;
	if (agilCrit > 35) agilCrit = 35;
	if (luckCrit > 35) luckCrit = 35;
	mainCharacter.criticalChance = (physCrit + magCrit + agilCrit + luckCrit);
}

void EnemyCriticalChanceCount(Enemy& enemy)
{

}

void BlockChanceCount(maincharacter& mainCharacter)
{
	double blockChance = (mainCharacter.physicalStability * 0.3);
	if (blockChance > 35) blockChance = 35;
	mainCharacter.blockChance = blockChance;
}

void EnemyBlockChanceCount(Enemy& enemy)
{

}

void InitiativeCount(maincharacter& mainCharacter)
{ //доделать, ЕСЛИ ЧТО
	int initiative = (mainCharacter.physicalStability / 4) + (mainCharacter.magicalStability / 4);

	mainCharacter.initiative = initiative;
}

void EnemyInitiativeCount(Enemy& enemy)
{

}

void VisibilityCount(maincharacter& mainCharacter)
{
	int visibility = (mainCharacter.physicalStability / 15) + (mainCharacter.physicalStrength / 20) - (mainCharacter.agility / 15);

	mainCharacter.visibility = visibility;
}

void DodgeChanceCount(maincharacter& mainCharacter)
{
	double agilChance = (mainCharacter.agility * 0.5);
	if (agilChance > 40) agilChance = 40;
	mainCharacter.dodgeChance = agilChance;
}

void EnemyDodgeChanceCount(Enemy& enemy)
{

}

void AccuracyCount(maincharacter& mainCharacter)
{
	double accuracy = (mainCharacter.agility * 0.6) + (mainCharacter.spirit * 0.2) + (mainCharacter.endurance * 0.2);
	mainCharacter.accuracy = accuracy;
}

void EnemyAccuracyCount(Enemy& enemy)
{

}

void RhetoricCount(maincharacter& mainCharacter)
{

}

void DropChanceCount(maincharacter& mainCharacter)
{
	double dropChance = (mainCharacter.luck * 0.5);
	mainCharacter.dropChance = dropChance;
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
	std::cout << "MaxHp " << mainCharacter.maxHitPoints << std::endl;
	std::cout << "MaxMp " << mainCharacter.maxManaPoints << std::endl;
	std::cout << "physdamage " << mainCharacter.physicalDamage << std::endl;
	std::cout << "magdamage " << mainCharacter.magicalDamage << std::endl;
	std::cout << "maxactionpoints " << mainCharacter.maxActionPoints << std::endl;
	std::cout << "maxweight " << mainCharacter.maxWeight << std::endl;
	std::cout << "critchance " << mainCharacter.criticalChance << std::endl;
	std::cout << "blockchance " << mainCharacter.blockChance << std::endl;
	std::cout << "initiative " << mainCharacter.initiative << std::endl;
	std::cout << "visibility " << mainCharacter.visibility << std::endl;
	std::cout << "dodgechance " << mainCharacter.dodgeChance << std::endl;
	std::cout << "accuracy " << mainCharacter.accuracy << std::endl;
	std::cout << "rhetoric " << mainCharacter.rhetoric << std::endl;
	std::cout << "dropchance " << mainCharacter.dropChance << std::endl;
}