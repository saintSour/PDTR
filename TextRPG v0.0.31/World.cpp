#include <Windows.h>

#include "Roles.h"
#include "World.h"
#include "BattleSystem.h"
#include "Attributes.h"
#include "game.h"

//
void CharacterMenu(maincharacter& mainCharacter)
{
	for (int goOut = 0; goOut == 0; )
	{
		system("cls");
		std::cout << "��������" << std::endl;
		std::cout << "1-�����\n2-��������������\n3-������ �����������\n4-������� ���� ��������� " << std::endl;
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
			std::cout << mainCharacter.roleType << std::endl;
			std::cout << "������� = " << mainCharacter.characterLevel << std::endl;
			std::cout << "���� �������� = " << mainCharacter.hitPoints << '/' << mainCharacter.maxHitPoints << std::endl;
			std::cout << "���� ���� = " << mainCharacter.manaPoints << '/' << mainCharacter.maxManaPoints << std::endl;
			std::cout << "���������� ���� = " << mainCharacter.physicalDamage << std::endl;
			std::cout << "���������� ���� = " << mainCharacter.magicalDamage << std::endl;
			std::cout << "���� ������������ ����� = " << mainCharacter.criticalChance << " %" << std::endl;
			std::cout << "������� ������������ ����� = " << mainCharacter.criticalRate << std::endl;
			std::cout << "���� ������������ = " << mainCharacter.blockChance << " %" << std::endl;
			std::cout << "���� ��������� = " << mainCharacter.dodgeChance << " %" << std::endl;
			std::cout << "�������� = " << mainCharacter.accuracy << std::endl;
			std::cout << "���������� ����� �������� = " << mainCharacter.maxActionPoints << std::endl;
			std::cout << "���������� ��������� ����� �������� = " << mainCharacter.maxRoleActionPoints << std::endl;
			std::cout << "���������� ��������� = " << mainCharacter.physicalStability << std::endl;
			std::cout << "���������� ��������� = " << mainCharacter.magicalStability << std::endl;
			std::cout << "���������� ���� = " << mainCharacter.physicalStrength << std::endl;
			std::cout << "���������� ���� = " << mainCharacter.magicalStrength << std::endl;
			std::cout << "�������� = " << mainCharacter.agility << std::endl;
			std::cout << "����������� = " << mainCharacter.rhetoric << std::endl;
			std::cout << "����� = " << mainCharacter.luck << std::endl;
			std::cout << "��� = " << mainCharacter.spirit << std::endl;
			std::cout << "������������ = " << mainCharacter.endurance << std::endl;
			std::cout << "���������� = " << mainCharacter.initiative << std::endl;
			std::cout << "���������� = " << mainCharacter.visibility << std::endl;
			std::cout << "������������ ��� = " << mainCharacter.maxWeight << std::endl;
			std::cout << "���� ��������� ���� = " << mainCharacter.dropChance << " %" << std::endl;
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			delete chooseH;
			mainCharacter.skills.UseSkill(mainCharacter);//
			break;
		}
		case 4:
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
{
	mainCharacter.characterLevel = 10;
	GetRole(mainCharacter, "Warrior");
	mainCharacter.characterLevel = 20;
	mainCharacter.skills.GetSkill("BandageWounds");
	mainCharacter.skills.GetSkill("DoubleStrike");
	CQACount(mainCharacter);
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
			CharacterMenu(mainCharacter);
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
{
	/*mainCharacter.inventory.GetItem(1001);
	mainCharacter.inventory.GetItem(1002);
	mainCharacter.inventory.GetItem(1001);
	mainCharacter.inventory.GetItem(1002);
	system("pause");
	*/
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
			CharacterMenu(mainCharacter);
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
{
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
			CharacterMenu(mainCharacter);
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
{
	system("cls");
	//BattleAwakeCon(mainCharacter, "Snake", 4);
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
			CharacterMenu(mainCharacter);
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
{
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
			CharacterMenu(mainCharacter);
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
{
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
			CharacterMenu(mainCharacter);
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
{
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
			CharacterMenu(mainCharacter);
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
{
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
			CharacterMenu(mainCharacter);
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
{
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
			CharacterMenu(mainCharacter);
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
{
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
			CharacterMenu(mainCharacter);
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
{
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
			CharacterMenu(mainCharacter);
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
{
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
			CharacterMenu(mainCharacter);
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
{
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
			CharacterMenu(mainCharacter);
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
{
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
			CharacterMenu(mainCharacter);
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
{
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
			CharacterMenu(mainCharacter);
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
{
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
			CharacterMenu(mainCharacter);
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