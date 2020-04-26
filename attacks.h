#ifndef ATTACKS
#include "entities.h"
#define ATTACKS
class base_atk{
public:

    /*This calculates the damage done. If
    missAttack() comes true, it'll do 0 damage,
    if not it'll get the damage within the range
    and increase it by 10% per level of the entity
    using it, truncated to the nearest integer*/
    int calculateDmg(entity target, entity opponent){
        if(missAttack(opponent)) return 0;
        float multiplier = 1 + (0.1 * target.getLvl());
        return getDmg() * multiplier;
    }
protected:
    int minDmg;
    int maxDmg;
    int missChance;

    //This just tests if the attack has missed
    bool missAttack(entity opponent){
        int random = (std::rand() % 100);
        if (random > missChance + opponent.getEvasiveness()) return 0;
        return 1;
    }

    //This gets the damage done within the specified range
    int getDmg(){
        int range = maxDmg - minDmg;
        return minDmg + (std::rand() % range);
    }
};

class basic_atk : public base_atk{
public:
    //Constructor just sets the values for this specific attack
    basic_atk() {
        this -> minDmg = 5;
        this -> maxDmg = 10;
        this -> missChance = 20;
    }
private:

};
#endif //ATTACKS
