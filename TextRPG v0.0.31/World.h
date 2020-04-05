#pragma once

class World
{
private:
	int years;
	int days;
	int hours;
	int minutes;
public:
	World()
	{
		this->years = 0;
		this->days = 0;
		this->hours = 0;
		this->minutes = 0;
	}
	void AddTimeYears(int years)
	{
		this->years += years;
		TimeSort();
	}
	void AddTimeDays(int days)
	{
		this->days += days;
		TimeSort();
	}
	void AddTimeHours(int hours)
	{
		this->hours += hours;
		TimeSort();
	}
	void AddTimeMinutes(int minutes)
	{
		this->minutes += minutes;
		TimeSort();
	}
	void TimeSort()
	{
		if (this->minutes >= 60)
		{
			this->minutes -= 60;
			this->hours += 1;
		}
		if (this->hours >= 24)
		{
			this->hours -= 24;
			this->days += 1;
		}
		if (this->days >= 365)
		{
			this->days -= 365;
			this->years += 1;
		}
	}
	void TimeShow()
	{
		TimeSort();
		std::cout << this->years << "год   " << "ƒень " << this->days  << "  "<< this->hours<< ":" << this->minutes << std::endl;
	}
};

void HouseNearTheHills(maincharacter& mainCharacter, World& world);

void CastleGates(maincharacter& mainCharacter, World& world);

void GreenForest(maincharacter& mainCharacter, World& world);

void DeepForest(maincharacter& mainCharacter, World& world);

void GladeNearTheCity(maincharacter& mainCharacter, World& world);

void MagesTower(maincharacter& mainCharacter, World& world);

void CastleCenter(maincharacter& mainCharacter, World& world);

void GuildDistrict(maincharacter& mainCharacter, World& world);

void Marketplace(maincharacter& mainCharacter, World& world);

void Church(maincharacter& mainCharacter, World& world);

void BlackSmith(maincharacter& mainCharacter, World& world);

void CastleNook(maincharacter& mainCharacter, World& world);

void AdventurersGuild(maincharacter& mainCharacter, World& world);

void ArchersGuild(maincharacter& mainCharacter, World& world);

void RoguesGuild(maincharacter& mainCharacter, World& world);

void WarriorsGuild(maincharacter& mainCharacter, World& world);