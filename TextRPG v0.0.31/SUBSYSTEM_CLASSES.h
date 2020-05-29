#pragma once
/*#include <string>
#include <vector>

//class Items;
//class Inventory;
//class Skill;
//class FTSkill;
//class STSkill;
//class SkillStock;
//class Actors;
//class maincharacter;
//class Enemy;
//class World;
//class WorldInventory;
//class Time;

class Items
{
public:
	Items();

	Items(int ID, int cost, int count, bool isStackable, int durability, std::string title);

	int ID;
	int count;
	bool isStackable;
	int cost;
	int durability;
	std::string title;
};

class Inventory //реализация инвентаря
{
public:
	Inventory();

private:

	std::vector<Items> inventory;

private:

	void InventoryRestack(std::vector<Items>& inventory);

	void InventoryResize(std::vector<Items>& inventory);

public:

	void GetItem(int ItemID);

	void DropItem(maincharacter& mainCharacter, World& world);

	void InventoryShow();
};

class Skill
{
private:
	std::string name;
	std::string description;
	int requiredMana;
	int requiredAP;
public:
	std::string GetName();

	void SetName(std::string name);

	std::string GetDescription();

	void SetDescription(std::string description);

	void SetRequiredMana(int mana);

	int GetRequiredMana();

	void SetRequiredAP(int AP);

	int GetRequiredAP();

};

class FTSkill : public Skill
{
public:
	void (*UseSkill)(maincharacter&, int, int, std::vector<Enemy>&);
};

class STSkill : public Skill
{
public:
	void (*UseSkill)(maincharacter&, int, int);
};

class SkillStock
{
public: 
	SkillStock();

private:
	std::vector<FTSkill> firstTypeSkills;
	std::vector<STSkill> secondTypeSkills;

public:
	void GetSkill(std::string skillTitle);

	void maincharacterSkillsUse(maincharacter& mainCharacter, std::vector<Enemy>& enemies);

	void UseSkill_World(maincharacter& mainCharacter);

	void UseSkill(maincharacter& mainCharacter);

	void UseSkill(maincharacter& mainCharacter, std::vector<Enemy>& enemies);

};

class Actors
{
public:
	Actors()
	{
		this->initiative = 0;
	}
	int initiative;
};

class maincharacter : public Actors
{
public:
	maincharacter();

	std::string roleType;
	std::string location;
	int characterLevel;

	int maxHitPoints;
	int maxManaPoints;
	int hitPoints;
	int manaPoints;

	int hpMultiplier;
	int mpMultiplier;
	int addHpMultiplier;
	int addMpMultiplier;

	int physicalDamage;
	int magicalDamage;
	int blockCount;
	double criticalChance;
	double criticalRate;

	double blockChance;
	double dodgeChance;
	double accuracy;

	int actionPoints;
	int maxActionPoints;
	int roleActionPoints;
	int maxRoleActionPoints;

	int physicalStability;
	int magicalStability;

	int physicalStrength;
	int magicalStrength;

	int agility;
	int rhetoric;
	int luck;
	int spirit;
	int endurance;
	int visibility;

	double maxWeight;
	double dropChance;

private:
	int countOfExperience;
	double levelsOfExperience[100]{};
	void setLevelsOfExperience(double levelsOfExperience[]);

	void setLevelOfCharacter();

	int initialHitPoints;
	int initialManaPoints;
	int initialPhysDamage;
	int initialMagDamage;
	int initialActionPoints;

public:

	void setCountOfExperience(int incCountOfExperience);

	int GetCountOfExperience();

	void ShowCountOfExperience();

	void characterUpdate(maincharacter& mainCharacter);

	int GetInitialHitPoints();

	int GetInitialManaPoints();

	int GetInitialPhysDamage();

	void SetInitialPhysDamage(int initialPhysDamage);

	int GetInitialMagDamage();

	void SetInitialMagDamage(int initialMagDamage);

	void SetInitialActionPoints(int initialActionPoints);

public:
	Inventory inventory; //инвентарь персонажа
	SkillStock skills; //способности персонажа
private:

	void StandartAttack(maincharacter& mainCharacter, std::vector<Enemy>& enemies);

	void EnemyInfo(std::vector<Enemy>& enemies);

public:

	void MaincharacterInfo(maincharacter& mainCharacter);
	
	void APRegen();

	void MaincharacterTurn(maincharacter& mainCharacter, std::vector<Enemy>& enemies);
	
};

class Enemy : public Actors
{
public:
	std::string enemyType;

	Enemy();

	int level;
	int experience;

	int maxHitPoints;
	int hitPoints = maxHitPoints;
	int maxManaPoints;
	int manaPoints = maxManaPoints;
	int maxActionPoints;

	int physicalDamage;
	int magicalDamage;
	int blockCount;

	int physicalStability;
	int magicalStability;

	int physicalStrength;
	int magicalStrength;

	int agility;
	int rhetoric;
	int luck;
	int spirit;
	int endurance;
	int visibility;

	double blockChance;
	double dodgeChance;
	double accuracy;

	double criticalChance;
	double criticalChanceRate;

	int initiative;
	std::string enteringPhrase;

	std::vector<void (*)(Enemy&, maincharacter&)> skillStock;

	void standartPhysAttack(Enemy& attacker, maincharacter& defender);
};*/

/*
class World
{
public:
	World();

	WorldInventory WorldInventory;
	Time WorldTime;
};

class WorldInventory
{
public:

private:
	std::vector<Items> HouseNearTheHills_Inventory;

	std::vector<Items> CastleGates_Inventory;

	std::vector<Items> GreenForest_Inventory;

	std::vector<Items> DeepForest_Inventory;

	std::vector<Items> GladeNearTheCity_Inventory;

	std::vector<Items> MagesTower_Inventory;

	std::vector<Items> CastleCenter_Inventory;

	std::vector<Items> GuildDistrict_Inventory;

	std::vector<Items> Marketplace_Inventory;

	std::vector<Items> Church_Inventory;

	std::vector<Items> BlackSmith_Inventory;

	std::vector<Items> CastleNook_Inventory;

	std::vector<Items> AdventurersGuild_Inventory;

	std::vector<Items> ArchersGuild_Inventory;

	std::vector<Items> RoguesGuild_Inventory;

	std::vector<Items> WarriorsGuild_Inventory;

	std::vector<Items>& FindLocation(maincharacter mainCharacter);

	void InventoryResize(std::vector<Items>& inventory);

	void InventoryRestack(std::vector<Items>& inventory);

public:

	void GetItem_location(maincharacter& mainCharacter, Items& item);

	void TakeItem_location(maincharacter& mainCharacter, Items item);
};

class Time
{
private:

	int years;
	int days;
	int hours;
	int minutes;
public:
	Time();

protected:

	void AddTimeYears(int years);

	void AddTimeDays(int days);

	void AddTimeHours(int hours);

	void AddTimeMinutes(int minutes);

	void TimeSort();

public:
	void TimeShow();
};*/