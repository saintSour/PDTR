#include "Roles.h"
#include "Enemies.h"

#include "Skills.h"

void BandageWounds(maincharacter& mainCharacter)
{
	int heal = 5; //���������� ���������������� ��������
	std::cout << "�� ���������� ���� � �������� " << heal << "��" << std::endl;
	mainCharacter.hitPoints += heal;
	if (mainCharacter.hitPoints > mainCharacter.maxHitPoints)
		mainCharacter.hitPoints = mainCharacter.maxHitPoints;
	system("pause");
	system("cls");
}