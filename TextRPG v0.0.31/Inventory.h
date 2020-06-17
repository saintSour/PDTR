#pragma once
#include <iostream> //необходимо пересмотреть выводы данных через std::cout
#include <vector>

#include "Items.h"

//////Для спокойствия компилятора//////
//#include "SUBSYSTEM_CLASSES.h"/////
//#include "World.h"
//////Для спокойствия компилятора//////

class Inventory //реализация инвентаря
{
public:
	Inventory()
	{

	}
	friend class World;

private:
//protected:
	std::vector<Weapon> weapon_inventory;
	std::vector<Armor> armor_inventory;
	std::vector<Consumable> consumables_inventory;
	std::vector<Component> components_inventory;
	std::vector<QuestItem> questItems_inventory;

private:
	template <typename T>
	void InventoryRestack(std::vector<T>& inventory) //перестановка(сортировка)
	{
		int size = inventory.size();
		for (int i = 0; i < size; i++)
		{
			if (inventory[i].ID == 0000)
			{

				for (int j = i; j < (size - 1); j++)
				{
					inventory[j] = inventory[(size_t(j) + 1)];
				}
				inventory[(size_t(size) - 1)].ID = 0;
			}
		}
		//for (int i = 0; i < size; i++) //debug
		//{
		//	std::cout << inventory[i].ID << std::endl;
		//}
		std::cout << "\n\n\n";
		InventoryResize(inventory);
	}
	template <typename T>
	void InventoryResize(std::vector<T>& inventory) //изменение размера инвентаря при необходимости
	{
		int size = inventory.size();
		if (size == 0) inventory.resize(1); 
		else
		{
			while (inventory[(size - 1)].ID == 0) //
			{
				inventory.erase(inventory.end() - 1);
				//inventory.resize(--size);
				size--;
			}
			//if () inventory.resize(size + 1);
		}
	}
	template <typename T>
	int GetElenementsCount(std::vector<T> inventory)
	{
		int counter = 0;
		if (inventory.size() != 0)
		{
			for (int i = 0; i < inventory.size(); i++)
			{
				counter += inventory[i].count;
			}
		}
		return counter;
	}

public:

	void GetItem(int ItemID)
	{
		std::string tempItemType = GetItemType(ItemID);
		if (tempItemType == "Weapon")
		{
			InventoryResize(this->weapon_inventory);
			Weapon newItem = CreateItem_Weapon(ItemID);
			for (size_t i = 0; i <= (this->weapon_inventory.size() - 1); i++)
			{
				if (this->weapon_inventory[i].title == newItem.title && newItem.isStackable)
				{
					this->weapon_inventory[i].count += 1;
					break;
				}
				else
				{
					newItem.count = 1;
					this->weapon_inventory.push_back(newItem);
					break;
				}
			}
			InventoryRestack(this->weapon_inventory);
			std::cout << "Вы получили " << newItem.title << std::endl;
		}
		if (tempItemType == "Armor")
		{
			InventoryResize(this->armor_inventory);
			Armor newItem = CreateItem_Armor(ItemID);
			for (size_t i = 0; i <= (this->armor_inventory.size() - 1); i++)
			{
				if (this->armor_inventory[i].title == newItem.title && newItem.isStackable)
				{
					this->armor_inventory[i].count += 1;
					break;
				}
				else
				{
					newItem.count = 1;
					this->armor_inventory.push_back(newItem);
					break;
				}
			}
			InventoryRestack(this->armor_inventory);
			std::cout << "Вы получили " << newItem.title << std::endl;
		}
		if (tempItemType == "Consumable")
		{
			InventoryResize(this->consumables_inventory);
			Consumable newItem = CreateItem_Consumable(ItemID);
			for (size_t i = 0; i <= (this->consumables_inventory.size() - 1); i++)
			{
				if (this->consumables_inventory[i].title == newItem.title && newItem.isStackable)
				{
					this->consumables_inventory[i].count += 1;
					break;
				}
				else
				{
					newItem.count = 1;
					this->consumables_inventory.push_back(newItem);
					break;
				}
			}
			InventoryRestack(this->consumables_inventory);
			std::cout << "Вы получили " << newItem.title << std::endl;
		}
		if (tempItemType == "Component")
		{
			InventoryResize(this->components_inventory);
			Component newItem = CreateItem_Component(ItemID);
			for (size_t i = 0; i <= (this->components_inventory.size() - 1); i++)
			{
				if (this->components_inventory[i].title == newItem.title && newItem.isStackable)
				{
					this->components_inventory[i].count += 1;
					break;
				}
				else
				{
					newItem.count = 1;
					this->components_inventory.push_back(newItem);
					break;
				}
			}
			InventoryRestack(this->components_inventory);
			std::cout << "Вы получили " << newItem.title << std::endl;
		}
		if (tempItemType == "QuestItem")
		{
			InventoryResize(this->questItems_inventory);
			QuestItem newItem = CreateItem_QuestItem(ItemID);
			for (size_t i = 0; i <= (this->questItems_inventory.size() - 1); i++)
			{
				if (this->questItems_inventory[i].title == newItem.title && newItem.isStackable)
				{
					this->questItems_inventory[i].count += 1;
					break;
				}
				else
				{
					newItem.count = 1;
					this->questItems_inventory.push_back(newItem);
					break;
				}
			}
			InventoryRestack(this->questItems_inventory);
			std::cout << "Вы получили " << newItem.title << std::endl;
		}
		system("pause");
		system("cls");
	}

protected:

	int DropItemSub(std::string& tempType) //Выбрасывание вещей в локацию
	{
		system("cls");
		if (!(this->weapon_inventory.empty()) && !(this->armor_inventory.empty()) && !(this->consumables_inventory.empty()) && !(this->components_inventory.empty()) && !(this->questItems_inventory.empty()))
		{
			std::cout << "Что мне выбросить? " << std::endl;
			int tempCounter = 0;
			for (int i = 0; i < this->weapon_inventory.size(); i++)
			{
				std::cout << (tempCounter + 1) << ") " << this->weapon_inventory[i].title << std::endl;
				tempCounter++;
			}
			for (int i = 0; i < this->armor_inventory.size(); i++)
			{
				std::cout << (tempCounter + 1) << ") " << this->armor_inventory[i].title << std::endl;
				tempCounter++;
			}
			for (int i = 0; i < this->consumables_inventory.size(); i++)
			{
				std::cout << (tempCounter + 1) << ") " << this->consumables_inventory[i].title << std::endl;
				tempCounter++;
			}
			for (int i = 0; i < this->components_inventory.size(); i++)
			{
				std::cout << (tempCounter + 1) << ") " << this->components_inventory[i].title << std::endl;
				tempCounter++;
			}
			for (int i = 0; i < this->questItems_inventory.size(); i++)
			{
				std::cout << (tempCounter + 1) << ") " << this->questItems_inventory[i].title << std::endl;
				tempCounter++;
			}

			int choose;
			std::cin >> choose;
			if ((choose > (this->weapon_inventory.size() + this->armor_inventory.size() + this->consumables_inventory.size() + this->components_inventory.size() + this->questItems_inventory.size())) || (choose < 1)) 
			{ 
				system("cls"); 
				std::cout << "Я не понимаю..." << std::endl;
				system("pause"); 
				system("cls"); 
				return (-1);
			}
			else
			{
				if ((choose - 1) < weapon_inventory.size())
				{
					tempType = "Weapon";
					system("cls");
					return (choose - 1);
				} else
				if (/*(choose - 1) > weapon_inventory.size() &&*/ (choose - 1) < (armor_inventory.size() + weapon_inventory.size()))
				{
					tempType = "Armor";
					system("cls");
					return (choose - weapon_inventory.size() - 1);
				} else
				if (/*(choose - 1) > armor_inventory.size() &&*/ (choose - 1) < (consumables_inventory.size() + armor_inventory.size() + weapon_inventory.size()))
				{
					tempType = "Consumable";
					system("cls");
					return (choose - weapon_inventory.size() - armor_inventory.size() - 1);
				} else
				if (/*(choose - 1) > consumables_inventory.size() &&*/ (choose - 1) < (components_inventory.size() + consumables_inventory.size() + armor_inventory.size() + weapon_inventory.size()))
				{
					tempType = "Component";
					system("cls");
					return (choose - weapon_inventory.size() - armor_inventory.size() - consumables_inventory.size() - 1);
				} else
				if (/*(choose - 1) > components_inventory.size() &&*/ (choose - 1) < (questItems_inventory.size() + components_inventory.size() + consumables_inventory.size() + armor_inventory.size() + weapon_inventory.size()))
				{
					tempType = "QuestItem";
					system("cls");
					return (choose - weapon_inventory.size() - armor_inventory.size() - consumables_inventory.size() - components_inventory.size() - 1);
				}
			};
		}
	}

public:

	void DeleteItem(int iterator, std::string type)
	{
		if (type == "Weapon")
		{
			if (this->weapon_inventory[iterator].count > 1)
			{
				this->weapon_inventory[iterator].count--;
			}
			else this->weapon_inventory.erase(this->weapon_inventory.begin() + iterator);
		}
		if (type == "Armor")
		{
			if (this->armor_inventory[iterator].count > 1)
			{
				this->armor_inventory[iterator].count--;
			}
			else this->armor_inventory.erase(this->armor_inventory.begin() + iterator);
		}
		if (type == "Consumable")
		{
			if (this->consumables_inventory[iterator].count > 1)
			{
				this->consumables_inventory[iterator].count--;
			}
			else this->consumables_inventory.erase(this->consumables_inventory.begin() + iterator);
		}
		if (type == "Component")
		{
			if (this->components_inventory[iterator].count > 1)
			{
				this->components_inventory[iterator].count--;
			}
			else this->components_inventory.erase(this->components_inventory.begin() + iterator);
		}
		if (type == "QuestItem")
		{
			if (this->questItems_inventory[iterator].count > 1)
			{
				this->questItems_inventory[iterator].count--;
			}
			else this->questItems_inventory.erase(this->questItems_inventory.begin() + iterator);
		}
	}

	Weapon GetItemAlloc_Weapon(int iterator, std::string type)
	{
		return this->weapon_inventory[iterator];
	}
	Armor GetItemAlloc_Armor(int iterator, std::string type)
	{
		return this->armor_inventory[iterator];
	}
	Consumable GetItemAlloc_Consumable(int iterator, std::string type)
	{
		return this->consumables_inventory[iterator];
	}
	Component GetItemAlloc_Component(int iterator, std::string type)
	{
		return this->components_inventory[iterator];
	}
	QuestItem GetItemAlloc_QuestItem(int iterator, std::string type)
	{
		return this->questItems_inventory[iterator];
	}

	bool _Empty(std::string type)
	{
		if (type == "Weapon")
		{
			if (this->weapon_inventory.empty())
			{
				return true;
			}
			else return false;
		}
		if (type == "Armor")
		{
			if (this->armor_inventory.empty())
			{
				return true;
			}
			else return false;
		}
		if (type == "Consumable")
		{
			if (this->consumables_inventory.empty())
			{
				return true;
			}
			else return false;
		}
		if (type == "Component")
		{
			if (this->components_inventory.empty())
			{
				return true;
			}
			else return false;
		}
		if (type == "QuestItem")
		{
			if (this->questItems_inventory.empty())
			{
				return true;
			}
			else return false;
		}
	}

	bool _Empty()
	{
		if (this->weapon_inventory.empty() && this->armor_inventory.empty() && this->consumables_inventory.empty() && this->components_inventory.empty() && this->questItems_inventory.empty())
		{
			return true;
		}
		else return false;
	}

	void InventoryShow()//Показать инвентарь
	{
		system("cls");
		int tempSize1 = this->weapon_inventory.size();
		int tempSize2 = this->armor_inventory.size();
		int tempSize3 = this->consumables_inventory.size();
		int tempSize4 = this->components_inventory.size();
		int tempSize5 = this->questItems_inventory.size();
		int tempCounter = 0;
			if (tempSize1 != 0)
			for (int i = 0; i < tempSize1; i++)
			{
				std::cout << (i + 1) << ") " << this->weapon_inventory[i].title;
				if (this->weapon_inventory[i].count > 1) std::cout << " Количество:" << this->weapon_inventory[i].count;
				std::cout << std::endl;
				tempCounter++;
			}
		if (tempSize2 != 0)
			for (int i = 0; i < tempSize2; i++)
			{
				std::cout << (tempCounter + 1) << ") " << this->armor_inventory[i].title;
				if (this->armor_inventory[i].count > 1) std::cout << " Количество:" << this->armor_inventory[i].count;
				std::cout << std::endl;
				tempCounter++;
			}
		if (tempSize3 != 0)
			for (int i = 0; i < tempSize3; i++)
			{
				std::cout << (tempCounter + 1) << ") " << this->consumables_inventory[i].title;
				if (this->consumables_inventory[i].count > 1) std::cout << " Количество:" << this->consumables_inventory[i].count;
				std::cout << std::endl;
				tempCounter++;
			}
		if (tempSize4 != 0)
			for (int i = 0; i < tempSize4; i++)
			{
				std::cout << (tempCounter + 1) << ") " << this->components_inventory[i].title;
				if (this->components_inventory[i].count > 1) std::cout << " Количество:" << this->components_inventory[i].count;
				std::cout << std::endl;
				tempCounter++;
			}
		if (tempSize5 != 0)
			for (int i = 0; i < tempSize5; i++)
			{
				std::cout << (tempCounter + 1) << ") " << this->questItems_inventory[i].title;
				if (this->questItems_inventory[i].count > 1) std::cout << " Количество:" << this->questItems_inventory[i].count;
				std::cout << std::endl;
				tempCounter++;
			}
		system("pause");
		system("cls");
	}
};