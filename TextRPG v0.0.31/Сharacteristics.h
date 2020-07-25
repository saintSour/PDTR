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

	double blockChance; //���� ����������������� ������������
	double dodgeChance;
	double accuracy;

	int actionPoints; //���������� ��
	int maxActionPoints = 3;
	int roleActionPoints;
	int maxRoleActionPoints;

	int physicalStability;
	int magicalStability;

	int physicalStrength; //��������� �������
	int magicalStrength;

	int agility; //��������
	int rhetoric; //�����������, �-�� ���������
	int luck; //�����
	int spirit; //���
	int endurance; //������������
	int initiative; //����������
	int visibility; //����������

	double maxWeight; //������������ ���
	double dropChance; //���. ���� ��������� ����
};