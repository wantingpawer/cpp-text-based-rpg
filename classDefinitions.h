#ifndef CLASSDEF
#define CLASSDEF

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
    inline int getLives();
    inline int getExp();
    inline int getNextLvl();
    inline void setClass(std::string newClass);
    std::string getClass();
    void gainExp(int exp);
    inline void setLives(int lives);
    inline void setHp(int hp);
    inline std::string getAttack();
    void setName(std::string name);
    std::string getName();
    bool tryToEscape();
    playableCharacter(int hp, int evasiveness, std::string attack, std::string initialClass);
    struct inventoryStruct{
        int healingPotions = 1;
        int maxHeal = 0;
        int levelUp = 0;
    };
    inventoryStruct inventory;

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
    enemy(std::string type, int hp, int lvl, int evasiveness, int exp, bool doAppearance);
    enemy(std::string type, int hp, int lvl, int exp, int evasiveness);
    enemy();
    inline int getExp();
    void setAttributes(std::string type, int hp, int lvl, int evasiveness, int exp);
    std::string getType();
    void appearanceMessage();

private:
    std::string type;
    //Enemies have experience because that's what's given to a player for killing the enemy
    int exp;
};

#endif // CLASSDEF
