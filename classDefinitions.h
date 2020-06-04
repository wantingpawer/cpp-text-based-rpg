#ifndef CLASSDEF
#define CLASSDEF

/*
Everything here is just to define all the classes being
used in the program. This is so that every class knows the
exact memory layout of every other class and can therefore
use them in their own class members
*/

class entity;
class base_atk;
class basic_atk;
class playableCharacter;
class gameInterface;
class enemy;

class base_atk{
public:
    int calculateDmg(entity *target, entity *opponent);
protected:
    int minDmg;
    int maxDmg;
    int missChance;
    bool missAttack(entity *opponent);
    int getDmg();
};

class basic_atk : public base_atk{
public:
    void setParams(int minDmg, int maxDmg, int missChance);
    void setParams(int minDmg, int maxDmg);
    basic_atk();
};

class entity{
public:
    inline int takeDmg(int dmg);
    inline int getHp();
    inline int getMaxHp();
    inline int getLvl();
    inline int getEvasiveness();

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

    inline int getLives();
    inline int getExp();
    inline int getNextLvl();
    inline void setClass(std::string newClass);
    std::string getClass();
    void gainExp(int exp);
    inline void setLives(int lives);
    inline void setHp(int hp);
    inline void setExp(int exp);
    inline void setNextLvl(int nextLvl);
    inline void setLvl(int lvl);
    inline std::string getAttack();
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

class gameInterface{
public:
    int startAttack(playableCharacter *player, enemy opponent);
    inline std::string displayHealth(entity target);

private:
    int playerAttack(playableCharacter *player, enemy opponent);
    int opponentAttack(enemy opponent, playableCharacter *player);
};

class enemy : public entity{
public:
    enemy(std::string type, int hp, int lvl, int evasiveness, int exp, float reward, bool doAppearance);
    enemy(std::string type, int hp, int lvl, int exp, int evasiveness, float reward);
    enemy();
    inline int getExp();
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

#endif // CLASSDEF
