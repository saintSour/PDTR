#include "Roles.h"
#include "Enemies.h"
#include "Damage.h"

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
		std::cout << "0) Отмена" << std::endl;
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
		else std::cout << "Такого противника нет! " << std::endl;
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
		std::cout << "Прокнула ловкость" << std::endl;
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
			std::cout << "Прокнула броня" << std::endl;
			system("pause");
			system("cls");
		}
		else
		{
			if (damage.type == "physical") damage.count = damage.basicdamage /* - (damage / 100 * defender.block) - resists */;
			if (damage.type == "magical") damage.count = damage.basicdamage /* - (damage / 100 * defender.block) - resists */;
			defender.hitPoints -= damage.count;
			std::cout << "Ничего не прокнуло, обычная атака" << std::endl;
			system("pause");
			system("cls");
		}
	}
}

							/*Праотец всех скиллов, отдай честь*/
void maincharacter::StandartAttack(maincharacter& mainCharacter, std::vector<Enemy>& enemies)
{
	int enemyChoose; //выбор противника
	enemyChoose = EnemyChoose(enemies);
	int requiredMana = 0;					/*Сделать требования МП у оружия*/
	int requiredAP = 2;						/*Сделать требования ОД у оружия*/
	Damage damage;
	damage.basicdamage = mainCharacter.physicalDamage;	/*Сделать урон от оружия + урон может быть магическим + зависимость типа урона от оружия*/ 
	damage.type = "physical";
	if (enemyChoose != -1)
	{
			if (CheckRequirements(mainCharacter, requiredMana, requiredAP))
			{
				DamageDeal(mainCharacter, enemies[enemyChoose], damage);

				mainCharacter.manaPoints -= requiredMana;
				mainCharacter.actionPoints -= requiredAP;
			}
			else 
			{
				UseFail(mainCharacter, requiredMana, requiredAP);
				system("pause");
				system("cls");
			}
	}
	else system("cls");
}									/*Конец праотца*/

void maincharacter::MaincharacterInfo(maincharacter& mainCharacter)
{
	system("cls");
	CQACount(mainCharacter);
	std::cout << mainCharacter.roleType << std::endl;
	std::cout << "Уровень = " << mainCharacter.characterLevel << std::endl;
	mainCharacter.ShowCountOfExperience();
	std::cout << "Очки здоровья = " << mainCharacter.hitPoints << '/' << mainCharacter.maxHitPoints << std::endl;
	std::cout << "Очки маны = " << mainCharacter.manaPoints << '/' << mainCharacter.maxManaPoints << std::endl;
	std::cout << "Физический урон = " << mainCharacter.physicalDamage << std::endl;
	std::cout << "Магический урон = " << mainCharacter.magicalDamage << std::endl;
	std::cout << "Шанс критического урона = " << mainCharacter.criticalChance << " %" << std::endl;
	std::cout << "Рейтинг критического урона = " << mainCharacter.criticalRate << std::endl;
	std::cout << "Шанс блокирования = " << mainCharacter.blockChance << " %" << std::endl;
	std::cout << "Шанс уклонения = " << mainCharacter.dodgeChance << " %" << std::endl;
	std::cout << "Меткость = " <<mainCharacter.accuracy << " %" << std::endl;
	std::cout << "Количество очков действий = " << mainCharacter.actionPoints << "/" << mainCharacter.maxActionPoints << std::endl;
	std::cout << "Количество специальных очков действий = " << mainCharacter.roleActionPoints << "/" << mainCharacter.maxRoleActionPoints << std::endl;
	std::cout << "Физическая стойкость = " << mainCharacter.physicalStability << std::endl;
	std::cout << "Магическая стойкость = " << mainCharacter.magicalStability << std::endl;
	std::cout << "Физическая сила = " << mainCharacter.physicalStrength << std::endl;
	std::cout << "Магическая сила = " << mainCharacter.magicalStrength << std::endl;
	std::cout << "Ловкость = " << mainCharacter.agility << std::endl;
	std::cout << "Красноречие = " << mainCharacter.rhetoric << std::endl;
	std::cout << "Удача = " << mainCharacter.luck << std::endl;
	std::cout << "Дух = " << mainCharacter.spirit << std::endl;
	std::cout << "Выносливость = " << mainCharacter.endurance << std::endl;
	std::cout << "Инициатива = " << mainCharacter.initiative << std::endl;
	std::cout << "Заметность = " << mainCharacter.visibility << std::endl;
	std::cout << "Максимальный вес = " << mainCharacter.maxWeight << std::endl;
	std::cout << "Шанс выпадения лута = " << mainCharacter.dropChance << " %" << std::endl;
	system("pause");
	system("cls");
}

void maincharacter::EnemyInfo(std::vector<Enemy>& enemies)//сделай
{
	int enemyChoose;
	for (int goOut = 0; goOut != 1; )
	{
		std::cout << "Who? То есть кто? " << std::endl;
		for (int i = 0; i <= (enemies.size() - 1); i++)
		{
			std::cout << (i + 1) << ") " << enemies[i].enemyType << "   ХП " << enemies[i].hitPoints << "   МП " << enemies[i].manaPoints << std::endl;
		}
		std::cout << "0) Отмена" << std::endl;
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
		else std::cout << "Такого противника нет! " << std::endl;
		system("pause");
		system("cls");
	}
	if (enemyChoose != -1)
	{
		std::cout << enemies[enemyChoose].enemyType << std::endl;
		std::cout << "Уровень = " << enemies[enemyChoose].level << std::endl;
		std::cout << "Очки здоровья = " << enemies[enemyChoose].hitPoints << '/' << enemies[enemyChoose].maxHitPoints << std::endl;
		std::cout << "Очки маны = " << enemies[enemyChoose].manaPoints << '/' << enemies[enemyChoose].maxManaPoints << std::endl;
		std::cout << "Физический урон = " << enemies[enemyChoose].physicalDamage << std::endl;
		std::cout << "Магический урон = " << enemies[enemyChoose].magicalDamage << std::endl;
		std::cout << "Шанс критического урона = " << enemies[enemyChoose].criticalChance << " %" << std::endl;
		std::cout << "Рейтинг критического урона = " << enemies[enemyChoose].criticalChanceRate << std::endl;
		std::cout << "Шанс блокирования = " << enemies[enemyChoose].blockChance << " %" << std::endl;
		std::cout << "Шанс уклонения = " << enemies[enemyChoose].dodgeChance << " %" << std::endl;
		std::cout << "Меткость = " << enemies[enemyChoose].accuracy << std::endl;
		std::cout << "Количество очков действий = " << enemies[enemyChoose].maxActionPoints << std::endl;
		//std::cout << "Количество классовых очков действий = " << enemies[enemyChoose].maxRoleActionPoints << std::endl;
		std::cout << "Физическая стойкость = " << enemies[enemyChoose].physicalStability << std::endl;
		std::cout << "Магическая стойкость = " << enemies[enemyChoose].magicalStability << std::endl;
		std::cout << "Физическая сила = " << enemies[enemyChoose].physicalStrength << std::endl;
		std::cout << "Магическая сила = " << enemies[enemyChoose].magicalStrength << std::endl;
		std::cout << "Ловкость = " << enemies[enemyChoose].agility << std::endl;
		std::cout << "Красноречие = " << enemies[enemyChoose].rhetoric << std::endl;
		std::cout << "Удача = " << enemies[enemyChoose].luck << std::endl;
		std::cout << "Дух = " << enemies[enemyChoose].spirit << std::endl;
		std::cout << "Выносливость = " << enemies[enemyChoose].endurance << std::endl;
		std::cout << "Инициатива = " << enemies[enemyChoose].initiative << std::endl;
		std::cout << "Заметность = " << enemies[enemyChoose].visibility << std::endl;
	/*	std::cout << "Максимальный вес = " << enemies[enemyChoose].maxWeight << std::endl;
		std::cout << "Шанс выпадения лута = " << enemies[enemyChoose].dropChance << " %" << std::endl;*/
	}
	system("pause");
	system("cls");
}

void BandageWounds(maincharacter& mainCharacter, int requiredMana, int requiredAP)
{
	if (CheckRequirements(mainCharacter, requiredMana, requiredAP))
	{
		int heal = 5; //количество восстановленного здоровья
		std::cout << "Вы перевязали раны и вылечили " << heal << "ХП" << std::endl;
		mainCharacter.hitPoints += heal;
		if (mainCharacter.hitPoints > mainCharacter.maxHitPoints)
			mainCharacter.hitPoints = mainCharacter.maxHitPoints;

		mainCharacter.manaPoints -= requiredMana;
		mainCharacter.actionPoints -= requiredAP;
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
	damage.basicdamage = (mainCharacter.physicalDamage * 0.8);	/*Сделать урон от оружия + урон может быть магическим + зависимость типа урона от оружия*/
	damage.type = "physical";
	if (enemyChoose != -1)
	{
		if (CheckRequirements(mainCharacter, requiredMana, requiredAP))
		{
			DamageDeal(mainCharacter, enemies[enemyChoose], damage);

			DamageDeal(mainCharacter, enemies[enemyChoose], damage);

			mainCharacter.manaPoints -= requiredMana;
			mainCharacter.actionPoints -= requiredAP;
		}
		else UseFail(mainCharacter, requiredMana, requiredAP);
		system("pause");
		system("cls");
	}
	else system("cls");

}