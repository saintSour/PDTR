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
		std::cout << "Персонаж" << std::endl;
		std::cout << "1-Сумка\n2-Характеристики\n3-Мирные способности\n4-Закрыть окно персонажа " << std::endl;
		int* chooseH = new int;
		std::cin >> *chooseH;
		switch (*chooseH)
		{
		case 1:
		{
			system("cls");
			delete chooseH;
			mainCharacter.inventory.InventoryShow(); //интерактивный инвентарь
			break;
		}
		case 2:
		{
			system("cls");
			delete chooseH;
			CQACount(mainCharacter);
			std::cout << mainCharacter.roleType << std::endl;
			std::cout << "Уровень = " << mainCharacter.characterLevel << std::endl;
			std::cout << "Очки здоровья = " << mainCharacter.hitPoints << '/' << mainCharacter.maxHitPoints << std::endl;
			std::cout << "Очки маны = " << mainCharacter.manaPoints << '/' << mainCharacter.maxManaPoints << std::endl;
			std::cout << "Физический урон = " << mainCharacter.physicalDamage << std::endl;
			std::cout << "Магический урон = " << mainCharacter.magicalDamage << std::endl;
			std::cout << "Шанс критического урона = " << mainCharacter.criticalChance << " %" << std::endl;
			std::cout << "Рейтинг критического урона = " << mainCharacter.criticalRate << std::endl;
			std::cout << "Шанс блокирования = " << mainCharacter.blockChance << " %" << std::endl;
			std::cout << "Шанс уклонения = " << mainCharacter.dodgeChance << " %" << std::endl;
			std::cout << "Меткость = " << mainCharacter.accuracy << std::endl;
			std::cout << "Количество очков действий = " << mainCharacter.maxActionPoints << std::endl;
			std::cout << "Количество классовых очков действий = " << mainCharacter.maxRoleActionPoints << std::endl;
			std::cout << "Физическая стойкость = " << mainCharacter.physicalStability << std::endl;
			std::cout << "Магическая стойкость = " << mainCharacter.magicalStability << std::endl;
			std::cout << "Физическая сила = " << mainCharacter.physicalStrength << std::endl;
			std::cout << "Магическая сила = " << mainCharacter.magicalStrength << std::endl;
			std::cout << "Ловкость = " << mainCharacter.agility << std::endl;
			std::cout << "Красноречие = " << mainCharacter.rhetoric << std::endl;
			std::cout << "Удача = " << mainCharacter.luck << std::endl;
			std::cout << "Дух = " << mainCharacter.spirit << std::endl;
			std::cout << "Выносливость = " << mainCharacter.endurance << std::endl;
			std::cout << "Инициатива = " << mainCharacter.initiative << std::endl;
			std::cout << "Заметность = " << mainCharacter.visibility << std::endl;
			std::cout << "Максимальный вес = " << mainCharacter.maxWeight << std::endl;
			std::cout << "Шанс выпадения лута = " << mainCharacter.dropChance << " %" << std::endl;
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
			std::cout << "Не понимаю... " << std::endl;
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
		std::cout << "Дом Возле Полей " << std::endl;

		std::cout << "Выберите, куда пойти: \n1-Ворота Города\n2-Зелёный Лес\n8-Персонаж\n9-Настройки\n0-Выйти из игры" << std::endl;
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
			std::cout << "Пора вздремнуть... "; Sleep(1000); std::cout << "Завтра будет тяжёлый день. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "Я не знаю такого места..." << std::endl;
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
		std::cout << "Ворота Города " << std::endl;
		std::cout << "Выберите, куда пойти: \n1-Городской Центр\n2-Поляна За городом\n3-Зелёный Лес\n8-Персонаж\n9-Настройки\n0-Выйти из игры" << std::endl;
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
			std::cout << "Пора вздремнуть... "; Sleep(1000); std::cout << "Завтра будет тяжёлый день. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "Я не знаю такого места..." << std::endl;
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
		std::cout << "Зелёный Лес " << std::endl;
		std::cout << "Выберите, куда пойти: \n1-Ворота Города\n2-Густой Лес\n8-Персонаж\n9-Настройки\n0-Выйти из игры" << std::endl;
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
			std::cout << "Пора вздремнуть... "; Sleep(1000); std::cout << "Завтра будет тяжёлый день. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "Я не знаю такого места..." << std::endl;
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
		std::cout << "Густой Лес " << std::endl;
		std::cout << "Выберите, куда пойти: \n1-Поляна За Городом\n2-Зелёный Лес\n8-Персонаж\n9-Настройки\n0-Выйти из игры" << std::endl;
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
			std::cout << "Пора вздремнуть... "; Sleep(1000); std::cout << "Завтра будет тяжёлый день. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "Я не знаю такого места..." << std::endl;
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
		std::cout << "Поляна За Городом " << std::endl;
		std::cout << "Выберите, куда пойти: \n1-Ворота Города\n2-Башня Магов\n3-Густой Лес\n8-Персонаж\n9-Настройки\n0-Выйти из игры" << std::endl;
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
			std::cout << "Пора вздремнуть... "; Sleep(1000); std::cout << "Завтра будет тяжёлый день. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "Я не знаю такого места..." << std::endl;
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
		std::cout << "Башня Магов " << std::endl;
		std::cout << "Выберите, куда пойти: \n1-Поляна За городом\n8-Персонаж\n9-Настройки\n0-Выйти из игры" << std::endl;
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
			std::cout << "Пора вздремнуть... "; Sleep(1000); std::cout << "Завтра будет тяжёлый день. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "Я не знаю такого места..." << std::endl;
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
		std::cout << "Центр Города " << std::endl;
		std::cout << "Выберите, куда пойти: \n1-Район Гильдий\n2-Рынок\n3-Церковь\n4-Кузнец\n5-Закоулок(в разработке)\n6-Ворота Города\n8-Персонаж\n9-Настройки\n0-Выйти из игры" << std::endl;
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
			std::cout << "Пора вздремнуть... "; Sleep(1000); std::cout << "Завтра будет тяжёлый день. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "Я не знаю такого места..." << std::endl;
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
		std::cout << "Район Гильдий " << std::endl;
		std::cout << "Выберите, куда пойти: \n1-Гильдия Авантюристов\n2-Гильдия Лучников\n3-Гильдия Плутов\n4-Гильдия Войнов\n5-Центр Города\n8-Персонаж\n9-Настройки\n0-Выйти из игры" << std::endl;
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
			std::cout << "Пора вздремнуть... "; Sleep(1000); std::cout << "Завтра будет тяжёлый день. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "Я не знаю такого места..." << std::endl;
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
		std::cout << "Рынок " << std::endl;
		std::cout << "Выберите, куда пойти: \n1-Городской Центр\n2-Торговля\n8-Персонаж\n9-Настройки\n0-Выйти из игры" << std::endl;
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
			std::cout << "Здесь будет реализована торговля" << std::endl;
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
			std::cout << "Пора вздремнуть... "; Sleep(1000); std::cout << "Завтра будет тяжёлый день. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "Я не знаю такого места..." << std::endl;
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
		std::cout << "Церковь " << std::endl;
		std::cout << "Выберите, куда пойти: \n1-Городской Центр\n2-Помолиться\n8-Персонаж\n9-Настройки\n0-Выйти из игры" << std::endl;
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
			std::cout << "Здесь будет реализована церковь" << std::endl;
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
			std::cout << "Пора вздремнуть... "; Sleep(1000); std::cout << "Завтра будет тяжёлый день. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "Я не знаю такого места..." << std::endl;
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
		std::cout << "Кузнец " << std::endl;
		std::cout << "Выберите, куда пойти: \n1-Городской Центр\n2-Кузнец\n8-Персонаж\n9-Настройки\n0-Выйти из игры" << std::endl;
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
			std::cout << "Здесь будет реализовано улучшение экипировки" << std::endl;
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
			std::cout << "Пора вздремнуть... "; Sleep(1000); std::cout << "Завтра будет тяжёлый день. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "Я не знаю такого места..." << std::endl;
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
		std::cout << "Закоулок " << std::endl;
		std::cout << "Выберите, куда пойти: \n1-Городской Центр\n8-Персонаж\n9-Настройки\n0-Выйти из игры" << std::endl;
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
			std::cout << "Пора вздремнуть... "; Sleep(1000); std::cout << "Завтра будет тяжёлый день. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "Я не знаю такого места..." << std::endl;
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
		std::cout << "Гильдия Авантюристов " << std::endl;
		std::cout << "Выберите, куда пойти: \n1-Район Гильдий\n2-Доска заданий\n3-Квестерша\n8-Персонаж\n9-Настройки\n0-Выйти из игры" << std::endl;
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
			std::cout << "Здесь будет реализована Доска Заданий" << std::endl;
			break;
		}
		case 3:
		{
			system("cls");
			delete choose;
			std::cout << "Здесь будет реализована Квестерша" << std::endl;
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
			std::cout << "Пора вздремнуть... "; Sleep(1000); std::cout << "Завтра будет тяжёлый день. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "Я не знаю такого места..." << std::endl;
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
		std::cout << "Гильдия Лучников " << std::endl;
		std::cout << "Выберите, куда пойти: \n1-Район Гильдий\n2-Наставник Лучников\n8-Персонаж\n9-Настройки\n0-Выйти из игры" << std::endl;
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
			std::cout << "Здесь будет реализован наставник лучников" << std::endl;
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
			std::cout << "Пора вздремнуть... "; Sleep(1000); std::cout << "Завтра будет тяжёлый день. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "Я не знаю такого места..." << std::endl;
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
		std::cout << "Гильдия Плутов" << std::endl;
		std::cout << "Выберите, куда пойти: \n1-Район Гильдий\n2-Наставник Плутов\n8-Персонаж\n9-Настройки\n0-Выйти из игры" << std::endl;
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
			std::cout << "Здесь будет реализован наставник плутов" << std::endl;
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
			std::cout << "Пора вздремнуть... "; Sleep(1000); std::cout << "Завтра будет тяжёлый день. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "Я не знаю такого места..." << std::endl;
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
		std::cout << "Гильдия Мечников " << std::endl;
		std::cout << "Выберите, куда пойти: \n1-Район Гильдий\n2-Наставник Мечников\n8-Персонаж\n9-Настройки\n0-Выйти из игры" << std::endl;
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
			std::cout << "Здесь будет реализован наставник мечников" << std::endl;
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
			std::cout << "Пора вздремнуть... "; Sleep(1000); std::cout << "Завтра будет тяжёлый день. "; Sleep(1000);
			exit(0);
		}
		default:
		{
			std::cout << "Я не знаю такого места..." << std::endl;
			system("pause");
			system("cls");
			delete choose;
		}
		}
	}
}