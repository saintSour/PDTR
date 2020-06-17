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
		this->title = "";
		this->description = "";
		this->type = "";
	}
	Items(int ID, int cost, int count, bool isStackable, std::string title, std::string description, std::string type)
	{
		this->ID = ID;
		this->count = count;
		this->isStackable = isStackable;
		this->cost = cost;
		this->title = title;
		this->description = description;
		this->type = type;
	}

	int ID;
	int count;
	bool isStackable;
	int cost;
	
	std::string title;
	std::string description;
	std::string type;

	virtual ~Items() {};
};

class ShortItem //для короткого представления игрока в инвентаре локаций
{
public:
	std::string title;
	int count;
	int ID;
};

class Weapon : public Items
{
public:
	int attack;
};

class Armor : public Items
{
public:
	int defence;
};

class Consumable : public Items
{
public:
	
};

class Component : public Items
{
public:
	
};

class QuestItem : public Items
{
public:
	
};

std::string GetItemType(int itemID);

ShortItem CreateShortItem(std::string title, int count, int ID);

Weapon CreateItem_Weapon(int itemID);

Armor CreateItem_Armor(int itemID);

Consumable CreateItem_Consumable(int itemID);

Component CreateItem_Component(int itemID);

QuestItem CreateItem_QuestItem(int itemID);
