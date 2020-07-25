#pragma once

class Characteristics
{
public:

	int maxHitPoints;
	int maxHitPoints_ini; //ini - initial
	int maxManaPoints;
	int maxManaPoints_ini;

	int hitPoints;
	int manaPoints;

	int hpMultiplier;
	int mpMultiplier;
	int addHpMultiplier;
	int addMpMultiplier;

	int physicalDamage;
	int physicalDamage_ini;
	int magicalDamage;
	int magicalDamage_ini;
 
	int blockCount;
	int blockCount_ini;

	double criticalChance;
	double criticalChance_ini;

	double criticalRate;
	double criticalRate_ini;

	double blockChance; //шанс непосредственного блокирования
	double dodgeChance;
	double accuracy;

	int actionPoints; //Количество ОД
	int maxActionPoints = 3;
	int roleActionPoints;
	int maxRoleActionPoints;

	int physicalStability;
	int magicalStability;

	int physicalStrength; //нерабочий вариант
	int magicalStrength;

	int agility; //ловкость
	int rhetoric; //красноречие, а-ля убеждение
	int luck; //удача
	int spirit; //дух
	int endurance; //выносливость
	int initiative; //инициатива
	int visibility; //заметность

	double maxWeight; //Максимальный вес
	double dropChance; //Доп. Шанс выпадения лута
};