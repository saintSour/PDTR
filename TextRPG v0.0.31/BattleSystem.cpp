#include <iostream>
#include <Windows.h>
#include <vector>

#include "Enemies.h"
#include "Roles.h"
#include "Enemies.h"

template <typename T>
void quickEnemiesSort(std::vector<T>& actors, int left, int right) //сортировка врагов
{
	int i = left, j = (right - 1);
	T temp;
	int pivot = (actors[((i + j) / 2)].initiative);


	while (i <= j)
	{
		while (actors[i].initiative < pivot)
			i++;
		while (actors[j].initiative > pivot)
			j--;
		if (i <= j)
		{
			temp = actors[i];

			actors[i] = actors[j];

			actors[j] = temp;

			i++;
			j--;
		}
	};


	if (left < j)
		quickEnemiesSort(actors, left, j);
	if (i < right)
		quickEnemiesSort(actors, i, right);

}

void BattleStart(maincharacter& mainCharacter, std::vector<Enemy>& enemies) //сделать мгновенную смерть
{
	bool mainCharacterTurn = false;
	while ((mainCharacter.hitPoints > 0) && (!enemies.empty()))
	{
		mainCharacter.initiative = 7; //временна€ проверка
		enemies[0].initiative = 7;
		enemies[1].initiative = 1;
		enemies[2].initiative = 3;
		enemies[3].initiative = 9;
		quickEnemiesSort(enemies, 0, enemies.size());//добавление гг в вектор и последующа€ сортировка

		for (int i = enemies.size(); i >= 0; i--)
		{
			if (i > 1) //чтобы не было доступа к внешней пам€ти (об€зательно) || добавить try/catch
			{
				if ((mainCharacter.initiative >= enemies[(i - 1)].initiative) /*&& (mainCharacter.initiative >= enemies[(i - 2)].initiative)*/ && (!mainCharacterTurn))
				{
					std::cout << "атакует персонаж " << std::endl;//атака персонажа
					mainCharacterTurn = true;
					//i++;
					continue;
				}
				//enemies[(i - 1)].standartPhysAttack(enemies[(i - 1)], mainCharacter);//атака реб€т
			}
			else
			{
				if (i == 1)
				{
					if ((mainCharacter.initiative > enemies[(i - 1)].initiative) && (!mainCharacterTurn))
					{
						std::cout << "атакует персонаж " << std::endl;//атака персонажа
						mainCharacterTurn = true;
						//i++;
						continue;
					}
					//enemies[(i - 1)].standartPhysAttack(enemies[(i - 1)], mainCharacter);//атака реб€т
				}
				else
				{
					if (!mainCharacterTurn)
					{
						std::cout << "ебенит перс " << std::endl;//атака персонажа
						mainCharacterTurn = true;
						//i++;
						continue;
					}
					//enemies[(i - 1)].standartPhysAttack(enemies[(i - 1)], mainCharacter);//атака мудозвонов
				}
			}
		}
		mainCharacterTurn = false;
		system("pause");
	}
	std::cout << "ѕерсонаж погиб... " << std::endl;

	/*while (mainCharacter.hitPoints >= 0 && enemy.hitPoints >= 0) // битва продолжаетс€, пока кто-то не умрЄт
	{
		mainCharacter.characterUpdate();
		std::cout << "HP " << mainCharacter.hitPoints << " MP " << mainCharacter.manaPoints << "\n";
		std::cout << "HP " << enemy.hitPoints << " " << enemy.enemyType << "\n\n";
		std::cout << "Ќажми пробел, чтобы атаковать(разумеетс€, € это изменю)" << std::endl;
		system("pause");

		std::cout << "¬аше лицо переполн€етс€ гневом \n"; //изменить в следующем обновлении!!!
		Sleep(1000);
		std::cout << "¬ы замахиваетесь \n";
		Sleep(1000);
		std::cout << "» совершаете удар такой силы, который способен расколоть планету!\n" << "Ќу или почти...\n";
		Sleep(1000);
		enemy.hitPoints -= mainCharacter.physicalDamage; // исправить в следующем обновлении!!!
		system("cls");
	}
	if (enemy.hitPoints <= 0)
	{
		std::cout << "» пал противник " << enemy.enemyType << " от руки его т€жЄлой...\n"; //генератор фраз(смерть противника)
		mainCharacter.setCountOfExperience(100);
	}
	else 
	{
		std::cout << "¬ этом бою великий " << mainCharacter.roleType << " был повержен, но значит ли, что это конец истории?\n"; //генератор фраз(смерть главного геро€)
	}*/
}

void BattleAwake(maincharacter& mainCharacter)
{
	std::vector<Enemy> enemies;
	enemies.push_back(SpawnRandomEnemy());
	BattleStart(mainCharacter, enemies);
}

void BattleAwake(maincharacter& mainCharacter, std::string EnemyType)
{
	std::vector<Enemy> enemies;
	enemies.push_back(SpawnRandomEnemy(EnemyType));
	BattleStart(mainCharacter, enemies);
}

void BattleAwakeCon(maincharacter& mainCharacter, std::string EnemyDelegate, int enemiesCount)
{
	std::vector<Enemy> enemies;
	for (int i = 0; i < enemiesCount; i++)
	{
		enemies.push_back(SpawnEnemy(EnemyDelegate));
	}
	BattleStart(mainCharacter, enemies);
}