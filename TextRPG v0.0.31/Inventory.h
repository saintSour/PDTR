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
	std::vector<Items> inventory;

private:

	void InventoryRestack(std::vector<Items>& inventory) //перестановка(сортировка)
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

	void InventoryResize(std::vector<Items>& inventory) //изменение размера инвентаря при необходимости
	{
		int size = inventory.size();
		if (size == 0) inventory.resize(1); 
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

public:

	void GetItem(int ItemID)
	{
		InventoryResize(this->inventory);
		Items newItem = CreateItem(ItemID);
		for (size_t i = 0; i <= (this->inventory.size() - 1); i++)
		{
			if (this->inventory[i].title == newItem.title && newItem.isStackable)
			{
				this->inventory[i].count += 1;
				break;
			}
			else
			{
				this->inventory.push_back(newItem);
				break;
			}
		}
		InventoryRestack(this->inventory);
		std::cout << "Вы получили " << newItem.title << std::endl;
		system("pause");
		system("cls");
	}

protected:

	int DropItemSub() //Выбрасывание вещей в локацию
	{
		system("cls");
		if (!(this->inventory.empty()))
		{
			std::cout << "Что мне выбросить? " << std::endl;
			for (int i = 0; i < this->inventory.size(); i++)
			{
				std::cout << (i + 1) << ") " << this->inventory[i].title << std::endl;
			}
			int choose;
			std::cin >> choose;
			if ((choose > this->inventory.size()) || (choose < 1)) { system("cls"); std::cout << "Я не понимаю..." << std::endl; system("pause"); system("cls"); return (-1); }
			else
			{
				system("cls");
				return (choose - 1);
			};
		}
	}

public:

	void DeleteItem(int iterator)
	{
		if (this->inventory[iterator].count > 1) 
		{
			this->inventory[iterator].count--;
		}
		else this->inventory.erase(this->inventory.begin() + iterator);
	}

	Items GetItemAlloc(int iterator)
	{
		return this->inventory[iterator];
	}

	bool _Empty()
	{
		if (this->inventory.empty())
		{
			return true;
		}
		else return false;
	}

	void InventoryShow()//Показать инвентарь
	{
		system("cls");
		int size = this->inventory.size();
		if (size == 0) std::cout << "Мои карманы пусты " << std::endl;
		else for (int i = 0; i < size; i++)
		{
			std::cout << (i + 1) << ") " << this->inventory[i].title;
			if (this->inventory[i].count > 1) std::cout << " Количество:" << this->inventory[i].count;
			std::cout << std::endl;
		}
		system("pause");
		system("cls");
	}
};
