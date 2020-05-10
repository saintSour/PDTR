#include <iostream> //системные файлы
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <conio.h>

#include "game.h"

int main(int argc, char* argv[]) //основная структура, включая меню
{
	setlocale(LC_ALL, "RU");
	int choise = 0;
	std::cout << "Здравствуй, странник!\n\n";
	while(choise != 4993) 
	{
		std::cout << " 1 - Начать игру\n 2 - Настройки\n 3 - Выйти из игры\n";
		choise = _getch();

		switch (choise)
		{
		case 49:
		{
			Game(); //тело игры
			break;
		}

		case 50:
		{
			Settings(); //настройки игры
			break;
		}

		case 51:
		{
			ExitGame(); //выход из игры
			break;
		}

		default:
		{
			std::cout << "Иди нахуй, обработчика исключений ещё нет\n"; //обработка исключений
			system("pause");
			break;
		}
		}
		choise = 4993;
	}
}