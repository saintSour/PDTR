#pragma once
#include <vector>
#include <string>
#include <iostream>

//#include "Roles.h"
//#include "Items.h"
//#include "WorldLocations.h"

class WorldInventory
{
public:

private:
	std::vector<ShortItem> HouseNearTheHills_Inventory; //название, количество, ID

	std::vector<ShortItem> CastleGates_Inventory;

	std::vector<ShortItem> GreenForest_Inventory;

	std::vector<ShortItem> DeepForest_Inventory;

	std::vector<ShortItem> GladeNearTheCity_Inventory;

	std::vector<ShortItem> MagesTower_Inventory;

	std::vector<ShortItem> CastleCenter_Inventory;

	std::vector<ShortItem> GuildDistrict_Inventory;

	std::vector<ShortItem> Marketplace_Inventory;

	std::vector<ShortItem> Church_Inventory;

	std::vector<ShortItem> BlackSmith_Inventory;

	std::vector<ShortItem> CastleNook_Inventory;

	std::vector<ShortItem> AdventurersGuild_Inventory;

	std::vector<ShortItem> ArchersGuild_Inventory;

	std::vector<ShortItem> RoguesGuild_Inventory; //15

	std::vector<ShortItem> WarriorsGuild_Inventory;

	std::vector<ShortItem>& FindLocation(maincharacter mainCharacter)
	{
		if (mainCharacter.GetLocation() == "HouseNearTheHills") return HouseNearTheHills_Inventory;
		if (mainCharacter.GetLocation() == "CastleGates")	    return CastleGates_Inventory;
		if (mainCharacter.GetLocation() == "GreenForest")	    return GreenForest_Inventory;
		if (mainCharacter.GetLocation() == "DeepForest")	    return DeepForest_Inventory;
		if (mainCharacter.GetLocation() == "GladeNearTheCity")  return GladeNearTheCity_Inventory;
		if (mainCharacter.GetLocation() == "MagesTower")	    return MagesTower_Inventory;
		if (mainCharacter.GetLocation() == "CastleCenter")	    return CastleCenter_Inventory;
		if (mainCharacter.GetLocation() == "GuildDistrict")	    return GuildDistrict_Inventory;
		if (mainCharacter.GetLocation() == "Marketplace")	    return Marketplace_Inventory;
		if (mainCharacter.GetLocation() == "Church")			return Church_Inventory;

		if (mainCharacter.GetLocation() == "BlackSmith")		return BlackSmith_Inventory;
		if (mainCharacter.GetLocation() == "CastleNook")		return CastleNook_Inventory;
		if (mainCharacter.GetLocation() == "AdventurersGuild")  return AdventurersGuild_Inventory;
		if (mainCharacter.GetLocation() == "ArchersGuild")	    return ArchersGuild_Inventory;
		if (mainCharacter.GetLocation() == "RoguesGuild")	    return RoguesGuild_Inventory;
		if (mainCharacter.GetLocation()== "WarriorsGuild")	    return WarriorsGuild_Inventory;
	}

	void InventoryResize(std::vector<ShortItem>& inventory) //изменение размера инвентаря при необходимости
	{
		int size = inventory.size();
		if (size == 0) inventory.resize(0);
		else
		{
			while (inventory[(size - 1)].ID == 0)
			{
				inventory.erase(inventory.end() - 1);
				//inventory.resize(--size);
				size--;
			}
			//if () inventory.resize(size + 1);
		};
	};

	void InventoryRestack(std::vector<ShortItem>* inventory) //перестановка(сортировка)
	{
		int size = (*inventory).size();
		for (int i = 0; i < size; i++)
		{
			if ((*inventory)[i].ID == 0000)
			{

				for (int j = i; j < (size - 1); j++)
				{
					(*inventory)[j] = (*inventory)[(size_t(j) + 1)];
				}
				(*inventory)[(size_t(size) - 1)].ID = 0;
			}
		}
		//for (int i = 0; i < size; i++) //debug
		//{
		//	std::cout << inventory[i].ID << std::endl;
		//}
		InventoryResize(*inventory);
	}

	void InventoryRestack_ALL()
	{
		//InventoryRestack();
	}

	void DeleteItem(std::vector<ShortItem>* locationInventory, int iterator)
	{
		if ((*locationInventory)[iterator].count > 1)
		{
			(*locationInventory)[iterator].count--;
		}
		else (*locationInventory).erase((*locationInventory).begin() + iterator);
	}

public://временно

	template <class T>
	void GetItem_location(maincharacter mainCharacter, T item)//передать локации предмет
	{
		//InventoryResize(FindLocation(mainCharacter));
		if (!(FindLocation(mainCharacter).empty()))
		{
			for (size_t i = 0; i <= ((FindLocation(mainCharacter)).size() - 1); i++)
			{
				if (FindLocation(mainCharacter)[i].title == item.title && item.isStackable)
				{
					FindLocation(mainCharacter)[i].count += 1;
					break;
				}
				else
				{
					(FindLocation(mainCharacter)).push_back(CreateShortItem(item.title, 1 /*item.count*/, item.ID));// будет ли дюп предметов?
					break;
				}
			}
		} else (FindLocation(mainCharacter)).push_back(CreateShortItem(item.title, 1 /*item.count*/, item.ID));
		InventoryRestack(&FindLocation(mainCharacter));
	}

	void GetItem(maincharacter mainCharacter, int itemID)
	{
		std::string tempType = GetItemType(itemID);
		if (tempType == "Weapon")
		{
			GetItem_location(mainCharacter, CreateItem_Weapon(itemID));
		}
		if (tempType == "Armor")
		{
			GetItem_location(mainCharacter, CreateItem_Armor(itemID));
		}
		if (tempType == "Consumable")
		{
			GetItem_location(mainCharacter, CreateItem_Consumable(itemID));
		}
		if (tempType == "Component")
		{
			GetItem_location(mainCharacter, CreateItem_Component(itemID));
		}
		if (tempType == "QuestItem")
		{
			GetItem_location(mainCharacter, CreateItem_QuestItem(itemID));
		}
	}

public:

	void TakeItem_location(maincharacter& mainCharacter)//получить предмет из локации
	{
		//InventoryResize(FindLocation(mainCharacter));
		system("cls");
		if (!(FindLocation(mainCharacter).empty()))
		{
			std::cout << "Что мне поднять? " << std::endl;
			for (int i = 0; i < FindLocation(mainCharacter).size(); i++)
			{
				std::cout << (i + 1) << ") " << FindLocation(mainCharacter)[i].title << std::endl;
			}
			int choose;
			std::cin >> choose;
			if ((choose > FindLocation(mainCharacter).size()) || (choose < 1)) { system("cls"); std::cout << "Я не понимаю..." << std::endl; system("pause"); system("cls"); }
			else
			{
				system("cls");
				mainCharacter.inventory.GetItem((FindLocation(mainCharacter)[(choose - 1)].ID));
				DeleteItem(&FindLocation(mainCharacter), (choose - 1));
				InventoryRestack(&FindLocation(mainCharacter));

			};
		}
		else std::cout << "Я ничего не нашёл..." << std::endl;
		system("pause");
		system("cls");
		//InventoryRestack(&FindLocation(mainCharacter));
	}
};

class Time
{
private:

	int years;
	int days;
	int hours;
	int minutes;
public:
	Time()
	{
		this->years = 0;
		this->days = 0;
		this->hours = 0;
		this->minutes = 0;
	}
protected:

	void AddTimeYears(int years)
	{
		this->years += years;
		TimeSort();
	}
	void AddTimeDays(int days)
	{
		this->days += days;
		TimeSort();
	}
	void AddTimeHours(int hours)
	{
		this->hours += hours;
		TimeSort();
	}
	void AddTimeMinutes(int minutes)
	{
		this->minutes += minutes;
		TimeSort();
	}
	void TimeSort()
	{
		if (this->minutes >= 60)
		{
			this->minutes -= 60;
			this->hours += 1;
		}
		if (this->hours >= 24)
		{
			this->hours -= 24;
			this->days += 1;
		}
		if (this->days >= 365)
		{
			this->days -= 365;
			this->years += 1;
		}
	}
public:
	void TimeShow()
	{
		TimeSort();
		std::cout << this->years << " год   " << "День " << this->days << "  " << this->hours << ":" << this->minutes << std::endl;
	}
};