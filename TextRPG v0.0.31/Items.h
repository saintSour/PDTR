#pragma once
#include <string>



class Items
{
public:
	Items() //������ ������������ - ������ ����... ���������� ������� �������������� ������������, ���� ���� � ����������, ���������� ������� ����������� �� ID
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

	virtual ~Items() {}; //�����?
};

class ShortItem //��� ��������� ������������� ������ � ��������� �������
{
public:
	std::string title;
	int count;
	int ID;
};

class Weapon : public Items
{
public:
	Weapon()
	{
		this->title = "None";
		this->additionalType = "None";
		this->attack = 0;
	}
	std::string additionalType;
	int attack;
	std::string damageType;

	std::string additionalSkill;
};

class Armor : public Items
{
public:
	Armor()
	{
		this->title = "None";
		this->additionalType = "None";
		this->defence = 0;
	}
	std::string additionalType;
	int defence;

	std::string additionalSkill;
};

class Consumable : public Items
{
public:
	Consumable()
	{

	}
};

class Component : public Items
{
public:
	Component()
	{

	}
};

class QuestItem : public Items
{
public:
	QuestItem()
	{

	}
};

std::string GetItemType(int itemID);

ShortItem CreateShortItem(std::string title, int count, int ID);

Weapon CreateItem_Weapon(int itemID);

Armor CreateItem_Armor(int itemID);

Consumable CreateItem_Consumable(int itemID);

Component CreateItem_Component(int itemID);

QuestItem CreateItem_QuestItem(int itemID);
