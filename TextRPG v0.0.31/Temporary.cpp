#include <iostream>
#include <vector>

// инвентарь

void InventoryResize(std::vector<int>& inventory);

void InventoryRestack(std::vector<int>& inventory);

void InventoryRestack(std::vector<int>& inventory) //перестановка(сортировка)
{
	int size = inventory.size();
	for (int i = 0; i < size; i++)
	{
		if (inventory[i] == 0000)
		{

			for (int j = i; j < (size - 1); j++)
			{
				inventory[j] = inventory[(size_t(j) + 1)];
			}
			inventory[(size_t(size) - 1)] = 0;
		}
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << inventory[i] << std::endl;
	}
	std::cout << "\n\n\n";
	InventoryResize(inventory);
}

void InventoryResize(std::vector<int>& inventory) //изменение размера инвентаря при необходимости
{
	int size = inventory.size();
	if (size == 0) inventory.resize(1);
	else
	{

			while (inventory[--size] == 0)
			{
				inventory.erase(inventory.end() - 1); //доделать увеличение
				inventory.resize(--size);
				size--;
			}
			//if () inventory.resize(size + 1);
	};
}

void GetItem(std::vector<int>& inventory, int ItemID)
{
	inventory.push_back(ItemID);
	InventoryRestack(inventory);
}

void tempMain2()
{
	std::vector<int> inventory{10, 35, 84, 0, 15, 6, 600, 0, 35, 8, 9, 15, 0, 4, 654, 0, 34, 0, 1}; //Инвентарь
	inventory.reserve(10);
	InventoryRestack(inventory);

	for (size_t i = 0; i < inventory.size(); i++) //явное приведение для галочки и лишней потери данных
	{
		std::cout << inventory[i] << std::endl;
	}
	std::cout << "\n\n\n";

	GetItem(inventory, 54);

	for (size_t i = 0; i < inventory.size(); i++) //явное приведение для галочки и лишней потери данных
	{
		std::cout << inventory[i] << std::endl;
	}
}







//система боя
class aCtors
{
public:
	std::string name;
	int initiative = 0;
	aCtors()
	{
		this->name = " ";
		this->initiative = 0;
	}
	aCtors(std::string name, int initiative)
	{
		this->name = name;
		this->initiative = initiative;
	}
};

void quickSort(std::vector<aCtors>& actors, int left, int right)
{
	int i = left, j = (right - 1);
	aCtors temp;
	int pivot = (actors[((i+j) / 2)].initiative);


	while (i <= j)
	{
		while (actors[i].initiative < pivot)
			i++;
		while (actors[j].initiative > pivot)
			j--;
		if (i <= j)
		{
			temp = actors[i];

			actors[i] = actors[j];

			actors[j] = temp;

			i++;
			j--;
		}
	};


	if (left < j)
		quickSort(actors, left, j);
	if (i < right)
		quickSort(actors, i, right);

}

void tempMain1()
{
	std::vector<aCtors> actors{ {"Alpha", 6}, { "Beta", 10 }, { "Gamma", 4 }, { "Delta", 7 }, {"Epsilon", 13}, {"Zeta", 17} };

	quickSort(actors, 0, actors.size());

	for (size_t i = 0; i < actors.size(); i++) //явное приведение для галочки и лишней потери данных
	{
		std::cout << actors[i].name << "\t" << actors[i].initiative << std::endl;
	}
}