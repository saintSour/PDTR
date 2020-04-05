#pragma once
#include <string>

class Items
{
public:
	Items() //данные конструкторы - мёртвая тема... необходимо сделать многоуровневое наследование, либо базу с предметами, нахождение которых выполняется по ID
	{
		this->ID = 0; //
		this->count = 0;
		this->isStackable = true;
		this->cost = 0;
		this->durability = 0;
		this->title = "";
	}
	Items(int ID, int cost, int count, bool isStackable, int durability, std::string title)
	{
		this->ID = ID;
		this->count = count;
		this->isStackable = isStackable;
		this->cost = cost;
		this->durability = durability;
		this->title = title;
	}

	int ID;
	int count;
	bool isStackable;
	int cost;
	int durability;
	std::string title;
};

class Armor : public Items
{
public:
	int defence;
};

Items CreateItem(int itemID);
