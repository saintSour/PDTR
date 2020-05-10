#pragma once

void BattleAwake(maincharacter& mainCharacter); //механика боя

void BattleAwake(maincharacter& mainCharacter, std::string EnemyType);

void BattleAwakeCon(maincharacter& mainCharacter, std::string EnemyDelegate, int enemiesCount);

void EnemyDeath(maincharacter& mainCharacter, std::vector<Enemy>& enemies);