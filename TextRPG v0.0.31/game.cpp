#include <iostream> //��������� �����
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <conio.h>

#include "game.h"

int main(int argc, char* argv[]) //�������� ���������, ������� ����
{
	setlocale(LC_ALL, "RU");
	int choise = 0;
	std::cout << "����������, ��������!\n\n";
	while(choise != 4993) 
	{
		std::cout << " 1 - ������ ����\n 2 - ���������\n 3 - ����� �� ����\n";
		choise = _getch();

		switch (choise)
		{
		case 49:
		{
			Game(); //���� ����
			break;
		}

		case 50:
		{
			Settings(); //��������� ����
			break;
		}

		case 51:
		{
			ExitGame(); //����� �� ����
			break;
		}

		default:
		{
			std::cout << "��� �����, ����������� ���������� ��� ���\n"; //��������� ����������
			system("pause");
			break;
		}
		}
		choise = 4993;
	}
}