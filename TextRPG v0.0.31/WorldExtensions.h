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
	std::vector<Items> HouseNearTheHills_Inventory;

	std::vector<Items> CastleGates_Inventory;

	std::vector<Items> GreenForest_Inventory;

	std::vector<Items> DeepForest_Inventory;

	std::vector<Items> GladeNearTheCity_Inventory;

	std::vector<Items> MagesTower_Inventory;

	std::vector<Items> CastleCenter_Inventory;

	std::vector<Items> GuildDistrict_Inventory;

	std::vector<Items> Marketplace_Inventory;

	std::vector<Items> Church_Inventory;

	std::vector<Items> BlackSmith_Inventory;

	std::vector<Items> CastleNook_Inventory;

	std::vector<Items> AdventurersGuild_Inventory;

	std::vector<Items> ArchersGuild_Inventory;

	std::vector<Items> RoguesGuild_Inventory; //15

	std::vector<Items> WarriorsGuild_Inventory;

	std::vector<Items>& FindLocation(maincharacter mainCharacter)
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

	void InventoryResize(std::vector<Items>& inventory) //изменение размера инвентаря при необходимости
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

	void InventoryRestack(std::vector<Items>* inventory) //перестановка(сортировка)
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

public://временно

	void DeleteItem(std::vector<Items>* locationInventory, int iterator)
	{
		if ((*locationInventory)[iterator].count > 1)
		{
			(*locationInventory)[iterator].count--;
		}
		else (*locationInventory).erase((*locationInventory).begin() + iterator);
	}

	void GetItem_location(maincharacter mainCharacter, Items item)//передать локации предмет
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
					(FindLocation(mainCharacter)).push_back(item);// будет ли дюп предметов?
					break;
				}
			}
		} else (FindLocation(mainCharacter)).push_back(item);
		InventoryRestack(&FindLocation(mainCharacter));
	}

	void GetItem(maincharacter mainCharacter, int itemID)
	{
		GetItem_location(mainCharacter, CreateItem(itemID));
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