#include "attacks.h"
#include "entities.h"
/*This calculates the damage done. If
missAttack() comes true, it'll do 0 damage,
if not it'll get the damage within the range
and increase it by 10% per level of the entity
using it, truncated to the nearest integer*/
int base_atk::calculateDmg(entity *target, entity *opponent){
    if(missAttack(opponent)) return 0;
    float multiplier = 1 + (0.1 * target -> getLvl());
    return getDmg() * multiplier;
}
//This just tests if the attack has missed
bool base_atk::missAttack(entity *opponent){
    int random = (std::rand() % 100);
    if (random > missChance + opponent -> getEvasiveness()) return false;
    return true;
}

//This gets the damage done within the specified range
base_atk::getDmg(){
    int range = maxDmg - minDmg;
    return minDmg + (std::rand() % range);
}

void basic_atk::setParams(int minDmg, int maxDmg, int missChance){
    this -> minDmg = minDmg;
    this -> maxDmg = maxDmg;
    this -> missChance = missChance;
}

void basic_atk::setParams(int minDmg, int maxDmg){
    this -> minDmg = minDmg;
    this -> maxDmg = maxDmg;
}

//Constructor just sets the values for this specific attack
basic_atk::basic_atk() {
    this -> minDmg = 10;
    this -> maxDmg = 15;
    this -> missChance = 20;
}
