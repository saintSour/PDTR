//���� ������ ���������
#include <vector>

#include "Items.h"



Items CreateItem(int itemID) //������� ����������
{
	Items newItem;
	switch (itemID)
	{
		{case 1001: //�����������, 
		{
			Items item(1001, 0, 1, true, 50, "������� �������������� ���������");//����
			newItem = item;
			break;
		}
		case 1002:
		{
			Items item(1002, 0, 1, false, 50, "������� ���������");
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