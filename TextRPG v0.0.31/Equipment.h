#pragma once

#include "Roles.h"
//#include "Items.h"
class maincharacter;
class Equipment
{
public:

	Equipment()
	{
		this->LeftHand = Weapon();
		this->LeftHand = Weapon();

		this->Head = Armor();				   	 this->Head.additionalType = "Head";
		this->Shoulders = Armor();				 this->Shoulders.additionalType = "Shoulders";
		this->ShouldersCover = Armor();			 this->ShouldersCover.additionalType = "ShouldersCover";
		this->Torso = Armor();					 this->Torso.additionalType = "Torso";
		this->TorsoCover = Armor();				 this->TorsoCover.additionalType = "TorsoCover";
		this->Forearm = Armor();				 this->Forearm.additionalType = "Forearm";
		this->Wrist = Armor();					 this->Wrist.additionalType = "Wrist";
		this->Gaiters = Armor();				 this->Gaiters.additionalType = "Gaiters";
		this->Shin = Armor();					 this->Shin.additionalType = "Shin";
		this->Shoes = Armor();					 this->Shoes.additionalType = "Shoes";
	}

private:

	Weapon LeftHand;
	Weapon RightHand;

	Armor Head; //голова
	Armor Shoulders; //плечи
	Armor ShouldersCover; // защита плечей
	Armor Torso; // торс
	Armor TorsoCover; // защита торса 
	Armor Forearm; //предплечья
	Armor Wrist; //кисти
	Armor Gaiters; //набедренники
	Armor Shin; //голени
	Armor Shoes; //ступни

public:

	Weapon GetLeftHand()
	{
		return this->LeftHand;
	}
	Weapon GetRightHand()
	{
		return this->RightHand;
	}

	Armor GetHead()
	{
		return this->Head;
	}
	Armor GetShoulders()
	{
		return this->Shoulders;
	}
	Armor GetShouldersCover()
	{
		return this->ShouldersCover;
	}
	Armor GetTorso()
	{
		return this->Torso;
	}
	Armor GetTorsoCover()
	{
		return this->TorsoCover;
	}
	Armor GetForearm()
	{
		return this->Forearm;
	}
	Armor GetWrist()
	{
		return this->Wrist;
	}
	Armor GetGaiters()
	{
		return this->Gaiters;
	}
	Armor GetShin()
	{
		return this->Shin;
	}
	Armor GetShoes()
	{
		return this->Shoes;
	}

	void SetLeftHand(Weapon weapon)
	{
		this->LeftHand = weapon;
	}
	void SetRightHand(Weapon weapon)
	{
		this->RightHand = weapon;
	}

	void SetHead(Armor armor)
	{
		this->Head = armor;
	}
	void SetShoulders(Armor armor)
	{
		this->Shoulders = armor;
	}
	void SetShouldersCover(Armor armor)
	{
		this->ShouldersCover = armor;
	}
	void SetTorso(Armor armor)
	{
		this->Torso = armor;
	}
	void SetTorsoCover(Armor armor)
	{
		this->TorsoCover = armor;
	}
	void SetForearm(Armor armor)
	{
		this->Forearm = armor;
	}
	void SetWrist(Armor armor)
	{
		this->Wrist = armor;
	}
	void SetGaiters(Armor armor)
	{
		this->Gaiters = armor;
	}
	void SetShin(Armor armor)
	{
		this->Shin = armor;
	}
	void SetShoes(Armor armor)
	{
		this->Shoes = armor;
	}
};