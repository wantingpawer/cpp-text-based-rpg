#pragma once
#include "attacks.h"
class entity{
public:
    int takeDmg(int dmg);
    int getHp();
    int getMaxHp();
    int getLvl();
    int getEvasiveness();

    basic_atk fight;

protected:
    int maxhp;
    int hp;
    int lvl;
    int evasiveness;
};

class playableCharacter : public entity{
public:

    //There's probably a better way to do this
    struct inventoryStruct{
        int healingPotions = 1;
        int maxHeal = 0;
        int levelUp = 0;
        float money = 0.0;
    };
    inventoryStruct inventory;

    int getLives();
    int getExp();
    int getNextLvl();
    void setClass(std::string newClass);
    std::string getClass();
    void gainExp(int exp);
    void setLives(int lives);
    void setHp(int hp);
    void setExp(int exp);
    void setNextLvl(int nextLvl);
    void setLvl(int lvl);
    std::string getAttack();
    void setName(std::string name);
    std::string getName();
    bool tryToEscape();
    playableCharacter(int hp, int evasiveness, std::string attack, std::string initialClass);

private:
    std::string attack;
    std::string name;
    std::string playerClass;
    int lives;
    int exp;
    int nextLvl;

    void createAttack();
    void testLevelUp();
};

class enemy : public entity{
public:
    enemy(std::string type, int hp, int lvl, int evasiveness, int exp, float reward, bool doAppearance);
    enemy(std::string type, int hp, int lvl, int exp, int evasiveness, float reward);
    enemy();
    int getExp();
    void setAttributes(std::string type, int hp, int lvl, int evasiveness, int exp, float reward);
    std::string getType();
    void appearanceMessage();
    float calculateReward();

private:
    std::string type;
    float reward;
    //Enemies have experience because that's what's given to a player for killing the enemy
    int exp;
};
