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
	EnterTheWorld(mainCharacter, world);

	/*while (gameActive)
	{
		mainCharacter.characterLevel = 27;

		CQACount(mainCharacter);
		CQADebug(mainCharacter); // ��������� �������

		system("pause");

		BattleAwake(mainCharacter);
		system("pause");
	}*/

	system("pause");
}

void ExitGame()
{
	std::cout << "� ���� ��� ������ ���� ����� �����)\n";

	std::cout << "�� �������� 3 ������� \n"; //����� �� ����
	Sleep(1000);
	std::cout << "�� �������� 2 ������� \n";
	Sleep(1000);
	std::cout << "�� �������� 1 �������\n";
	Sleep(1000);

	system("EXIT"); //return 0;
}

void Settings()
{

}