#include <iostream>

#include "Roles.h"

/*void GetRole(maincharacter& mainCharacter, int roleChoise) // начальный выбор роли главного персонажа
{
		switch (roleChoise) // присваивание (наследование) персонажу начальных характеристик класса
		{
		case 1:
		{
			//Warrior mainCharacter;
			Warrior warrior;
			mainCharacter.roleType = "Мечник";

			mainCharacter.physicalStrength = warrior.physicalStrength;
			mainCharacter.physicalStability = warrior.physicalStability;
			mainCharacter.magicalStrength = warrior.magicalStrength;
			mainCharacter.magicalStability = warrior.magicalStability;
			mainCharacter.agility = warrior.agility;
			mainCharacter.rhetoric = warrior.rhetoric;
			mainCharacter.luck = warrior.luck;
			mainCharacter.spirit = warrior.spirit;
			mainCharacter.endurance = warrior.endurance;

			mainCharacter.hpMultiplier = warrior.hpMultiplier;
			mainCharacter.mpMultiplier = warrior.mpMultiplier;
			mainCharacter.addHpMultiplier = warrior.addHpMultiplier;
			mainCharacter.addMpMultiplier = warrior.addMpMultiplier;
			break;
		}
		case 2:
		{
			Archer archer;
			mainCharacter.roleType = "Лучник";

			mainCharacter.physicalStrength = archer.physicalStrength;
			mainCharacter.physicalStability = archer.physicalStability;
			mainCharacter.magicalStrength = archer.magicalStrength;
			mainCharacter.magicalStability = archer.magicalStability;
			mainCharacter.agility = archer.agility;
			mainCharacter.rhetoric = archer.rhetoric;
			mainCharacter.luck = archer.luck;
			mainCharacter.spirit = archer.spirit;
			mainCharacter.endurance = archer.endurance;

			mainCharacter.hpMultiplier = archer.hpMultiplier;
			mainCharacter.mpMultiplier = archer.mpMultiplier;
			mainCharacter.addHpMultiplier = archer.addHpMultiplier;
			mainCharacter.addMpMultiplier = archer.addMpMultiplier;
			break;
		}
		case 3:
		{
			Thief thief;
			mainCharacter.roleType = "Плут";

			mainCharacter.physicalStrength = thief.physicalStrength;
			mainCharacter.physicalStability = thief.physicalStability;
			mainCharacter.magicalStrength = thief.magicalStrength;
			mainCharacter.magicalStability = thief.magicalStability;
			mainCharacter.agility = thief.agility;
			mainCharacter.rhetoric = thief.rhetoric;
			mainCharacter.luck = thief.luck;
			mainCharacter.spirit = thief.spirit;
			mainCharacter.endurance = thief.endurance;

			mainCharacter.hpMultiplier = thief.hpMultiplier;
			mainCharacter.mpMultiplier = thief.mpMultiplier;
			mainCharacter.addHpMultiplier = thief.addHpMultiplier;
			mainCharacter.addMpMultiplier = thief.addMpMultiplier;
			break;
		}
		case 4:
		{
			Novice novice;
			mainCharacter.roleType = "Послушник";

			mainCharacter.physicalStrength = novice.physicalStrength;
			mainCharacter.physicalStability = novice.physicalStability;
			mainCharacter.magicalStrength = novice.magicalStrength;
			mainCharacter.magicalStability = novice.magicalStability;
			mainCharacter.agility = novice.agility;
			mainCharacter.rhetoric = novice.rhetoric;
			mainCharacter.luck = novice.luck;
			mainCharacter.spirit = novice.spirit;
			mainCharacter.endurance = novice.endurance;

			mainCharacter.hpMultiplier = novice.hpMultiplier;
			mainCharacter.mpMultiplier = novice.mpMultiplier;
			mainCharacter.addHpMultiplier = novice.addHpMultiplier;
			mainCharacter.addMpMultiplier = novice.addMpMultiplier;
			break;
		}
		case 5:
		{
			Mage mage;
			mainCharacter.roleType = "Волшебник";

			mainCharacter.physicalStrength = mage.physicalStrength;
			mainCharacter.physicalStability = mage.physicalStability;
			mainCharacter.magicalStrength = mage.magicalStrength;
			mainCharacter.magicalStability = mage.magicalStability;
			mainCharacter.agility = mage.agility;
			mainCharacter.rhetoric = mage.rhetoric;
			mainCharacter.luck = mage.luck;
			mainCharacter.spirit = mage.spirit;
			mainCharacter.endurance = mage.endurance;

			mainCharacter.hpMultiplier = mage.hpMultiplier;
			mainCharacter.mpMultiplier = mage.mpMultiplier;
			mainCharacter.addHpMultiplier = mage.addHpMultiplier;
			mainCharacter.addMpMultiplier = mage.addMpMultiplier;

			break;
		}
		default:
			std::cout << "Прости, мой друг. Такого класса нет...\n\n";
			roleChoise = -1;
		}
}*/

void GetRole(maincharacter& mainCharacter, std::string roleType) // начальный выбор роли главного персонажа
{									// присваивание (наследование) персонажу начальных характеристик класса
		if (roleType == "_")//исправить на нужный класс
		{
			_ warrior;
			mainCharacter.roleType = "Долбоёб";

			mainCharacter.physicalStrength = warrior.physicalStrength;
			mainCharacter.physicalStability = warrior.physicalStability;
			mainCharacter.magicalStrength = warrior.magicalStrength;
			mainCharacter.magicalStability = warrior.magicalStability;
			mainCharacter.agility = warrior.agility;
			mainCharacter.rhetoric = warrior.rhetoric;
			mainCharacter.luck = warrior.luck;
			mainCharacter.spirit = warrior.spirit;
			mainCharacter.endurance = warrior.endurance;

			mainCharacter.hpMultiplier = warrior.hpMultiplier;
			mainCharacter.mpMultiplier = warrior.mpMultiplier;
			mainCharacter.addHpMultiplier = warrior.addHpMultiplier;
			mainCharacter.addMpMultiplier = warrior.addMpMultiplier;
		}
		if (roleType == "Warrior")
		{
			//Warrior mainCharacter;
			Warrior warrior;
			mainCharacter.roleType = "Мечник";

			mainCharacter.physicalStrength = warrior.physicalStrength;
			mainCharacter.physicalStability = warrior.physicalStability;
			mainCharacter.magicalStrength = warrior.magicalStrength;
			mainCharacter.magicalStability = warrior.magicalStability;
			mainCharacter.agility = warrior.agility;
			mainCharacter.rhetoric = warrior.rhetoric;
			mainCharacter.luck = warrior.luck;
			mainCharacter.spirit = warrior.spirit;
			mainCharacter.endurance = warrior.endurance;

			mainCharacter.hpMultiplier = warrior.hpMultiplier;
			mainCharacter.mpMultiplier = warrior.mpMultiplier;
			mainCharacter.addHpMultiplier = warrior.addHpMultiplier;
			mainCharacter.addMpMultiplier = warrior.addMpMultiplier;
		}
		if (roleType == "Archer")
		{
			Archer archer;
			mainCharacter.roleType = "Лучник";

			mainCharacter.physicalStrength = archer.physicalStrength;
			mainCharacter.physicalStability = archer.physicalStability;
			mainCharacter.magicalStrength = archer.magicalStrength;
			mainCharacter.magicalStability = archer.magicalStability;
			mainCharacter.agility = archer.agility;
			mainCharacter.rhetoric = archer.rhetoric;
			mainCharacter.luck = archer.luck;
			mainCharacter.spirit = archer.spirit;
			mainCharacter.endurance = archer.endurance;

			mainCharacter.hpMultiplier = archer.hpMultiplier;
			mainCharacter.mpMultiplier = archer.mpMultiplier;
			mainCharacter.addHpMultiplier = archer.addHpMultiplier;
			mainCharacter.addMpMultiplier = archer.addMpMultiplier;
		}
		if (roleType == "Thief")
		{
			Thief thief;
			mainCharacter.roleType = "Плут";

			mainCharacter.physicalStrength = thief.physicalStrength;
			mainCharacter.physicalStability = thief.physicalStability;
			mainCharacter.magicalStrength = thief.magicalStrength;
			mainCharacter.magicalStability = thief.magicalStability;
			mainCharacter.agility = thief.agility;
			mainCharacter.rhetoric = thief.rhetoric;
			mainCharacter.luck = thief.luck;
			mainCharacter.spirit = thief.spirit;
			mainCharacter.endurance = thief.endurance;

			mainCharacter.hpMultiplier = thief.hpMultiplier;
			mainCharacter.mpMultiplier = thief.mpMultiplier;
			mainCharacter.addHpMultiplier = thief.addHpMultiplier;
			mainCharacter.addMpMultiplier = thief.addMpMultiplier;
		}
		if (roleType == "Novice")
		{
			Novice novice;
			mainCharacter.roleType = "Послушник";

			mainCharacter.physicalStrength = novice.physicalStrength;
			mainCharacter.physicalStability = novice.physicalStability;
			mainCharacter.magicalStrength = novice.magicalStrength;
			mainCharacter.magicalStability = novice.magicalStability;
			mainCharacter.agility = novice.agility;
			mainCharacter.rhetoric = novice.rhetoric;
			mainCharacter.luck = novice.luck;
			mainCharacter.spirit = novice.spirit;
			mainCharacter.endurance = novice.endurance;

			mainCharacter.hpMultiplier = novice.hpMultiplier;
			mainCharacter.mpMultiplier = novice.mpMultiplier;
			mainCharacter.addHpMultiplier = novice.addHpMultiplier;
			mainCharacter.addMpMultiplier = novice.addMpMultiplier;
		}
		if (roleType == "Mage")
		{
			Mage mage;
			mainCharacter.roleType = "Волшебник";

			mainCharacter.physicalStrength = mage.physicalStrength;
			mainCharacter.physicalStability = mage.physicalStability;
			mainCharacter.magicalStrength = mage.magicalStrength;
			mainCharacter.magicalStability = mage.magicalStability;
			mainCharacter.agility = mage.agility;
			mainCharacter.rhetoric = mage.rhetoric;
			mainCharacter.luck = mage.luck;
			mainCharacter.spirit = mage.spirit;
			mainCharacter.endurance = mage.endurance;

			mainCharacter.hpMultiplier = mage.hpMultiplier;
			mainCharacter.mpMultiplier = mage.mpMultiplier;
			mainCharacter.addHpMultiplier = mage.addHpMultiplier;
			mainCharacter.addMpMultiplier = mage.addMpMultiplier;
		}
}