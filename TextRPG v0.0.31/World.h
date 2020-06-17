#pragma once

//#include "Inventory.h"
#include "WorldExtensions.h"

class World
{
public:
	World()
	{

	}
	friend maincharacter;

	WorldInventory WorldInventory;
	Time WorldTime;

	void DropItemOnTheGround(maincharacter& mainCharacter, World& world)// *выбросить на землю*
	{
		if (!(mainCharacter.inventory._Empty()))
		{
			std::string tempType;
			int tempChoose = mainCharacter.inventory.DropItemSub(tempType);
			if (tempChoose != -1)
			{
				if (tempType == "Weapon")
				{
					this->WorldInventory.GetItem_location(mainCharacter, mainCharacter.inventory.GetItemAlloc_Weapon(tempChoose, tempType));
					mainCharacter.inventory.DeleteItem(tempChoose, tempType);
				}
				if (tempType == "Armor")
				{
					this->WorldInventory.GetItem_location(mainCharacter, mainCharacter.inventory.GetItemAlloc_Armor(tempChoose, tempType));
					mainCharacter.inventory.DeleteItem(tempChoose, tempType);
				}
				if (tempType == "Consumable")
				{
					this->WorldInventory.GetItem_location(mainCharacter, mainCharacter.inventory.GetItemAlloc_Consumable(tempChoose, tempType));
					mainCharacter.inventory.DeleteItem(tempChoose, tempType);
				}
				if (tempType == "Component")
				{
					this->WorldInventory.GetItem_location(mainCharacter, mainCharacter.inventory.GetItemAlloc_Component(tempChoose, tempType));
					mainCharacter.inventory.DeleteItem(tempChoose, tempType);
				}
				if (tempType == "QuestItem")
				{
					this->WorldInventory.GetItem_location(mainCharacter, mainCharacter.inventory.GetItemAlloc_QuestItem(tempChoose, tempType));
					mainCharacter.inventory.DeleteItem(tempChoose, tempType);
				}
			}
		}
	}

	void PickItemFromTheGround(maincharacter& mainCharacter, World& world)// *поднять с земли*
	{
		//if (!(mainCharacter.inventory._Empty()))
		//{
		this->WorldInventory.TakeItem_location(mainCharacter);
		//}
	}
};