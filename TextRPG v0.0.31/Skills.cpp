#include "Roles.h"
#include "Enemies.h"

#include "Skills.h"

void BandageWounds(maincharacter& mainCharacter)
{
	int heal = 5; //количество восстановленного здоровья
	std::cout << "Вы перевязали раны и вылечили " << heal << "ХП" << std::endl;
	mainCharacter.hitPoints += heal;
	if (mainCharacter.hitPoints > mainCharacter.maxHitPoints)
		mainCharacter.hitPoints = mainCharacter.maxHitPoints;
	system("pause");
	system("cls");
}