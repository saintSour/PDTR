#include <Windows.h>

#include "Roles.h"
#include "World.h"
#include "WorldLocations.h"
#include "Attributes.h"
#include "game.h"
class maincharacter;
//
void CharacterMenu(maincharacter& mainCharacter, World& world)
{
	for (int goOut = 0; goOut == 0; )
	{
		system("cls");
		std::cout << "��������" << std::endl;
		std::cout << "1-�����\n2-��������������\n3-������ �����������\n4-��������� ����\n5-�������� �������� � �������\n0-������� ���� ��������� " << std::endl;
		int* chooseH = new int;
		std::cin >> *chooseH;
		switch (*chooseH)
		{
		case 1:
		{
			system("cls");
			delete chooseH;
			mainCharacter.inventory.InventoryShow(); //������������� ���������
			break;
		}
		case 2:
		{
			system("cls");
			delete chooseH;
			CQACount(mainCharacter);
			mainCharacter.MaincharacterInfo(mainCharacter);
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			delete chooseH;
			mainCharacter.skills.UseSkill_World(mainCharacter);//
			break;
		}
		case 4:
		{
			delete chooseH;
			world.DropItemOnTheGround(mainCharacter, world);
			break;
		}
		case 5:
		{
			delete chooseH;
			world.PickItemFromTheGround(mainCharacter, world);
			break;
		}
		case 0:
		{
			system("cls");
			delete chooseH;
			goOut = 1;
			break;
		}
		default:
		{
			std::cout << "�� �������... " << std::endl;
			system("pause");
			system("cls");
			delete chooseH;
			break;
		}
		}
	}
}
//

void EnterTheWorld(maincharacter& mainCharacter, World& world)
{
	HouseNearTheHills(mainCharacter, world);
}

void HouseNearTheHills(maincharacter& mainCharacter, World& world)
{ /**/ mainCharacter.SetLocation("HouseNearTheHills"); /**/
	mainCharacter.characterLevel = 10;
	GetRole(mainCharacter, "Warrior");
	mainCharacter.characterLevel = 20;
	mainCharacter.inventory.GetItem(1001);
	mainCharacter.inventory.GetItem(1001);
	mainCharacter.inventory.GetItem(2001);
	mainCharacter.inventory.GetItem(2001);
	mainCharacter.inventory.GetItem(3001);
	mainCharacter.inventory.GetItem(3001);
	mainCharacter.inventory.GetItem(4001);
	mainCharacter.inventory.GetItem(4001);
	mainCharacter.inventory.GetItem(5001);
	mainCharacter.inventory.GetItem(5001);
	//world.DropItemOnTheGround(mainCharacter, world);
	//world.PickItemFromTheGround(mainCharacter, world);
	system("cls");
	for (;;)
	{
		std::cout << "��� ����� ����� " << std::endl;

		std::cout << "��������, ���� �����: \n1-������ ������\n2-������ ���\n8-��������\n9-���������\n0-����� �� ����" << std::endl;
		int* choose = new int;
		std::cin >> *choose;
		switch (*choose)
		{
		case 1:
		{
			system("cls");
			delete choose;
			CastleGates(mainCharacter, world);
			break;
		}
		case 2:
		{
			system("cls");
			delete choose;
			GreenForest(mainCharacter, world);
			break;
		}
		case 8:
		{
			CharacterMenu(mainCharacter, world);
			delete choose;
			break;
		}
		case 9:
		{
			//settings()
			delete choose;
			break;
		}
		case 0:
		{
			//save();
			system("cls");
			delete choose;
			std::cout << "���� ����������... "; Sleep(1000); std::cout << "������ ����� ������ ����. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "� �� ���� ������ �����..." << std::endl;
			system("pause");
			system("cls");
			delete choose;
		}
		}
	}
}

void CastleGates(maincharacter& mainCharacter, World& world)
{ /**/ mainCharacter.SetLocation("CastleGates"); /**/
	//mainCharacter.inventory.GetItem(1001);
	//mainCharacter.inventory.GetItem(1002);
	//mainCharacter.inventory.GetItem(1001);
	//mainCharacter.inventory.GetItem(1002);
	//system("pause");
	//world.WorldInventory.GetItem(mainCharacter, 1001);
	//world.PickItemFromTheGround(mainCharacter, world);
	system("cls");
	for (;;)
	{
		std::cout << "������ ������ " << std::endl;
		std::cout << "��������, ���� �����: \n1-��������� �����\n2-������ �� �������\n3-������ ���\n8-��������\n9-���������\n0-����� �� ����" << std::endl;
		int* choose = new int;
		std::cin >> *choose;
		switch (*choose)
		{
		case 1:
		{
			system("cls");
			delete choose;
			CastleCenter(mainCharacter, world);
			break;
		}
		case 2:
		{
			system("cls");
			delete choose;
			GladeNearTheCity(mainCharacter, world);
			break;
		}
		case 3:
		{
			system("cls");
			delete choose;
			GreenForest(mainCharacter, world);
			break;
		}
		case 8:
		{
			CharacterMenu(mainCharacter, world);
			delete choose;
			break;
		}
		case 9:
		{
			//settings()
			delete choose;
			break;
		}
		case 0:
		{
			system("cls");
			delete choose;
			std::cout << "���� ����������... "; Sleep(1000); std::cout << "������ ����� ������ ����. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "� �� ���� ������ �����..." << std::endl;
			system("pause");
			system("cls");
			delete choose;
		}
		}
	}
}

void GreenForest(maincharacter& mainCharacter, World& world)
{ /**/ mainCharacter.SetLocation("GreenForest"); /**/
	system("cls");
	for (;;)
	{
		std::cout << "������ ��� " << std::endl;
		std::cout << "��������, ���� �����: \n1-������ ������\n2-������ ���\n8-��������\n9-���������\n0-����� �� ����" << std::endl;
		int* choose = new int;
		std::cin >> *choose;
		switch (*choose)
		{
		case 1:
		{
			system("cls");
			delete choose;
			CastleGates(mainCharacter, world);
			break;
		}
		case 2:
		{
			system("cls");
			delete choose;
			DeepForest(mainCharacter, world);
			break;
		}
		case 8:
		{
			CharacterMenu(mainCharacter, world);
			delete choose;
			break;
		}
		case 9:
		{
			//settings()
			delete choose;
			break;
		}
		case 0:
		{
			system("cls");
			delete choose;
			std::cout << "���� ����������... "; Sleep(1000); std::cout << "������ ����� ������ ����. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "� �� ���� ������ �����..." << std::endl;
			system("pause");
			system("cls");
			delete choose;
		}
		}
	}
}

void DeepForest(maincharacter& mainCharacter, World& world)
{ /**/ mainCharacter.SetLocation("DeepForest"); /**/
	system("cls");
	BattleAwakeCon(mainCharacter, "Hog", 1);
	for (;;)
	{
		std::cout << "������ ��� " << std::endl;
		std::cout << "��������, ���� �����: \n1-������ �� �������\n2-������ ���\n8-��������\n9-���������\n0-����� �� ����" << std::endl;
		int* choose = new int;
		std::cin >> *choose;
		switch (*choose)
		{
		case 1:
		{
			system("cls");
			delete choose;
			GladeNearTheCity(mainCharacter, world);
			break;
		}
		case 2:
		{
			system("cls");
			delete choose;
			GreenForest(mainCharacter, world);
			break;
		}
		case 8:
		{
			CharacterMenu(mainCharacter, world);
			delete choose;
			break;
		}
		case 9:
		{
			//settings()
			delete choose;
			break;
		}
		case 0:
		{
			system("cls");
			delete choose;
			std::cout << "���� ����������... "; Sleep(1000); std::cout << "������ ����� ������ ����. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "� �� ���� ������ �����..." << std::endl;
			system("pause");
			system("cls");
			delete choose;
		}
		}
	}
}

void GladeNearTheCity(maincharacter& mainCharacter, World& world)
{ /**/ mainCharacter.SetLocation("GladeNearTheCity"); /**/
	system("cls");
	for (;;)
	{
		std::cout << "������ �� ������� " << std::endl;
		std::cout << "��������, ���� �����: \n1-������ ������\n2-����� �����\n3-������ ���\n8-��������\n9-���������\n0-����� �� ����" << std::endl;
		int* choose = new int;
		std::cin >> *choose;
		switch (*choose)
		{
		case 1:
		{
			system("cls");
			delete choose;
			CastleGates(mainCharacter, world);
			break;
		}
		case 2:
		{
			system("cls");
			delete choose;
			MagesTower(mainCharacter, world);
			break;
		}
		case 3:
		{
			system("cls");
			delete choose;
			DeepForest(mainCharacter, world);
			break;
		}
		case 8:
		{
			CharacterMenu(mainCharacter, world);
			delete choose;
			break;
		}
		case 9:
		{
			//settings()
			delete choose;
			break;
		}
		case 0:
		{
			system("cls");
			delete choose;
			std::cout << "���� ����������... "; Sleep(1000); std::cout << "������ ����� ������ ����. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "� �� ���� ������ �����..." << std::endl;
			system("pause");
			system("cls");
			delete choose;
		}
		}
	}
}

void MagesTower(maincharacter& mainCharacter, World& world)
{ /**/ mainCharacter.SetLocation("MagesTower"); /**/
	system("cls");
	for (;;)
	{
		std::cout << "����� ����� " << std::endl;
		std::cout << "��������, ���� �����: \n1-������ �� �������\n8-��������\n9-���������\n0-����� �� ����" << std::endl;
		int* choose = new int;
		std::cin >> *choose;
		switch (*choose)
		{
		case 1:
		{
			system("cls");
			delete choose;
			GladeNearTheCity(mainCharacter, world);
			break;
		}
		case 8:
		{
			CharacterMenu(mainCharacter, world);
			delete choose;
			break;
		}
		case 9:
		{
			//settings()
			delete choose;
			break;
		}
		case 0:
		{
			system("cls");
			delete choose;
			std::cout << "���� ����������... "; Sleep(1000); std::cout << "������ ����� ������ ����. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "� �� ���� ������ �����..." << std::endl;
			system("pause");
			system("cls");
			delete choose;
		}
		}
	}
}

void CastleCenter(maincharacter& mainCharacter, World& world)
{ /**/ mainCharacter.SetLocation("CastleCenter"); /**/
	system("cls");
	for (;;)
	{
		std::cout << "����� ������ " << std::endl;
		std::cout << "��������, ���� �����: \n1-����� �������\n2-�����\n3-�������\n4-������\n5-��������(� ����������)\n6-������ ������\n8-��������\n9-���������\n0-����� �� ����" << std::endl;
		int* choose = new int;
		std::cin >> *choose;
		switch (*choose)
		{
		case 1:
		{
			system("cls");
			delete choose;
			GuildDistrict(mainCharacter, world);
			break;
		}
		case 2:
		{
			system("cls");
			delete choose;
			Marketplace(mainCharacter, world);
			break;
		}
		case 3:
		{
			system("cls");
			delete choose;
			Church(mainCharacter, world);
			break;
		}
		case 4:
		{
			system("cls");
			delete choose;
			BlackSmith(mainCharacter, world);
			break;
		}
		case 5:
		{
			system("cls");
			delete choose;
			CastleNook(mainCharacter, world);
			break;
		}
		case 6:
		{
			system("cls");
			delete choose;
			CastleGates(mainCharacter, world);
			break;
		}
		case 8:
		{
			CharacterMenu(mainCharacter, world);
			delete choose;
			break;
		}
		case 9:
		{
			//settings()
			delete choose;
			break;
		}
		case 0:
		{
			system("cls");
			delete choose;
			std::cout << "���� ����������... "; Sleep(1000); std::cout << "������ ����� ������ ����. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "� �� ���� ������ �����..." << std::endl;
			system("pause");
			system("cls");
			delete choose;
		}
		}
	}
}

void GuildDistrict(maincharacter& mainCharacter, World& world)
{ /**/ mainCharacter.SetLocation("GuildDistrict"); /**/
	system("cls");
	for (;;)
	{
		std::cout << "����� ������� " << std::endl;
		std::cout << "��������, ���� �����: \n1-������� ������������\n2-������� ��������\n3-������� ������\n4-������� ������\n5-����� ������\n8-��������\n9-���������\n0-����� �� ����" << std::endl;
		int* choose = new int;
		std::cin >> *choose;
		switch (*choose)
		{
		case 1:
		{
			system("cls");
			delete choose;
			AdventurersGuild(mainCharacter, world);
			break;
		}
		case 2:
		{
			system("cls");
			delete choose;
			ArchersGuild(mainCharacter, world);
			break;
		}
		case 3:
		{
			system("cls");
			delete choose;
			RoguesGuild(mainCharacter, world);
			break;
		}
		case 4:
		{
			system("cls");
			delete choose;
			WarriorsGuild(mainCharacter, world);
			break;
		}
		case 5:
		{
			system("cls");
			delete choose;
			CastleCenter(mainCharacter, world);
			break;
		}
		case 8:
		{
			CharacterMenu(mainCharacter, world);
			delete choose;
			break;
		}
		case 9:
		{
			//settings()
			delete choose;
			break;
		}
		case 0:
		{
			system("cls");
			delete choose;
			std::cout << "���� ����������... "; Sleep(1000); std::cout << "������ ����� ������ ����. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "� �� ���� ������ �����..." << std::endl;
			system("pause");
			system("cls");
			delete choose;
		}
		}
	}
}

void Marketplace(maincharacter& mainCharacter, World& world)
{ /**/ mainCharacter.SetLocation("Marketplace"); /**/
	system("cls");
	for (;;)
	{
		std::cout << "����� " << std::endl;
		std::cout << "��������, ���� �����: \n1-��������� �����\n2-��������\n8-��������\n9-���������\n0-����� �� ����" << std::endl;
		int* choose = new int;
		std::cin >> *choose;
		switch (*choose)
		{
		case 1:
		{
			system("cls");
			delete choose;
			CastleCenter(mainCharacter, world);
			break;
		}
		case 2:
		{
			system("cls");
			delete choose;
			std::cout << "����� ����� ����������� ��������" << std::endl;
			system("pause");
		}
		case 8:
		{
			CharacterMenu(mainCharacter, world);
			delete choose;
			break;
		}
		case 9:
		{
			//settings()
			delete choose;
			break;
		}
		case 0:
		{
			system("cls");
			delete choose;
			std::cout << "���� ����������... "; Sleep(1000); std::cout << "������ ����� ������ ����. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "� �� ���� ������ �����..." << std::endl;
			system("pause");
			system("cls");
			delete choose;
		}
		}
	}
}

void Church(maincharacter& mainCharacter, World& world)
{ /**/ mainCharacter.SetLocation("Church"); /**/
	system("cls");
	for (;;)
	{
		std::cout << "������� " << std::endl;
		std::cout << "��������, ���� �����: \n1-��������� �����\n2-����������\n8-��������\n9-���������\n0-����� �� ����" << std::endl;
		int* choose = new int;
		std::cin >> *choose;
		switch (*choose)
		{
		case 1:
		{
			system("cls");
			delete choose;
			CastleCenter(mainCharacter, world);
			break;
		}
		case 2:
		{
			system("cls");
			delete choose;
			std::cout << "����� ����� ����������� �������" << std::endl;
			system("pause");
		}
		case 8:
		{
			CharacterMenu(mainCharacter, world);
			delete choose;
			break;
		}
		case 9:
		{
			//settings()
			delete choose;
			break;
		}
		case 0:
		{
			system("cls");
			delete choose;
			std::cout << "���� ����������... "; Sleep(1000); std::cout << "������ ����� ������ ����. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "� �� ���� ������ �����..." << std::endl;
			system("pause");
			system("cls");
			delete choose;
		}
		}
	}
}

void BlackSmith(maincharacter& mainCharacter, World& world)
{ /**/ mainCharacter.SetLocation("BlackSmith"); /**/
	system("cls");
	for (;;)
	{
		std::cout << "������ " << std::endl;
		std::cout << "��������, ���� �����: \n1-��������� �����\n2-������\n8-��������\n9-���������\n0-����� �� ����" << std::endl;
		int* choose = new int;
		std::cin >> *choose;
		switch (*choose)
		{
		case 1:
		{
			system("cls");
			delete choose;
			CastleCenter(mainCharacter, world);
			break;
		}
		case 2:
		{
			system("cls");
			delete choose;
			std::cout << "����� ����� ����������� ��������� ����������" << std::endl;
			system("pause");
		}
		case 8:
		{
			CharacterMenu(mainCharacter, world);
			delete choose;
			break;
		}
		case 9:
		{
			//settings()
			delete choose;
			break;
		}
		case 0:
		{
			system("cls");
			delete choose;
			std::cout << "���� ����������... "; Sleep(1000); std::cout << "������ ����� ������ ����. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "� �� ���� ������ �����..." << std::endl;
			system("pause");
			system("cls");
			delete choose;
		}
		}
	}
}

void CastleNook(maincharacter& mainCharacter, World& world)
{ /**/ mainCharacter.SetLocation("CastleNook"); /**/
	system("cls");
	for (;;)
	{
		std::cout << "�������� " << std::endl;
		std::cout << "��������, ���� �����: \n1-��������� �����\n8-��������\n9-���������\n0-����� �� ����" << std::endl;
		int* choose = new int;
		std::cin >> *choose;
		switch (*choose)
		{
		case 1:
		{
			system("cls");
			delete choose;
			CastleCenter(mainCharacter, world);
			break;
		}
		case 8:
		{
			CharacterMenu(mainCharacter, world);
			delete choose;
			break;
		}
		case 9:
		{
			//settings()
			delete choose;
			break;
		}
		case 0:
		{
			system("cls");
			delete choose;
			std::cout << "���� ����������... "; Sleep(1000); std::cout << "������ ����� ������ ����. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "� �� ���� ������ �����..." << std::endl;
			system("pause");
			system("cls");
			delete choose;
		}
		}
	}
}

void AdventurersGuild(maincharacter& mainCharacter, World& world)
{ /**/ mainCharacter.SetLocation("AdventurersGuild"); /**/
	system("cls");
	for (;;)
	{
		std::cout << "������� ������������ " << std::endl;
		std::cout << "��������, ���� �����: \n1-����� �������\n2-����� �������\n3-���������\n8-��������\n9-���������\n0-����� �� ����" << std::endl;
		int* choose = new int;
		std::cin >> *choose;
		switch (*choose)
		{
		case 1:
		{
			system("cls");
			delete choose;
			GuildDistrict(mainCharacter, world);
			break;
		}
		case 2:
		{
			system("cls");
			delete choose;
			std::cout << "����� ����� ����������� ����� �������" << std::endl;
			break;
		}
		case 3:
		{
			system("cls");
			delete choose;
			std::cout << "����� ����� ����������� ���������" << std::endl;
			break;
		}
		case 8:
		{
			CharacterMenu(mainCharacter, world);
			delete choose;
			break;
		}
		case 9:
		{
			//settings()
			delete choose;
			break;
		}
		case 0:
		{
			system("cls");
			delete choose;
			std::cout << "���� ����������... "; Sleep(1000); std::cout << "������ ����� ������ ����. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "� �� ���� ������ �����..." << std::endl;
			system("pause");
			system("cls");
			delete choose;
		}
		}
	}
}

void ArchersGuild(maincharacter& mainCharacter, World& world)
{ /**/ mainCharacter.SetLocation("ArchersGuild"); /**/
	system("cls");
	for (;;)
	{
		std::cout << "������� �������� " << std::endl;
		std::cout << "��������, ���� �����: \n1-����� �������\n2-��������� ��������\n8-��������\n9-���������\n0-����� �� ����" << std::endl;
		int* choose = new int;
		std::cin >> *choose;
		switch (*choose)
		{
		case 1:
		{
			system("cls");
			delete choose;
			GuildDistrict(mainCharacter, world);
			break;
		}
		case 2:
		{
			system("cls");
			delete choose;
			std::cout << "����� ����� ���������� ��������� ��������" << std::endl;
			break;
		}
		case 8:
		{
			CharacterMenu(mainCharacter, world);
			delete choose;
			break;
		}
		case 9:
		{
			//settings()
			delete choose;
			break;
		}
		case 0:
		{
			system("cls");
			delete choose;
			std::cout << "���� ����������... "; Sleep(1000); std::cout << "������ ����� ������ ����. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "� �� ���� ������ �����..." << std::endl;
			system("pause");
			system("cls");
			delete choose;
		}
		}
	}
}

void RoguesGuild(maincharacter& mainCharacter, World& world)
{ /**/ mainCharacter.SetLocation("RoguesGuild"); /**/
	system("cls");
	for (;;)
	{
		std::cout << "������� ������" << std::endl;
		std::cout << "��������, ���� �����: \n1-����� �������\n2-��������� ������\n8-��������\n9-���������\n0-����� �� ����" << std::endl;
		int* choose = new int;
		std::cin >> *choose;
		switch (*choose)
		{
		case 1:
		{
			system("cls");
			delete choose;
			GuildDistrict(mainCharacter, world);
			break;
		}
		case 2:
		{
			system("cls");
			delete choose;
			std::cout << "����� ����� ���������� ��������� ������" << std::endl;
			break;
		}
		case 8:
		{
			CharacterMenu(mainCharacter, world);
			delete choose;
			break;
		}
		case 9:
		{
			//settings()
			delete choose;
			break;
		}
		case 0:
		{
			system("cls");
			delete choose;
			std::cout << "���� ����������... "; Sleep(1000); std::cout << "������ ����� ������ ����. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "� �� ���� ������ �����..." << std::endl;
			system("pause");
			system("cls");
			delete choose;
		}
		}
	}
}

void WarriorsGuild(maincharacter& mainCharacter, World& world)
{ /**/ mainCharacter.SetLocation("WarriorsGuild"); /**/
	system("cls");
	for (;;)
	{
		std::cout << "������� �������� " << std::endl;
		std::cout << "��������, ���� �����: \n1-����� �������\n2-��������� ��������\n8-��������\n9-���������\n0-����� �� ����" << std::endl;
		int* choose = new int;
		std::cin >> *choose;
		switch (*choose)
		{
		case 1:
		{
			system("cls");
			delete choose;
			GuildDistrict(mainCharacter, world);
			break;
		}
		case 2:
		{
			system("cls");
			delete choose;
			std::cout << "����� ����� ���������� ��������� ��������" << std::endl;
			break;
		}
		case 8:
		{
			CharacterMenu(mainCharacter, world);
			delete choose;
			break;
		}
		case 9:
		{
			//settings()
			delete choose;
			break;
		}
		case 0:
		{
			system("cls");
			delete choose;
			std::cout << "���� ����������... "; Sleep(1000); std::cout << "������ ����� ������ ����. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "� �� ���� ������ �����..." << std::endl;
			system("pause");
			system("cls");
			delete choose;
		}
		}
	}
}