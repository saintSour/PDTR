#pragma once
class maincharacter;
class Enemy;


//########################
//   FIRST_TYPE_SKILLS
//########################
void DoubleStrike(maincharacter& mainCharacter, int requiredMana, int requiredAP, std::vector<Enemy>& enemies);
//

//########################
//   SECOND_TYPE_SKILLS
//########################
void BandageWounds(maincharacter& mainCharacter, int requiredMana, int requiredAP);
//