#include "entities.h"
#include "OSdependent.h"

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
playableCharacter::playableCharacter(int hp, int evasiveness, std::string attack, std::string initialClass){
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
    this -> nextLvl = 100;
    this -> playerClass = initialClass;
    createAttack();
}

int playableCharacter::getLives() {return this -> lives;}

void playableCharacter::setClass(std::string newClass){
    this -> playerClass = newClass;
}

std::string playableCharacter::getClass() { return this -> playerClass; }

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
        fight.setParams(15, 20, 2);
    }
}

inline int playableCharacter::getExp(){ return exp; }
inline int playableCharacter::getNextLvl(){ return nextLvl; }
inline void playableCharacter::setLvl(int lvl){ this->lvl = lvl; }
inline void playableCharacter::setNextLvl(int nextLvl){ this->nextLvl = nextLvl; }
inline void playableCharacter::setExp(int exp){ this->exp = exp; }

void playableCharacter::gainExp(int exp){
    this -> exp += exp;
    this -> testLevelUp();
}

void playableCharacter::testLevelUp(){
    if(this -> exp > this -> nextLvl){
        std::cout << "You levelled up!\n" << std::endl;
        this -> lvl++;
        this -> exp -= this -> nextLvl;
        this -> nextLvl *= 1.05;
        this -> maxhp *= 1.05;
        this -> testLevelUp();
        std::cout << "You need " << nextLvl - exp << " exp to level up again!" << std::endl;
        clearScreen();
    }
}
/*The enemy constructor sets all of the values required
by the entity class, which can be found above. It can also
use the appearance message*/
enemy::enemy(std::string type, int hp, int lvl, int evasiveness, int exp, float reward, bool doAppearance){
    #ifdef DEBUG
    std::clog << "[DEBUG] ENTITY CREATED" << std::endl;
    pause(false);
    #endif // DEBUG
    this -> type = type;
    this -> maxhp = hp;
    this -> hp = hp;
    this -> lvl = lvl;
    this -> evasiveness = evasiveness;
    this -> exp = exp;
    this -> reward = reward;
    if(doAppearance) appearanceMessage();
}

//Same thing as above but without doAppearance
enemy::enemy(std::string type, int hp, int lvl, int exp, int evasiveness, float reward){
    #ifdef DEBUG
    std::clog << "[DEBUG] ENTITY CREATED" << std::endl;
    pause(false);
    #endif // DEBUG
    this -> type = type;
    this -> maxhp = hp;
    this -> hp = hp;
    this -> lvl = lvl;
    this -> exp = exp;
    this -> evasiveness = evasiveness;
    this -> reward = reward;
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
    this -> exp = -99999;
}

//This is a way to add the attributes of the enemy after creating it, rather than in the constructor
void enemy::setAttributes(std::string type, int hp, int lvl, int evasiveness, int exp, float reward){
    this -> type = type;
    this -> maxhp = hp;
    this -> hp = hp;
    this -> lvl = lvl;
    this -> evasiveness = evasiveness;
    this -> exp = exp;
    this -> reward = reward;
}

int enemy::getExp(){return this -> exp;}

std::string enemy::getType(){
    return type;
}

float enemy::calculateReward(){
    float multiplier = static_cast<float>(rand() % 20) / 10;
    return reward * multiplier;
}

void enemy::appearanceMessage(){
    std::cout << "A wild level " << lvl  << " " << type << " has appeared!" << std::endl;
}
