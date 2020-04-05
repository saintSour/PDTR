#pragma once

#include "Roles.h"
#include "World.h"

void Game();
void Settings();
void ExitGame();

void GetRole(maincharacter& mainCharacter, std::string roleType);

void EnterTheWorld(maincharacter& mainCharacter, World& world);