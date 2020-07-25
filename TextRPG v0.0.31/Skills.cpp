#include "Roles.h"
#include "Enemies.h"
#include "Damage.h"

bool CheckRequirements(maincharacter mainCharacter, int requiredMana, int requiredAP)
{
	if (mainCharacter.characteristics.manaPoints >= requiredMana && mainCharacter.characteristics.actionPoints >= requiredAP) return true;
	else return false;
}

void UseFail(maincharacter mainCharacter, int requiredMana, int requiredAP)
{
	if (mainCharacter.characteristics.manaPoints < requiredMana) std::cout << "��� �� ������� ���� " << std::endl;
	else if (mainCharacter.characteristics.actionPoints < requiredAP) std::cout << "��� �� ������� ����� �������� " << std::endl;
}

int EnemyChoose(const std::vector<Enemy>& enemies)
{
	int enemyChoose;
	for (int goOut = 0; goOut != 1; )
	{
		std::cout << "���� ��� ������� ���������? " << std::endl;
		for (int i = 0; i <= (enemies.size() - 1); i++)
		{
			std::cout << (i + 1) << ") " << enemies[i].enemyType << "   �� " << enemies[i].hitPoints << "   �� " << enemies[i].manaPoints << std::endl;
		}
		std::cout << "0) ������" << std::endl;
		std::cin >> enemyChoose;
		if (enemyChoose == 0)
		{
			goOut = 1;
			enemyChoose--;
		}
		else if (enemyChoose <= enemies.size())
		{
			goOut = 1;
			enemyChoose--;
		}
		else std::cout << "������ ���������� ���! " << std::endl;
		system("pause");
		system("cls");
	}

	return enemyChoose;
}

template <typename T1, typename T2>
void DamageDeal(T1& attacker, T2& defender, Damage& damage)
{
	srand(time(NULL));
	if ((rand() % 101) <= defender.dodgeChance)
	{
		damage.count = 0;
		std::cout << "�������� ��������" << std::endl;
		system("pause");
		system("cls");
	} 
	else
	{
		if ((rand() % 101) <= defender.blockChance)
		{
			if (damage.type == "physical") damage.count = damage.basicdamage - defender.blockCount /* - (damage / 100 * defender.block) - resists */;
			if (damage.type == "magical") damage.count = damage.basicdamage - defender.blockCount /* - (damage / 100 * defender.block) - resists */;
			defender.hitPoints -= damage.count;
			std::cout << "�������� �����" << std::endl;
			system("pause");
			system("cls");
		}
		else
		{
			if (damage.type == "physical") damage.count = damage.basicdamage /* - (damage / 100 * defender.block) - resists */;
			if (damage.type == "magical") damage.count = damage.basicdamage /* - (damage / 100 * defender.block) - resists */;
			defender.hitPoints -= damage.count;
			std::cout << "������ �� ��������, ������� �����" << std::endl;
			system("pause");
			system("cls");
		}
	}
}

							/*������� ���� �������, ����� �����*/
void maincharacter::StandartAttack(maincharacter& mainCharacter, std::vector<Enemy>& enemies)
{
	int enemyChoose; //����� ����������
	enemyChoose = EnemyChoose(enemies);
	int requiredMana = 0;					/*������� ���������� �� � ������*/
	int requiredAP = 2;						/*������� ���������� �� � ������*/
	Damage damage;
	damage.basicdamage = mainCharacter.characteristics.physicalDamage;	/*������� ���� �� ������ + ���� ����� ���� ���������� + ����������� ���� ����� �� ������*/
	damage.type = "physical";
	if (enemyChoose != -1)
	{
			if (CheckRequirements(mainCharacter, requiredMana, requiredAP))
			{
				DamageDeal(mainCharacter, enemies[enemyChoose], damage);

				mainCharacter.characteristics.manaPoints -= requiredMana;
				mainCharacter.characteristics.actionPoints -= requiredAP;
			}
			else 
			{
				UseFail(mainCharacter, requiredMana, requiredAP);
				system("pause");
				system("cls");
			}
	}
	else system("cls");
}									/*����� �������*/

void maincharacter::MaincharacterInfo(maincharacter& mainCharacter)
{
	system("cls");
	CQACount(mainCharacter);
	std::cout << mainCharacter.roleType << std::endl;
	std::cout << "������� = " << mainCharacter.characterLevel << std::endl;
	mainCharacter.ShowCountOfExperience();
	std::cout << "���� �������� = " << mainCharacter.characteristics.hitPoints << '/' << mainCharacter.characteristics.maxHitPoints << std::endl;
	std::cout << "���� ���� = " << mainCharacter.characteristics.manaPoints << '/' << mainCharacter.characteristics.maxManaPoints << std::endl;
	std::cout << "���������� ���� = " << mainCharacter.characteristics.physicalDamage << std::endl;
	std::cout << "���������� ���� = " << mainCharacter.characteristics.magicalDamage << std::endl;
	std::cout << "���� ������������ ����� = " << mainCharacter.characteristics.criticalChance << " %" << std::endl;
	std::cout << "������� ������������ ����� = " << mainCharacter.characteristics.criticalRate << std::endl;
	std::cout << "���� ������������ = " << mainCharacter.characteristics.blockChance << " %" << std::endl;
	std::cout << "���� ��������� = " << mainCharacter.characteristics.dodgeChance << " %" << std::endl;
	std::cout << "�������� = " <<mainCharacter.characteristics.accuracy << " %" << std::endl;
	std::cout << "���������� ����� �������� = " << mainCharacter.characteristics.actionPoints << "/" << mainCharacter.characteristics.maxActionPoints << std::endl;
	std::cout << "���������� ����������� ����� �������� = " << mainCharacter.characteristics.roleActionPoints << "/" << mainCharacter.characteristics.maxRoleActionPoints << std::endl;
	std::cout << "���������� ��������� = " << mainCharacter.characteristics.physicalStability << std::endl;
	std::cout << "���������� ��������� = " << mainCharacter.characteristics.magicalStability << std::endl;
	std::cout << "���������� ���� = " << mainCharacter.characteristics.physicalStrength << std::endl;
	std::cout << "���������� ���� = " << mainCharacter.characteristics.magicalStrength << std::endl;
	std::cout << "�������� = " << mainCharacter.characteristics.agility << std::endl;
	std::cout << "����������� = " << mainCharacter.characteristics.rhetoric << std::endl;
	std::cout << "����� = " << mainCharacter.characteristics.luck << std::endl;
	std::cout << "��� = " << mainCharacter.characteristics.spirit << std::endl;
	std::cout << "������������ = " << mainCharacter.characteristics.endurance << std::endl;
	std::cout << "���������� = " << mainCharacter.characteristics.initiative << std::endl;
	std::cout << "���������� = " << mainCharacter.characteristics.visibility << std::endl;
	std::cout << "������������ ��� = " << mainCharacter.characteristics.maxWeight << std::endl;
	std::cout << "���� ��������� ���� = " << mainCharacter.characteristics.dropChance << " %" << std::endl;
	system("pause");
	system("cls");
}

void maincharacter::EnemyInfo(std::vector<Enemy>& enemies)//������
{
	int enemyChoose;
	for (int goOut = 0; goOut != 1; )
	{
		std::cout << "Who? �� ���� ���? " << std::endl;
		for (int i = 0; i <= (enemies.size() - 1); i++)
		{
			std::cout << (i + 1) << ") " << enemies[i].enemyType << "   �� " << enemies[i].hitPoints << "   �� " << enemies[i].manaPoints << std::endl;
		}
		std::cout << "0) ������" << std::endl;
		std::cin >> enemyChoose;
		if (enemyChoose == 0)
		{
			goOut = 1;
			enemyChoose--;
		}
		else if (enemyChoose <= enemies.size())
		{
			goOut = 1;
			enemyChoose--;
		}
		else std::cout << "������ ���������� ���! " << std::endl;
		system("pause");
		system("cls");
	}
	if (enemyChoose != -1)
	{
		std::cout << enemies[enemyChoose].enemyType << std::endl;
		std::cout << "������� = " << enemies[enemyChoose].level << std::endl;
		std::cout << "���� �������� = " << enemies[enemyChoose].hitPoints << '/' << enemies[enemyChoose].maxHitPoints << std::endl;
		std::cout << "���� ���� = " << enemies[enemyChoose].manaPoints << '/' << enemies[enemyChoose].maxManaPoints << std::endl;
		std::cout << "���������� ���� = " << enemies[enemyChoose].physicalDamage << std::endl;
		std::cout << "���������� ���� = " << enemies[enemyChoose].magicalDamage << std::endl;
		std::cout << "���� ������������ ����� = " << enemies[enemyChoose].criticalChance << " %" << std::endl;
		std::cout << "������� ������������ ����� = " << enemies[enemyChoose].criticalChanceRate << std::endl;
		std::cout << "���� ������������ = " << enemies[enemyChoose].blockChance << " %" << std::endl;
		std::cout << "���� ��������� = " << enemies[enemyChoose].dodgeChance << " %" << std::endl;
		std::cout << "�������� = " << enemies[enemyChoose].accuracy << std::endl;
		std::cout << "���������� ����� �������� = " << enemies[enemyChoose].maxActionPoints << std::endl;
		//std::cout << "���������� ��������� ����� �������� = " << enemies[enemyChoose].maxRoleActionPoints << std::endl;
		std::cout << "���������� ��������� = " << enemies[enemyChoose].physicalStability << std::endl;
		std::cout << "���������� ��������� = " << enemies[enemyChoose].magicalStability << std::endl;
		std::cout << "���������� ���� = " << enemies[enemyChoose].physicalStrength << std::endl;
		std::cout << "���������� ���� = " << enemies[enemyChoose].magicalStrength << std::endl;
		std::cout << "�������� = " << enemies[enemyChoose].agility << std::endl;
		std::cout << "����������� = " << enemies[enemyChoose].rhetoric << std::endl;
		std::cout << "����� = " << enemies[enemyChoose].luck << std::endl;
		std::cout << "��� = " << enemies[enemyChoose].spirit << std::endl;
		std::cout << "������������ = " << enemies[enemyChoose].endurance << std::endl;
		std::cout << "���������� = " << enemies[enemyChoose].initiative << std::endl;
		std::cout << "���������� = " << enemies[enemyChoose].visibility << std::endl;
	/*	std::cout << "������������ ��� = " << enemies[enemyChoose].maxWeight << std::endl;
		std::cout << "���� ��������� ���� = " << enemies[enemyChoose].dropChance << " %" << std::endl;*/
	}
	system("pause");
	system("cls");
}

void BandageWounds(maincharacter& mainCharacter, int requiredMana, int requiredAP)
{
	if (CheckRequirements(mainCharacter, requiredMana, requiredAP))
	{
		int heal = 5; //���������� ���������������� ��������
		std::cout << "�� ���������� ���� � �������� " << heal << "��" << std::endl;
		mainCharacter.characteristics.hitPoints += heal;
		if (mainCharacter.characteristics.hitPoints > mainCharacter.characteristics.maxHitPoints)
			mainCharacter.characteristics.hitPoints = mainCharacter.characteristics.maxHitPoints;

		mainCharacter.characteristics.manaPoints -= requiredMana;
		mainCharacter.characteristics.actionPoints -= requiredAP;
	}
	else UseFail(mainCharacter, requiredMana, requiredAP);
	system("pause");
	system("cls");
}

void DoubleStrike(maincharacter& mainCharacter, int requiredMana, int requiredAP, std::vector<Enemy>& enemies)
{
	int enemyChoose;
	enemyChoose = EnemyChoose(enemies);
	Damage damage;
	damage.basicdamage = (mainCharacter.characteristics.physicalDamage * 0.8);	/*������� ���� �� ������ + ���� ����� ���� ���������� + ����������� ���� ����� �� ������*/
	damage.type = "physical";
	if (enemyChoose != -1)
	{
		if (CheckRequirements(mainCharacter, requiredMana, requiredAP))
		{
			DamageDeal(mainCharacter, enemies[enemyChoose], damage);

			DamageDeal(mainCharacter, enemies[enemyChoose], damage);

			mainCharacter.characteristics.manaPoints -= requiredMana;
			mainCharacter.characteristics.actionPoints -= requiredAP;
		}
		else UseFail(mainCharacter, requiredMana, requiredAP);
		system("pause");
		system("cls");
	}
	else system("cls");

}