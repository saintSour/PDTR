#include <iostream>
#include <Windows.h>

#include "game.h"
#include "Roles.h"
#include "BattleSystem.h"
#include "Attributes.h"
#include "World.h"
#include "Inventory.h"
void Game()
{
	system("cls");
	int gameActive = 1;
	maincharacter mainCharacter;
	World world;
	GetRole(mainCharacter, "_");
	mainCharacter.characterLevel = 1;
	EnterTheWorld(mainCharacter, world);

	system("pause");
}

void ExitGame()
{
	std::cout << "Я буду рад видеть тебя здесь снова)\n";

	std::cout << "До закрытия 3 секунды \n"; //выход из игры
	Sleep(1000);
	std::cout << "До закрытия 2 секунды \n";
	Sleep(1000);
	std::cout << "До закрытия 1 секунда\n";
	Sleep(1000);

	system("EXIT"); //return 0;
}

void Settings()
{

}