#pragma once

//#include "Inventory.h"
#include "WorldExtensions.h"

class World
{
public:
	World()
	{

	}

	WorldInventory WorldInventory;
	Time WorldTime;

	void DropItemOnTheGround(maincharacter& mainCharacter, World& world)// *выбросить на землю*
	{
		if (!(mainCharacter.inventory._Empty()))
		{
			int tempChoose = mainCharacter.inventory.DropItemSub();
			if (tempChoose != -1)
			{
				this->WorldInventory.GetItem_location(mainCharacter, mainCharacter.inventory.GetItemAlloc(tempChoose));
				mainCharacter.inventory.DeleteItem(tempChoose);
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