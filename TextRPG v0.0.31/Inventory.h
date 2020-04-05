#pragma once
#include <iostream> //необходимо пересмотреть выводы данный через std::sout
#include <vector>

//#include "Roles.h"
#include "Items.h"

class Inventory //реализация инвентаря
{
public: Inventory()
{

}
private:
	std::vector<Items> inventory;

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
		/*for (int i = 0; i < size; i++) //debug
		{
			std::cout << inventory[i].ID << std::endl;
		}*/
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
				inventory.erase(inventory.end() - 1); //доделать увеличение
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
		std::cout << "Вы получили "<< newItem.title << std::endl;
		system("pause");
		system("cls");
	}

	void InventoryShow()
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
	}
};