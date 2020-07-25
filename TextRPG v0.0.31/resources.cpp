#include <iostream>

#include "Roles.h"
#include "Attributes.h"

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
			_ _;
			mainCharacter.roleType = "Никто";

			mainCharacter.characteristics.physicalStrength += _.physicalStrength;
			mainCharacter.characteristics.physicalStability += _.physicalStability;
			mainCharacter.characteristics.magicalStrength += _.magicalStrength;
			mainCharacter.characteristics.magicalStability += _.magicalStability;
			mainCharacter.characteristics.agility += _.agility;
			mainCharacter.characteristics.rhetoric += _.rhetoric;
			mainCharacter.characteristics.luck += _.luck;
			mainCharacter.characteristics.spirit += _.spirit;
			mainCharacter.characteristics.endurance += _.endurance;

			mainCharacter.characteristics.hpMultiplier = _.hpMultiplier;
			mainCharacter.characteristics.mpMultiplier = _.mpMultiplier;
			mainCharacter.characteristics.addHpMultiplier = _.addHpMultiplier;
			mainCharacter.characteristics.addMpMultiplier = _.addMpMultiplier;
			CQACount(mainCharacter);
		}
		if (roleType == "Warrior")
		{
			//Warrior mainCharacter;
			Warrior warrior;
			mainCharacter.roleType = "Мечник";

			mainCharacter.characteristics.physicalStrength += warrior.physicalStrength;
			mainCharacter.characteristics.physicalStability += warrior.physicalStability;
			mainCharacter.characteristics.magicalStrength += warrior.magicalStrength;
			mainCharacter.characteristics.magicalStability += warrior.magicalStability;
			mainCharacter.characteristics.agility += warrior.agility;
			mainCharacter.characteristics.rhetoric += warrior.rhetoric;
			mainCharacter.characteristics.luck += warrior.luck;
			mainCharacter.characteristics.spirit += warrior.spirit;
			mainCharacter.characteristics.endurance += warrior.endurance;

			mainCharacter.characteristics.hpMultiplier = warrior.hpMultiplier;
			mainCharacter.characteristics.mpMultiplier = warrior.mpMultiplier;
			mainCharacter.characteristics.addHpMultiplier = warrior.addHpMultiplier;
			mainCharacter.characteristics.addMpMultiplier = warrior.addMpMultiplier;
			CQACount(mainCharacter);
		}
		if (roleType == "Archer")
		{
			Archer archer;
			mainCharacter.roleType = "Лучник";

			mainCharacter.characteristics.physicalStrength += archer.physicalStrength;
			mainCharacter.characteristics.physicalStability += archer.physicalStability;
			mainCharacter.characteristics.magicalStrength += archer.magicalStrength;
			mainCharacter.characteristics.magicalStability += archer.magicalStability;
			mainCharacter.characteristics.agility += archer.agility;
			mainCharacter.characteristics.rhetoric += archer.rhetoric;
			mainCharacter.characteristics.luck += archer.luck;
			mainCharacter.characteristics.spirit += archer.spirit;
			mainCharacter.characteristics.endurance += archer.endurance;

			mainCharacter.characteristics.hpMultiplier = archer.hpMultiplier;
			mainCharacter.characteristics.mpMultiplier = archer.mpMultiplier;
			mainCharacter.characteristics.addHpMultiplier = archer.addHpMultiplier;
			mainCharacter.characteristics.addMpMultiplier = archer.addMpMultiplier;
			CQACount(mainCharacter);
		}
		if (roleType == "Thief")
		{
			Thief thief;
			mainCharacter.roleType = "Плут";

			mainCharacter.characteristics.physicalStrength += thief.physicalStrength;
			mainCharacter.characteristics.physicalStability += thief.physicalStability;
			mainCharacter.characteristics.magicalStrength += thief.magicalStrength;
			mainCharacter.characteristics.magicalStability += thief.magicalStability;
			mainCharacter.characteristics.agility += thief.agility;
			mainCharacter.characteristics.rhetoric += thief.rhetoric;
			mainCharacter.characteristics.luck += thief.luck;
			mainCharacter.characteristics.spirit += thief.spirit;
			mainCharacter.characteristics.endurance += thief.endurance;

			mainCharacter.characteristics.hpMultiplier = thief.hpMultiplier;
			mainCharacter.characteristics.mpMultiplier = thief.mpMultiplier;
			mainCharacter.characteristics.addHpMultiplier = thief.addHpMultiplier;
			mainCharacter.characteristics.addMpMultiplier = thief.addMpMultiplier;
			CQACount(mainCharacter);
		}
		if (roleType == "Novice")
		{
			Novice novice;
			mainCharacter.roleType = "Послушник";

			mainCharacter.characteristics.physicalStrength += novice.physicalStrength;
			mainCharacter.characteristics.physicalStability += novice.physicalStability;
			mainCharacter.characteristics.magicalStrength += novice.magicalStrength;
			mainCharacter.characteristics.magicalStability += novice.magicalStability;
			mainCharacter.characteristics.agility += novice.agility;
			mainCharacter.characteristics.rhetoric += novice.rhetoric;
			mainCharacter.characteristics.luck += novice.luck;
			mainCharacter.characteristics.spirit += novice.spirit;
			mainCharacter.characteristics.endurance += novice.endurance;

			mainCharacter.characteristics.hpMultiplier = novice.hpMultiplier;
			mainCharacter.characteristics.mpMultiplier = novice.mpMultiplier;
			mainCharacter.characteristics.addHpMultiplier = novice.addHpMultiplier;
			mainCharacter.characteristics.addMpMultiplier = novice.addMpMultiplier;
			CQACount(mainCharacter);
		}
		if (roleType == "Mage")
		{
			Mage mage;
			mainCharacter.roleType = "Волшебник";

			mainCharacter.characteristics.physicalStrength += mage.physicalStrength;
			mainCharacter.characteristics.physicalStability += mage.physicalStability;
			mainCharacter.characteristics.magicalStrength += mage.magicalStrength;
			mainCharacter.characteristics.magicalStability += mage.magicalStability;
			mainCharacter.characteristics.agility += mage.agility;
			mainCharacter.characteristics.rhetoric += mage.rhetoric;
			mainCharacter.characteristics.luck += mage.luck;
			mainCharacter.characteristics.spirit += mage.spirit;
			mainCharacter.characteristics.endurance += mage.endurance;

			mainCharacter.characteristics.hpMultiplier = mage.hpMultiplier;
			mainCharacter.characteristics.mpMultiplier = mage.mpMultiplier;
			mainCharacter.characteristics.addHpMultiplier = mage.addHpMultiplier;
			mainCharacter.characteristics.addMpMultiplier = mage.addMpMultiplier;
			CQACount(mainCharacter);
		}
}