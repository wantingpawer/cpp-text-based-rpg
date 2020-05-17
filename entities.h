#ifndef ENTITY
#define ENTITY
#include "attacks.h"

//Simple getters for classes that inherit from entity
entity::takeDmg(int dmg){
    #ifdef DEBUG
    std::clog << "[DEBUG] ENTITY TAKEN " << dmg << " DAMAGE" << std::endl;
    pause(false);
    #endif // DEBUG
    return hp -= dmg;
}
entity::getHp(){ return hp; }
entity::getMaxHp() { return maxhp; }
entity::getLvl() { return lvl; }
entity::getEvasiveness() { return evasiveness; }

std::string playableCharacter::getAttack() { return attack; }
void playableCharacter::setName(std::string name){
    this -> name = name;
}
std::string playableCharacter::getName() {
    return name;
}

bool playableCharacter::tryToEscape() {
    //random value up to 100
    int random = (std::rand() % 100);
    //if that value is higher than the evasiveness, then you didn't escape
    if(random > evasiveness) return false;
    return true;
}
/*The playable character constructor
sets all of the values required by the
entity class, which can be found above.*/
playableCharacter::playableCharacter(int hp, int evasiveness, std::string attack){
    #ifdef DEBUG
    std::clog << "[DEBUG] ENTITY CREATED" << std::endl;
    pause(false);
    #endif // DEBUG
    this -> exp = 0;
    this -> evasiveness = evasiveness;
    this -> maxhp = hp;
    this -> hp = hp;
    this -> lvl = 1;
    this -> attack = attack;
    this -> lives = 2;
    createAttack();
}

int playableCharacter::getLives() {return this -> lives;}

void playableCharacter::setLives(int lives) {
    #ifdef DEBUG
    std::clog << "[DEBUG] ENTITY LIVES SET TO " << lives << std::endl;
    pause(false);
    #endif // DEBUG
    this -> lives = lives;
}
void playableCharacter::setHp(int hp) {
    #ifdef DEBUG
    std::clog << "[DEBUG] ENTITY HP SET TO " << hp << std::endl;
    pause(false);
    #endif // DEBUG
    this -> hp = hp;
}

void playableCharacter::createAttack(){
    if(attack == "Fireball"){
        fight.setParams(10, 25, 20);
    }else if(attack == "Crushing_strike"){
        fight.setParams(10, 40, 40);
    }else if(attack == "Crossbow"){
        fight.setParams(5, 10, 2);
    }
}

/*The enemy constructor sets all of the values required
by the entity class, which can be found above. It can also
use the appearance message*/
enemy::enemy(std::string type, int hp, int lvl, int evasiveness, bool doAppearance){
    #ifdef DEBUG
    std::clog << "[DEBUG] ENTITY CREATED" << std::endl;
    pause(false);
    #endif // DEBUG
    this -> type = type;
    this -> maxhp = hp;
    this -> hp = hp;
    this -> lvl = lvl;
    this -> evasiveness = evasiveness;
    if(doAppearance) appearanceMessage();
}

//Same thing as above but without doAppearance
enemy::enemy(std::string type, int hp, int lvl, int evasiveness){
    #ifdef DEBUG
    std::clog << "[DEBUG] ENTITY CREATED" << std::endl;
    pause(false);
    #endif // DEBUG
    this -> type = type;
    this -> maxhp = hp;
    this -> hp = hp;
    this -> lvl = lvl;
    this -> evasiveness = evasiveness;
}
enemy::enemy(){
    #ifdef DEBUG
    std::clog << "[DEBUG] ENTITY CREATED" << std::endl;
    pause(false);
    #endif // DEBUG
    this -> type = "ERROR";
    this -> maxhp = 1000000;
    this -> hp = 1000000;
    this -> lvl = 1000000;
    this -> evasiveness = 100000;
}

void enemy::setAttributes(std::string type, int hp, int lvl, int evasiveness){
    this -> type = type;
    this -> maxhp = hp;
    this -> hp = hp;
    this -> lvl = lvl;
    this -> evasiveness = evasiveness;
}

std::string enemy::getType(){
    return type;
}


void enemy::appearanceMessage(){
    std::cout << "A wild level " << lvl  << " " << type << " has appeared!" << std::endl;
}
#endif //ENTITIES
