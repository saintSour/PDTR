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

void EnemyDeath(maincharacter& mainCharacter, std::vector<Enemy>& enemies)
{
	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].hitPoints <= 0) 
		{
			std::cout << enemies[i].enemyType << " умер " << std::endl;
			mainCharacter.setCountOfExperience(enemies[i].experience);
			enemies.erase(enemies.begin() + i);
		}
	}
}

void EndTurn(bool& mainCharacterTurn, maincharacter& mainCharacter, std::vector<Enemy>& enemies)
{
	mainCharacterTurn = false;
	mainCharacter.APRegen();
	/*for (auto i = 0; i < enemies.size(); i++)
	{
		enemies[i].APRegen();
	}*/
}

void BattleStart(maincharacter& mainCharacter, std::vector<Enemy>& enemies) //сделать мгновенную смерть
{
	std::cout << "Ќа ¬ас напал " << enemies[0].enemyType << std::endl;
	bool mainCharacterTurn = false;
	mainCharacter.APRegen();

	while ((mainCharacter.hitPoints > 0) && (!enemies.empty()))
	{
		mainCharacter.initiative = 7; //временна€ проверка

		quickEnemiesSort(enemies, 0, enemies.size());//добавление гг в вектор и последующа€ сортировка

		for (int i = enemies.size(); i > 0; i--)
		{
			if (i > 1)
			{
				if ((mainCharacter.initiative >= enemies[(i - 1)].initiative) && (!mainCharacterTurn))
				{
					mainCharacter.MaincharacterTurn(mainCharacter, enemies);//логика персонажа
					mainCharacterTurn = true;
					EnemyDeath(mainCharacter, enemies);
					i++;
					continue;
				}
				else { enemies[(i - 1)].standartPhysAttack(enemies[(i - 1)], mainCharacter); EnemyDeath(mainCharacter, enemies); }//логика реб€т
			}
			else 
			{
				if (i == 1)
				{
					if ((mainCharacter.initiative > enemies[(i - 1)].initiative) && (!mainCharacterTurn))
					{
						mainCharacter.MaincharacterTurn(mainCharacter, enemies);//логика персонажа
						mainCharacterTurn = true;
						EnemyDeath(mainCharacter, enemies);
						i++;
						continue;
					}
					else { enemies[(i - 1)].standartPhysAttack(enemies[(i - 1)], mainCharacter); EnemyDeath(mainCharacter, enemies); }//логика реб€т
				}
			}
		}
		EnemyDeath(mainCharacter, enemies);
		EndTurn(mainCharacterTurn, mainCharacter, enemies);
		system("pause");
		system("cls");
	}
	//EndBattle();
	//std::cout << "ѕерсонаж погиб... " << std::endl;

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