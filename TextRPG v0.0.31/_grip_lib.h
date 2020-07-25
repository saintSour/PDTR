#pragma once
#include "Roles.h"
//#include "Items.h"

/*void Equipment::PutOn(Weapon equipment, maincharacter& mainCharacter)
{
	if (equipment.additionalType == "Two-Handed")
	{
		if (this->LeftHand.title == "None" && this->RightHand.title == "None")
		{
			this->RightHand = equipment;
			this->LeftHand = equipment;
			this->LeftHand.type = this->LeftHand.type + "_ALT";
		}
		else 
			if (this->LeftHand.title != "None" && this->RightHand.title != "None")
			{
				std::cout << "�� �������, ��� ������ �������� " << this->RightHand.title << ' � ' << this->LeftHand.title << " �� ��������� ������ " << equipment.title << '?' << std::endl;
				std::cout << "1 - ��, 2 - ���" << std::endl;
				int choose;
				std::cin >> choose;
				if (choose == 1)
				{
					mainCharacter.inventory.GetItem_WithoutDeclaring(this->RightHand.ID);
					mainCharacter.inventory.GetItem_WithoutDeclaring(this->LeftHand.ID);
					this->RightHand = equipment;
					this->LeftHand = equipment;
					this->LeftHand.type = this->LeftHand.type + "_ALT";
				}
			} 
			else
				if (this->LeftHand.title == "None" || this->RightHand.title == "None")
				{
					std::string hand;
					std::string title;
					if (this->LeftHand.title == "None") { hand = "������"; title = this->RightHand.title; };
					if (this->RightHand.title == "None") { hand = "�����"; title = this->LeftHand.title; };
					std::cout << "�� �������, ��� ������ �������� " << title << " � " << hand << " ���� �� ��������� ������ " << equipment.title << '?' << std::endl;
					std::cout << "1 - ��, 2 - ���" << std::endl;
					int choose;
					std::cin >> choose;
					if (choose == 1)
					{
						if (this->LeftHand.title == "None") mainCharacter.inventory.GetItem_WithoutDeclaring(this->RightHand.ID);
						if (this->RightHand.title == "None") mainCharacter.inventory.GetItem_WithoutDeclaring(this->LeftHand.ID);
						this->RightHand = equipment;
						this->LeftHand = equipment;
						this->LeftHand.type = this->LeftHand.type + "_ALT";
					}
				}
	}
	else if (equipment.additionalType == "One-Handed")
	{
		std::cout << "� ����� ���� ����� ����������� " << equipment.title << " ?" << std::endl;
		std::cout << "1 - ������ ����, 2 - ������ ����" << std::endl;
		int choose;
		std::cin >> choose;
		if (choose == 1)
		{
			if (this->RightHand.title == "None")
			{
				this->RightHand = equipment;
			}
			else
			{
				int choose;
				std::cout << "�� �������, ��� ������ �������� " << this->RightHand.title << " � ������ ���� �� " << equipment.title << '?' << std::endl;
				std::cout << "1 - ��, 2 - ���" << std::endl;
				std::cin >> choose;
				if (choose == 1)
				{
					mainCharacter.inventory.GetItem_WithoutDeclaring(this->RightHand.ID);
					this->RightHand = equipment;
				}
			}
		}
		if (choose == 0)
		{
			if (this->LeftHand.title == "None")
			{
				this->LeftHand = equipment;
			}
			else
			{
				int choose;
				std::cout << "�� �������, ��� ������ �������� " << this->LeftHand.title << " � ����� ���� �� " << equipment.title << '?' << std::endl;
				std::cout << "1 - ��, 2 - ���" << std::endl;
				std::cin >> choose;
				if (choose == 1)
				{
					mainCharacter.inventory.GetItem_WithoutDeclaring(this->LeftHand.ID);
					this->LeftHand = equipment;
				}
			}
		}
	}
	system("cls");
}

void Equipment::PutOn(Armor equipment, maincharacter& mainCharacter)
{
	std::string title = equipment.title;

	if (equipment.additionalType == "Head")
	{
		if (this->Head.title == "None")
		{
			this->Head = equipment;
		}
		else
		{
			std::cout << "�� ������ �������� " << title << " �� " << equipment.title << '?' << std::endl;
			std::cout << "1 - ��, 0 - ���" << std::endl;
			int choose;
			std::cin >> choose;
			if (choose == 1) ResetArmor(equipment, &mainCharacter);//������� ��� ������ ������
		}
	}
	if (equipment.additionalType == "Shoulders")
	{
		if (this->Shoulders.title == "None")
		{
			this->Shoulders = equipment;
		}
		else
		{
			std::cout << "�� ������ �������� " << title << " �� " << equipment.title << '?' << std::endl;
			std::cout << "1 - ��, 0 - ���" << std::endl;
			int choose;
			std::cin >> choose;
			if (choose == 1) ResetArmor(equipment, &mainCharacter);//������� ��� ������ ������
		}
	}
	if (equipment.additionalType == "ShouldersCover")
	{
		if (this->ShouldersCover.title == "None")
		{
			this->ShouldersCover = equipment;
		}
		else
		{
			std::cout << "�� ������ �������� " << title << " �� " << equipment.title << '?' << std::endl;
			std::cout << "1 - ��, 0 - ���" << std::endl;
			int choose;
			std::cin >> choose;
			if (choose == 1) ResetArmor(equipment, &mainCharacter);//������� ��� ������ ������
		}
	}
	if (equipment.additionalType == "Torso")
	{
		if (this->Torso.title == "None")
		{
			this->Torso = equipment;
		}
		else
		{
			std::cout << "�� ������ �������� " << title << " �� " << equipment.title << '?' << std::endl;
			std::cout << "1 - ��, 0 - ���" << std::endl;
			int choose;
			std::cin >> choose;
			if (choose == 1) ResetArmor(equipment, &mainCharacter);//������� ��� ������ ������
		}
	}
	if (equipment.additionalType == "TorsoCover")
	{
		if (this->TorsoCover.title == "None")
		{
			this->TorsoCover = equipment;
		}
		else
		{
			std::cout << "�� ������ �������� " << title << " �� " << equipment.title << '?' << std::endl;
			std::cout << "1 - ��, 0 - ���" << std::endl;
			int choose;
			std::cin >> choose;
			if (choose == 1) ResetArmor(equipment, &mainCharacter);//������� ��� ������ ������
		}
	}
	if (equipment.additionalType == "Forearm")
	{
		if (this->Forearm.title == "None")
		{
			this->Forearm = equipment;
		}
		else
		{
			std::cout << "�� ������ �������� " << title << " �� " << equipment.title << '?' << std::endl;
			std::cout << "1 - ��, 0 - ���" << std::endl;
			int choose;
			std::cin >> choose;
			if (choose == 1) ResetArmor(equipment, &mainCharacter);//������� ��� ������ ������
		}
	}
	if (equipment.additionalType == "Wrist")
	{
		if (this->Wrist.title == "None")
		{
			this->Wrist = equipment;
		}
		else
		{
			std::cout << "�� ������ �������� " << title << " �� " << equipment.title << '?' << std::endl;
			std::cout << "1 - ��, 0 - ���" << std::endl;
			int choose;
			std::cin >> choose;
			if (choose == 1) ResetArmor(equipment, &mainCharacter);//������� ��� ������ ������
		}
	}
	if (equipment.additionalType == "Gaiters")
	{
		if (this->Gaiters.title == "None")
		{
			this->Gaiters = equipment;
		}
		else
		{
			std::cout << "�� ������ �������� " << title << " �� " << equipment.title << '?' << std::endl;
			std::cout << "1 - ��, 0 - ���" << std::endl;
			int choose;
			std::cin >> choose;
			if (choose == 1) ResetArmor(equipment, &mainCharacter);//������� ��� ������ ������
		}
	}
	if (equipment.additionalType == "Shin")
	{
		if (this->Shin.title == "None")
		{
			this->Shin = equipment;
		}
		else
		{
			std::cout << "�� ������ �������� " << title << " �� " << equipment.title << '?' << std::endl;
			std::cout << "1 - ��, 0 - ���" << std::endl;
			int choose;
			std::cin >> choose;
			if (choose == 1) ResetArmor(equipment, &mainCharacter);//������� ��� ������ ������
		}
	}
	if (equipment.additionalType == "Shoes")
	{
		if (this->Shoes.title == "None")
		{
			this->Shoes = equipment;
		}
		else
		{
			std::cout << "�� ������ �������� " << title << " �� " << equipment.title << '?' << std::endl;
			std::cout << "1 - ��, 0 - ���" << std::endl;
			int choose;
			std::cin >> choose;
			if (choose == 1) ResetArmor(equipment, &mainCharacter);//������� ��� ������ ������
		}
	}
}

void Equipment::PutOff(Weapon equipment, maincharacter& mainCharacter, std::string arm)
{
	if (equipment.additionalType == "Two-Handed")
	{
		mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
		Weapon weapon;
		this->RightHand = weapon;
		this->LeftHand = weapon;
	}
	if (equipment.additionalType == "One-Handed")
	{
		if (arm == "Right")
		{
			mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
			Weapon weapon;
			this->RightHand = weapon;
		}
		else
		if (arm == "Left")
		{
			mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
			Weapon weapon;
			this->LeftHand = weapon;
		}
	}
}

void Equipment::PutOff(Armor equipment, maincharacter& mainCharacter)
{
	if (equipment.additionalType == "Head")
	{
		mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
		Armor armor;
		this->Head = armor;
	}
	if (equipment.additionalType == "Shoulders")
	{
		mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
		Armor armor;
		this->Shoulders = armor;
	}
	if (equipment.additionalType == "ShouldersCover")
	{
		mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
		Armor armor;
		this->ShouldersCover = armor;
	}
	if (equipment.additionalType == "Torso")
	{
		mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
		Armor armor;
		this->Torso = armor;
	}
	if (equipment.additionalType == "TorsoCover")
	{
		mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
		Armor armor;
		this->TorsoCover = armor;
	}
	if (equipment.additionalType == "Forearm")
	{
		mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
		Armor armor;
		this->Forearm = armor;
	}
	if (equipment.additionalType == "Wrist")
	{
		mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
		Armor armor;
		this->Wrist = armor;
	}
	if (equipment.additionalType == "Gaiters")
	{
		mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
		Armor armor;
		this->Gaiters = armor;
	}
	if (equipment.additionalType == "Shin")
	{
		mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
		Armor armor;
		this->Shin = armor;
	}
	if (equipment.additionalType == "Shoes")
	{
		mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
		Armor armor;
		this->Shoes = armor;
	}
}

void Equipment::ResetArmor(Armor equipment, maincharacter* mainCharacter)//��������������� �������
{
	if (equipment.additionalType == "Head")
	{
		(*mainCharacter).inventory.GetItem_WithoutDeclaring(this->Head.ID);
		this->Head = equipment;
	}
	if (equipment.additionalType == "Shoulders")
	{
		(*mainCharacter).inventory.GetItem_WithoutDeclaring(this->Shoulders.ID);
		this->Shoulders = equipment;
	}
	if (equipment.additionalType == "ShouldersCover")
	{
		(*mainCharacter).inventory.GetItem_WithoutDeclaring(this->ShouldersCover.ID);
		this->ShouldersCover = equipment;
	}
	if (equipment.additionalType == "Torso")
	{
		(*mainCharacter).inventory.GetItem_WithoutDeclaring(this->Torso.ID);
		this->Torso = equipment;
	}
	if (equipment.additionalType == "TorsoCover")
	{
		(*mainCharacter).inventory.GetItem_WithoutDeclaring(this->TorsoCover.ID);
		this->TorsoCover = equipment;
	}
	if (equipment.additionalType == "Forearm")
	{
		(*mainCharacter).inventory.GetItem_WithoutDeclaring(this->Forearm.ID);
		this->Forearm = equipment;
	}
	if (equipment.additionalType == "Wrist")
	{
		(*mainCharacter).inventory.GetItem_WithoutDeclaring(this->Wrist.ID);
		this->Wrist = equipment;
	}
	if (equipment.additionalType == "Gaiters")
	{
		(*mainCharacter).inventory.GetItem_WithoutDeclaring(this->Gaiters.ID);
		this->Gaiters = equipment;
	}
	if (equipment.additionalType == "Shin")
	{
		(*mainCharacter).inventory.GetItem_WithoutDeclaring(this->Shin.ID);
		this->Shin = equipment;
	}
	if (equipment.additionalType == "Shoes")
	{
		(*mainCharacter).inventory.GetItem_WithoutDeclaring(this->Shoes.ID);
		this->Shoes = equipment;
	}
}

Weapon Equipment::GetEquipment(Weapon equipment, maincharacter& mainCharacter)
{
	system("cls");
	int j = 1;//�������������� �������� ��� ���������� ������������ �� ���� ���������
	std::vector<Weapon> tempVec;

	for (size_t i = 0; i < mainCharacter.inventory.weapon_inventory.size(); i++)
	{
		if (equipment.additionalType == mainCharacter.inventory.weapon_inventory[i].additionalType)
		{
			std::cout << j << ") " << mainCharacter.inventory.weapon_inventory[i].title << std::endl;
			j++;
			tempVec.push_back(mainCharacter.inventory.weapon_inventory[i]);
		}
	}

	int choose;

	std::cout << std::endl << "����� ������� ����� �������?" << std::endl;
	std::cin >> choose;
	choose--;
	
	return tempVec[choose];
}

Armor Equipment::GetEquipment(Armor equipment, maincharacter& mainCharacter)
{
	system("cls");
	Armor armor;////
	return armor;////
}

void Equipment::Equip_ASSIST(Weapon equipment, maincharacter& mainCharacter, std::string arm)
{
	int choose;
	std::cout << "��� ���-�� ����� ������ " << equipment.title << " ��� ������ ������ ���?" << std::endl;
	std::cout << "1 - ��������, 2 - �����" << std::endl;
	std::cin >> choose;

	if (choose == 1)
	{
		PutOn(GetEquipment(equipment, mainCharacter), mainCharacter);
	}
	if (choose == 2) PutOff(equipment, mainCharacter, arm);
}

void Equipment::Equip_ASSIST(Armor equipment, maincharacter& mainCharacter)
{
	int choose;
	std::cout << "��� ���-�� ������ ������ " << equipment.title << " ��� ������ ����� � ���� ���?" << std::endl;
	std::cout << "1 - ��������, 2 - �����" << std::endl;
	std::cin >> choose;

	if (choose == 1)
	{
		PutOn(GetEquipment(equipment, mainCharacter), mainCharacter);
	}
	if (choose == 2) PutOff(equipment, mainCharacter);
}

void Equipment::ShowClothes(maincharacter& mainCharacter)
{
	std::cout << "      " << "��������" << std::endl;
	std::cout << "������: " << this->Head.title << std::endl;
	std::cout << "�����: " << this->Shoulders.title << std::endl;
	std::cout << "������ ������: " << this->ShouldersCover.title << std::endl;
	std::cout << "����: " << this->Torso.title << std::endl;
	std::cout << "������ �����: " << this->TorsoCover.title << std::endl;
	std::cout << "����������: " << this->Forearm.title << std::endl;
	std::cout << "�����: " << this->Wrist.title << std::endl;
	std::cout << "������������: " << this->Gaiters.title << std::endl;
	std::cout << "������: " << this->Shin.title << std::endl;
	std::cout << "������: " << this->Shoes.title << std::endl;

	if (this->RightHand.additionalType != "Two-Handed")
	{
		std::cout << "������ ����: " << this->RightHand.title << std::endl;
		std::cout << "����� ����: " << this->LeftHand.title << std::endl;
	}
	else
	{
		std::cout << "����: " << this->RightHand.title << std::endl;
	}
	
	int choose;
	std::cout << "��� ������� ������� ����������?" << std::endl;
	std::cin >> choose;
	if (choose == 1)
	{
		system("cls");
		ChangeClothes(mainCharacter);
	}
}

void Equipment::ChangeClothes(maincharacter& mainCharacter)
{
	std::cout << "      " << "��������" << std::endl;
	std::cout << "1) ������: " << this->Head.title << std::endl;
	std::cout << "2) �����: " << this->Shoulders.title << std::endl;
	std::cout << "3) ������ ������: " << this->ShouldersCover.title << std::endl;
	std::cout << "4) ����: " << this->Torso.title << std::endl;
	std::cout << "5) ������ �����: " << this->TorsoCover.title << std::endl;
	std::cout << "6) ����������: " << this->Forearm.title << std::endl;
	std::cout << "7) �����: " << this->Wrist.title << std::endl;
	std::cout << "8) ������������: " << this->Gaiters.title << std::endl;
	std::cout << "9) ������: " << this->Shin.title << std::endl;
	std::cout << "10) ������: " << this->Shoes.title << std::endl;

	if (this->RightHand.additionalType != "Two-Handed")
	{
		std::cout << "11) ������ ����: " << this->RightHand.title << std::endl;
		std::cout << "12) ����� ����: " << this->LeftHand.title << std::endl;
	}
	else
	{
		std::cout << "11) ����: " << this->RightHand.title << std::endl;
	}

	int choose;
	std::cout << "����� ������� ���������� ��� ������� ������������?" << std::endl;
	std::cin >> choose;

	switch (choose)
	{
	case 1:
	{
		Equip_ASSIST(this->Head, mainCharacter);
		break;
	}
	case 2:
	{
		Equip_ASSIST(this->Shoulders, mainCharacter);
		break;
	}
	case 3:
	{
		Equip_ASSIST(this->ShouldersCover, mainCharacter);
		break;
	}
	case 4:
	{
		Equip_ASSIST(this->Torso, mainCharacter);
		break;
	}
	case 5:
	{
		Equip_ASSIST(this->TorsoCover, mainCharacter);
		break;
	}
	case 6:
	{
		Equip_ASSIST(this->Forearm, mainCharacter);
		break;
	}
	case 7:
	{
		Equip_ASSIST(this->Wrist, mainCharacter);
		break;
	}
	case 8:
	{
		Equip_ASSIST(this->Gaiters, mainCharacter);
		break;
	}
	case 9:
	{
		Equip_ASSIST(this->Shin, mainCharacter);
		break;
	}
	case 10:
	{
		Equip_ASSIST(this->Shoes, mainCharacter);
		break;
	}
	case 11:
	{
		Equip_ASSIST(this->RightHand, mainCharacter, "Right");////
		break;
	}
	case 12:
	{
		Equip_ASSIST(this->RightHand, mainCharacter, "Left");////
		break;
	}
	default:
		break;
	}
}
*/

namespace EM_Coupling
{
	void ResetArmor(Armor equipment, maincharacter* mainCharacter, Equipment* gear)//��������������� �������
	{
		if (equipment.additionalType == "Head")
		{
			(*mainCharacter).inventory.GetItem_WithoutDeclaring((*gear).GetHead().ID);
			(*gear).GetHead() = equipment;
		}
		if (equipment.additionalType == "Shoulders")
		{
			(*mainCharacter).inventory.GetItem_WithoutDeclaring((*gear).GetShoulders().ID);
			(*gear).GetShoulders() = equipment;
		}
		if (equipment.additionalType == "ShouldersCover")
		{
			(*mainCharacter).inventory.GetItem_WithoutDeclaring((*gear).GetShouldersCover().ID);
			(*gear).GetShouldersCover() = equipment;
		}
		if (equipment.additionalType == "Torso")
		{
			(*mainCharacter).inventory.GetItem_WithoutDeclaring((*gear).GetTorso().ID);
			(*gear).GetTorso() = equipment;
		}
		if (equipment.additionalType == "TorsoCover")
		{
			(*mainCharacter).inventory.GetItem_WithoutDeclaring((*gear).GetTorsoCover().ID);
			(*gear).GetTorsoCover() = equipment;
		}
		if (equipment.additionalType == "Forearm")
		{
			(*mainCharacter).inventory.GetItem_WithoutDeclaring((*gear).GetForearm().ID);
			(*gear).GetForearm() = equipment;
		}
		if (equipment.additionalType == "Wrist")
		{
			(*mainCharacter).inventory.GetItem_WithoutDeclaring((*gear).GetWrist().ID);
			(*gear).GetWrist() = equipment;
		}
		if (equipment.additionalType == "Gaiters")
		{
			(*mainCharacter).inventory.GetItem_WithoutDeclaring((*gear).GetGaiters().ID);
			(*gear).GetGaiters() = equipment;
		}
		if (equipment.additionalType == "Shin")
		{
			(*mainCharacter).inventory.GetItem_WithoutDeclaring((*gear).GetShin().ID);
			(*gear).GetShin() = equipment;
		}
		if (equipment.additionalType == "Shoes")
		{
			(*mainCharacter).inventory.GetItem_WithoutDeclaring((*gear).GetShoes().ID);
			(*gear).GetShoes() = equipment;
		}
	}

	void PutOn(Weapon equipment, maincharacter& mainCharacter, Equipment& gear)
	{
		if (equipment.additionalType == "Two-Handed")
		{
			if (gear.GetLeftHand().title == "None" && gear.GetRightHand().title == "None")
			{
				gear.GetRightHand() = equipment;
				gear.GetLeftHand() = equipment;
				gear.GetLeftHand().type = gear.GetLeftHand().type + "_ALT";
			}
			else
				if (gear.GetLeftHand().title != "None" && gear.GetRightHand().title != "None")
				{
					std::cout << "�� �������, ��� ������ �������� " << gear.GetRightHand().title << ' � ' << gear.GetLeftHand().title << " �� ��������� ������ " << equipment.title << '?' << std::endl;
					std::cout << "1 - ��, 2 - ���" << std::endl;
					int choose;
					std::cin >> choose;
					if (choose == 1)
					{
						mainCharacter.inventory.GetItem_WithoutDeclaring(gear.GetRightHand().ID);
						mainCharacter.inventory.GetItem_WithoutDeclaring(gear.GetLeftHand().ID);
						gear.GetRightHand() = equipment;
						gear.GetLeftHand() = equipment;
						gear.GetLeftHand().type = gear.GetLeftHand().type + "_ALT";
					}
				}
				else
					if (gear.GetLeftHand().title == "None" || gear.GetRightHand().title == "None")
					{
						std::string hand;
						std::string title;
						if (gear.GetLeftHand().title == "None") { hand = "������"; title = gear.GetRightHand().title; };
						if (gear.GetRightHand().title == "None") { hand = "�����"; title = gear.GetLeftHand().title; };
						std::cout << "�� �������, ��� ������ �������� " << title << " � " << hand << " ���� �� ��������� ������ " << equipment.title << '?' << std::endl;
						std::cout << "1 - ��, 2 - ���" << std::endl;
						int choose;
						std::cin >> choose;
						if (choose == 1)
						{
							if (gear.GetLeftHand().title == "None") mainCharacter.inventory.GetItem_WithoutDeclaring(gear.GetRightHand().ID);
							if (gear.GetRightHand().title == "None") mainCharacter.inventory.GetItem_WithoutDeclaring(gear.GetLeftHand().ID);
							gear.GetRightHand() = equipment;
							gear.GetLeftHand() = equipment;
							gear.GetLeftHand().type = gear.GetLeftHand().type + "_ALT";
						}
					}
		}
		else if (equipment.additionalType == "One-Handed")
		{
			std::cout << "� ����� ���� ����� ����������� " << equipment.title << " ?" << std::endl;
			std::cout << "1 - ������ ����, 2 - ������ ����" << std::endl;
			int choose;
			std::cin >> choose;
			if (choose == 1)
			{
				if (gear.GetRightHand().title == "None")
				{
					gear.GetRightHand() = equipment;
				}
				else
				{
					int choose;
					std::cout << "�� �������, ��� ������ �������� " << gear.GetRightHand().title << " � ������ ���� �� " << equipment.title << '?' << std::endl;
					std::cout << "1 - ��, 2 - ���" << std::endl;
					std::cin >> choose;
					if (choose == 1)
					{
						mainCharacter.inventory.GetItem_WithoutDeclaring(gear.GetRightHand().ID);
						gear.GetRightHand() = equipment;
					}
				}
			}
			if (choose == 0)
			{
				if (gear.GetLeftHand().title == "None")
				{
					gear.GetLeftHand() = equipment;
				}
				else
				{
					int choose;
					std::cout << "�� �������, ��� ������ �������� " << gear.GetLeftHand().title << " � ����� ���� �� " << equipment.title << '?' << std::endl;
					std::cout << "1 - ��, 2 - ���" << std::endl;
					std::cin >> choose;
					if (choose == 1)
					{
						mainCharacter.inventory.GetItem_WithoutDeclaring(gear.GetLeftHand().ID);
						gear.GetLeftHand() = equipment;
					}
				}
			}
		}
		system("cls");
	}

	void PutOn(Armor equipment, maincharacter& mainCharacter, Equipment& gear)
	{
		std::string title = equipment.title;

		if (equipment.additionalType == "Head")
		{
			if (gear.GetHead().title == "None")
			{
				gear.SetHead(equipment);
			}
			else
			{
				std::cout << "�� ������ �������� " << title << " �� " << equipment.title << '?' << std::endl;
				std::cout << "1 - ��, 0 - ���" << std::endl;
				int choose;
				std::cin >> choose;
				if (choose == 1) ResetArmor(equipment, &mainCharacter, &gear);//������� ��� ������ ������
			}
		}
		if (equipment.additionalType == "Shoulders")
		{
			if (gear.GetShoulders().title == "None")
			{
				gear.SetShoulders(equipment);
			}
			else
			{
				std::cout << "�� ������ �������� " << title << " �� " << equipment.title << '?' << std::endl;
				std::cout << "1 - ��, 0 - ���" << std::endl;
				int choose;
				std::cin >> choose;
				if (choose == 1) ResetArmor(equipment, &mainCharacter, &gear);//������� ��� ������ ������
			}
		}
		if (equipment.additionalType == "ShouldersCover")
		{
			if (gear.GetShouldersCover().title == "None")
			{
				gear.SetShouldersCover(equipment);
			}
			else
			{
				std::cout << "�� ������ �������� " << title << " �� " << equipment.title << '?' << std::endl;
				std::cout << "1 - ��, 0 - ���" << std::endl;
				int choose;
				std::cin >> choose;
				if (choose == 1) ResetArmor(equipment, &mainCharacter, &gear);//������� ��� ������ ������
			}
		}
		if (equipment.additionalType == "Torso")
		{
			if (gear.GetTorso().title == "None")
			{
				gear.SetTorso(equipment);
			}
			else
			{
				std::cout << "�� ������ �������� " << title << " �� " << equipment.title << '?' << std::endl;
				std::cout << "1 - ��, 0 - ���" << std::endl;
				int choose;
				std::cin >> choose;
				if (choose == 1) ResetArmor(equipment, &mainCharacter, &gear);//������� ��� ������ ������
			}
		}
		if (equipment.additionalType == "TorsoCover")
		{
			if (gear.GetTorsoCover().title == "None")
			{
				gear.SetTorsoCover(equipment);
			}
			else
			{
				std::cout << "�� ������ �������� " << title << " �� " << equipment.title << '?' << std::endl;
				std::cout << "1 - ��, 0 - ���" << std::endl;
				int choose;
				std::cin >> choose;
				if (choose == 1) ResetArmor(equipment, &mainCharacter, &gear);//������� ��� ������ ������
			}
		}
		if (equipment.additionalType == "Forearm")
		{
			if (gear.GetForearm().title == "None")
			{
				gear.SetForearm(equipment);
			}
			else
			{
				std::cout << "�� ������ �������� " << title << " �� " << equipment.title << '?' << std::endl;
				std::cout << "1 - ��, 0 - ���" << std::endl;
				int choose;
				std::cin >> choose;
				if (choose == 1) ResetArmor(equipment, &mainCharacter, &gear);//������� ��� ������ ������
			}
		}
		if (equipment.additionalType == "Wrist")
		{
			if (gear.GetWrist().title == "None")
			{
				gear.SetWrist(equipment);
			}
			else
			{
				std::cout << "�� ������ �������� " << title << " �� " << equipment.title << '?' << std::endl;
				std::cout << "1 - ��, 0 - ���" << std::endl;
				int choose;
				std::cin >> choose;
				if (choose == 1) ResetArmor(equipment, &mainCharacter, &gear);//������� ��� ������ ������
			}
		}
		if (equipment.additionalType == "Gaiters")
		{
			if (gear.GetGaiters().title == "None")
			{
				gear.SetGaiters(equipment);
			}
			else
			{
				std::cout << "�� ������ �������� " << title << " �� " << equipment.title << '?' << std::endl;
				std::cout << "1 - ��, 0 - ���" << std::endl;
				int choose;
				std::cin >> choose;
				if (choose == 1) ResetArmor(equipment, &mainCharacter, &gear);//������� ��� ������ ������
			}
		}
		if (equipment.additionalType == "Shin")
		{
			if (gear.GetShin().title == "None")
			{
				gear.SetShin(equipment);
			}
			else
			{
				std::cout << "�� ������ �������� " << title << " �� " << equipment.title << '?' << std::endl;
				std::cout << "1 - ��, 0 - ���" << std::endl;
				int choose;
				std::cin >> choose;
				if (choose == 1) ResetArmor(equipment, &mainCharacter, &gear);//������� ��� ������ ������
			}
		}
		if (equipment.additionalType == "Shoes")
		{
			if (gear.GetShoes().title == "None")
			{
				gear.SetShoes(equipment);
			}
			else
			{
				std::cout << "�� ������ �������� " << title << " �� " << equipment.title << '?' << std::endl;
				std::cout << "1 - ��, 0 - ���" << std::endl;
				int choose;
				std::cin >> choose;
				if (choose == 1) ResetArmor(equipment, &mainCharacter, &gear);//������� ��� ������ ������
			}
		}
	}

	void PutOff(Weapon equipment, maincharacter& mainCharacter, std::string arm, Equipment& gear)
	{
		if (equipment.additionalType == "Two-Handed")
		{
			mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
			Weapon weapon;
			gear.GetRightHand() = weapon;
			gear.GetLeftHand() = weapon;
		}
		if (equipment.additionalType == "One-Handed")
		{
			if (arm == "Right")
			{
				mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
				Weapon weapon;
				gear.GetRightHand() = weapon;
			}
			else
				if (arm == "Left")
				{
					mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
					Weapon weapon;
					gear.GetLeftHand() = weapon;
				}
		}
	}

	void PutOff(Armor equipment, maincharacter& mainCharacter, Equipment& gear)
	{
		if (equipment.additionalType == "Head")
		{
			mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
			Armor armor;
			gear.SetHead(armor);
		}
		if (equipment.additionalType == "Shoulders")
		{
			mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
			Armor armor;
			gear.SetShoulders(armor);
		}
		if (equipment.additionalType == "ShouldersCover")
		{
			mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
			Armor armor;
			gear.SetShouldersCover(armor);
		}
		if (equipment.additionalType == "Torso")
		{
			mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
			Armor armor;
			gear.SetTorso(armor);
		}
		if (equipment.additionalType == "TorsoCover")
		{
			mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
			Armor armor;
			gear.SetTorsoCover(armor);
		}
		if (equipment.additionalType == "Forearm")
		{
			mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
			Armor armor;
			gear.SetForearm(armor);
		}
		if (equipment.additionalType == "Wrist")
		{
			mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
			Armor armor;
			gear.SetWrist(armor);
		}
		if (equipment.additionalType == "Gaiters")
		{
			mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
			Armor armor;
			gear.SetGaiters(armor);
		}
		if (equipment.additionalType == "Shin")
		{
			mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
			Armor armor;
			gear.SetShin(armor);
		}
		if (equipment.additionalType == "Shoes")
		{
			mainCharacter.inventory.GetItem_WithoutDeclaring(equipment.ID);
			Armor armor;
			gear.SetShoes(armor);
		}
	}

	Weapon GetEquipment(Weapon equipment, maincharacter& mainCharacter)
	{
		system("cls");
		int j = 1;//�������������� �������� ��� ���������� ������������ �� ���� ���������
		std::vector<Weapon> tempVec;

		for (size_t i = 0; i < mainCharacter.inventory.GetWeaponInventory().size(); i++)
		{
			if (equipment.additionalType == mainCharacter.inventory.GetWeaponInventory()[i].additionalType)
			{
				std::cout << j << ") " << mainCharacter.inventory.GetWeaponInventory()[i].title << std::endl;
				j++;
				tempVec.push_back(mainCharacter.inventory.GetWeaponInventory()[i]);
			}
		}

		int choose;

		std::cout << std::endl << "����� ������ �������?" << std::endl;
		std::cin >> choose;
		choose--;

		bool isDeleted = false;
		for (size_t i = 0; i < mainCharacter.inventory.GetWeaponInventory().size(); i++) //����������� �������� � ���������
		{
			if (mainCharacter.inventory.GetWeaponInventory()[i].ID == tempVec[choose].ID && isDeleted == false)
			{
				mainCharacter.inventory.DeleteItem(i, "Weapon");
				isDeleted = true;
			}
		}

		return tempVec[choose];
	}

	Armor GetEquipment(Armor equipment, maincharacter& mainCharacter)
	{
		system("cls");
		int j = 1;//�������������� �������� ��� ���������� ������������ �� ���� ���������
		std::vector<Armor> tempVec;

		for (size_t i = 0; i < mainCharacter.inventory.GetArmorInventory().size(); i++)
		{
			if (equipment.additionalType == mainCharacter.inventory.GetArmorInventory()[i].additionalType)
			{
				std::cout << j << ") " << mainCharacter.inventory.GetArmorInventory()[i].title << std::endl;
				j++;
				tempVec.push_back(mainCharacter.inventory.GetArmorInventory()[i]);
			}
		}

		int choose;

		std::cout << std::endl << "����� ������� ����� �������?" << std::endl;
		std::cin >> choose;
		choose--;

		bool isDeleted = false;
		for (size_t i = 0; i < mainCharacter.inventory.GetArmorInventory().size(); i++) //����������� �������� � ���������
		{
			if (mainCharacter.inventory.GetArmorInventory()[i].ID == tempVec[choose].ID && isDeleted == false)
			{
				mainCharacter.inventory.DeleteItem(i, "Armor");
				isDeleted = true;
			}
		}

		return tempVec[choose];
	}

	void Equip_ASSIST(Weapon equipment, maincharacter& mainCharacter, std::string arm)
	{
		system("cls");
		int choose;

		if (equipment.title != "None")
		{
			std::cout << "��� ���-�� ����� ������ " << equipment.title << " ��� ������ ������ ���?" << std::endl;
			std::cout << "1 - ��������, 2 - �����" << std::endl;
			std::cin >> choose;
		}
		else choose = 1;

		if (choose == 1)
		{
			PutOn(GetEquipment(equipment, mainCharacter), mainCharacter, mainCharacter.equipment);
		}
		if (choose == 2) PutOff(equipment, mainCharacter, arm, mainCharacter.equipment);
	}

	void Equip_ASSIST(Armor equipment, maincharacter& mainCharacter)
	{
		system("cls");
		int choose;

		if (equipment.title != "None")
		{
			std::cout << "��� ���-�� ������ ������ " << equipment.title << " ��� ������ ����� � ���� ���?" << std::endl;
			std::cout << "1 - ��������, 2 - �����" << std::endl;
			std::cin >> choose;
		}
		else choose = 1;

		if (choose == 1)
		{
			PutOn(GetEquipment(equipment, mainCharacter), mainCharacter, mainCharacter.equipment);
		}
		if (choose == 2) PutOff(equipment, mainCharacter, mainCharacter.equipment);
	}

	void ChangeClothes(maincharacter& mainCharacter, Equipment& gear)
	{
		std::cout << "      " << "��������" << std::endl;
		std::cout << "1) ������: " << gear.GetHead().title << std::endl;
		std::cout << "2) �����: " << gear.GetShoulders().title << std::endl;
		std::cout << "3) ������ ������: " << gear.GetShouldersCover().title << std::endl;
		std::cout << "4) ����: " << gear.GetTorso().title << std::endl;
		std::cout << "5) ������ �����: " << gear.GetTorsoCover().title << std::endl;
		std::cout << "6) ����������: " << gear.GetForearm().title << std::endl;
		std::cout << "7) �����: " << gear.GetWrist().title << std::endl;
		std::cout << "8) ������������: " << gear.GetGaiters().title << std::endl;
		std::cout << "9) ������: " << gear.GetShin().title << std::endl;
		std::cout << "10) ������: " << gear.GetShoes().title << std::endl;

		if (gear.GetRightHand().additionalType != "Two-Handed")
		{
			std::cout << "11) ������ ����: " << gear.GetRightHand().title << std::endl;
			std::cout << "12) ����� ����: " << gear.GetLeftHand().title << std::endl;
		}
		else
		{
			std::cout << "11) ����: " << gear.GetRightHand().title << std::endl;
		}

		int choose;
		std::cout << "����� ������� ���������� ��� ������� ������������?" << std::endl;
		std::cin >> choose;

		switch (choose)
		{
		case 1:
		{
			Equip_ASSIST(gear.GetHead(), mainCharacter);
			break;
		}
		case 2:
		{
			Equip_ASSIST(gear.GetShoulders(), mainCharacter);
			break;
		}
		case 3:
		{
			Equip_ASSIST(gear.GetShouldersCover(), mainCharacter);
			break;
		}
		case 4:
		{
			Equip_ASSIST(gear.GetTorso(), mainCharacter);
			break;
		}
		case 5:
		{
			Equip_ASSIST(gear.GetTorsoCover(), mainCharacter);
			break;
		}
		case 6:
		{
			Equip_ASSIST(gear.GetForearm(), mainCharacter);
			break;
		}
		case 7:
		{
			Equip_ASSIST(gear.GetWrist(), mainCharacter);
			break;
		}
		case 8:
		{
			Equip_ASSIST(gear.GetGaiters(), mainCharacter);
			break;
		}
		case 9:
		{
			Equip_ASSIST(gear.GetShin(), mainCharacter);
			break;
		}
		case 10:
		{
			Equip_ASSIST(gear.GetShoes(), mainCharacter);
			break;
		}
		case 11:
		{
			Equip_ASSIST(gear.GetRightHand(), mainCharacter, "Right");////
			break;
		}
		case 12:
		{
			Equip_ASSIST(gear.GetRightHand(), mainCharacter, "Left");////
			break;
		}
		default:
			break;
		}
	}

	void ShowClothes(maincharacter& mainCharacter, Equipment& gear)
	{
		std::cout << "      " << "��������" << std::endl;
		std::cout << "������: " << gear.GetHead().title << std::endl;
		std::cout << "�����: " << gear.GetShoulders().title << std::endl;
		std::cout << "������ ������: " << gear.GetShouldersCover().title << std::endl;
		std::cout << "����: " << gear.GetTorso().title << std::endl;
		std::cout << "������ �����: " << gear.GetTorsoCover().title << std::endl;
		std::cout << "����������: " << gear.GetForearm().title << std::endl;
		std::cout << "�����: " << gear.GetWrist().title << std::endl;
		std::cout << "������������: " << gear.GetGaiters().title << std::endl;
		std::cout << "������: " << gear.GetShin().title << std::endl;
		std::cout << "������: " << gear.GetShoes().title << std::endl;

		if (gear.GetRightHand().additionalType != "Two-Handed")
		{
			std::cout << "������ ����: " << gear.GetRightHand().title << std::endl;
			std::cout << "����� ����: " << gear.GetLeftHand().title << std::endl;
		}
		else
		{
			std::cout << "����: " << gear.GetRightHand().title << std::endl;
		}

		int choose;
		std::cout << "��� ������� ������� ����������?" << std::endl;
		std::cout << "1 - ��, 2 - ���" << std::endl;
		std::cin >> choose;
		if (choose == 1)
		{
			system("cls");
			ChangeClothes(mainCharacter, gear);
		}
	}

	void Clothes(maincharacter& mainCharacter)
	{
		system("cls");
		ShowClothes(mainCharacter, mainCharacter.equipment);
	}
}