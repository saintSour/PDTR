//база данных предметов
#include <vector>

#include "Items.h"



std::string GetItemType(int itemID) //ожидает реализации
{
	std::string tempType;
	switch (itemID)
	{
		case 1001: //предположим, что так
		{
			tempType = "Weapon";
			break;
		}
		case 2001:
		{
			tempType = "Armor";
			break;
		}
		case 3001:
		{
			tempType = "Consumable";
			break;
		}
		case 4001:
		{
			tempType = "Component";
			break;
		}
		case 5001:
		{
			tempType = "QuestItem";
			break;
		}
	}
	return tempType;
}

ShortItem CreateShortItem(std::string title, int count, int ID)
{
	ShortItem tempShortItem;
	tempShortItem.title = title;
	tempShortItem.count = count;
	tempShortItem.ID = ID;
	return tempShortItem;
}

Weapon CreateItem_Weapon(int itemID) //Доделать это пиздец срочно
{
	Weapon newItem;
	newItem.ID = itemID;
	newItem.type = "Weapon";
	switch (itemID)
	{
	case 1001:
		newItem.title = "Оружие";
		newItem.description = "";
		break;
	}
	return newItem;
}
Armor CreateItem_Armor(int itemID)
{
	Armor newItem;
	newItem.ID = itemID;
	newItem.type = "Armor";
	switch (itemID)
	{
	case 2001:
		newItem.title = "Броня";
		newItem.description = "";
		break;
	}
	return newItem;
}
Consumable CreateItem_Consumable(int itemID)
{
	Consumable newItem;
	newItem.ID = itemID;
	newItem.type = "Consumable";
	switch (itemID)
	{
	case 3001:
		newItem.title = "Расходник";
		newItem.description = "";
		break;
	}
	return newItem;
}
Component CreateItem_Component(int itemID)
{
	Component newItem;
	newItem.ID = itemID;
	newItem.type = "Component";
	switch (itemID)
	{
	case 4001:
		newItem.title = "Компонент";
		newItem.description = "";
		break;
	}
	return newItem;
}
QuestItem CreateItem_QuestItem(int itemID)
{
	QuestItem newItem;
	newItem.ID = itemID;
	newItem.type = "QuestItem";
	switch (itemID)
	{
	case 5001:
		newItem.title = "Квестовый предмет";
		newItem.description = "";
		break;
	}
	return newItem;
}