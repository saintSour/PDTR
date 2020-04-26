#include "Roles.h"
#include "Enemies.h"

bool CheckRequirements(maincharacter mainCharacter, int requiredMana, int requiredAP)
{
	if (mainCharacter.manaPoints >= requiredMana && mainCharacter.actionPoints >= requiredAP) return true;
	else return false;
}

void UseFail(maincharacter mainCharacter, int requiredMana, int requiredAP)
{
	if (mainCharacter.manaPoints < requiredMana) std::cout << "Мне не хватает маны " << std::endl;
	else if (mainCharacter.actionPoints < requiredAP) std::cout << "Мне не хватает очков действия " << std::endl;
}

int EnemyChoose(const std::vector<Enemy>& enemies)
{
	int enemyChoose;
	for (int goOut = 0; goOut != 1; )
	{
		std::cout << "Кого мне следует атаковать? " << std::endl;
		for (int i = 0; i <= (enemies.size() - 1); i++)
		{
			std::cout << (i + 1) << ") " << enemies[i].enemyType << "   ХП " << enemies[i].hitPoints << "   МП " << enemies[i].manaPoints << std::endl;
		}
		std::cin >> enemyChoose;
		if (enemyChoose <= enemies.size())
		{
			goOut = 1;
			enemyChoose--;
		}
		else std::cout << "Такого противника нет! " << std::endl;
		system("pause");
		system("cls");
	}

	std::cin >> enemyChoose;
	return enemyChoose;
}

void BandageWounds(maincharacter& mainCharacter)
{
	int requiredMana = 4;
	int requiredAP = 2;
	if (CheckRequirements(mainCharacter, requiredMana, requiredAP))
	{
		int heal = 5; //количество восстановленного здоровья
		std::cout << "Вы перевязали раны и вылечили " << heal << "ХП" << std::endl;
		mainCharacter.hitPoints += heal;
		if (mainCharacter.hitPoints > mainCharacter.maxHitPoints)
			mainCharacter.hitPoints = mainCharacter.maxHitPoints;
	}
	else UseFail(mainCharacter, requiredMana, requiredAP);
	system("pause");
	system("cls");
}

void DoubleStrike(maincharacter& mainCharacter, std::vector<Enemy>& enemies)
{
	int enemyChoose;
	int requiredMana = 8;
	int requiredAP = 3;
	enemyChoose = EnemyChoose(enemies);
	if (CheckRequirements(mainCharacter, requiredMana, requiredAP))
	{
		enemies[enemyChoose].hitPoints -= (mainCharacter.physicalDamage * 0.8);
		std::cout << "Вы совершили первый удар " << std::endl;
		enemies[enemyChoose].hitPoints -= (mainCharacter.physicalDamage * 0.8);
		std::cout << "Вы совершили второй удар " << std::endl;
	}
	else UseFail(mainCharacter, requiredMana, requiredAP);
	system("pause");
	system("cls");
}