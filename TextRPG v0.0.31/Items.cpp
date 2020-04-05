//база данных предметов
#include <vector>

#include "Items.h"



Items CreateItem(int itemID) //ожидает реализации
{
	Items newItem;
	switch (itemID)
	{
		{case 1001: //предположим, 
		{
			Items item(1001, 0, 1, true, 50, "Мужской складывающийся настоящий");//тело
			newItem = item;
			break;
		}
		case 1002:
		{
			Items item(1002, 0, 1, false, 50, "Женский настоящий");
			newItem = item;
			break;
		}}
		{case 2001:
		{

			break;
		}
		case 2002:
		{

			break;
		}}
	}
	return newItem;
}