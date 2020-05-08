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
    inline std::string getAttack();
    void setName(std::string name);
    std::string getName();
    bool tryToEscape();
    playableCharacter(int hp, int evasiveness, std::string attack);

private:
    std::string attack;
    std::string name;
    int exp;

    void createAttack();
};

class gameInterface{
public:
    int startAttack(playableCharacter player, enemy opponent);
    inline std::string displayHealth(entity target);

private:
    int playerAttack(playableCharacter player, enemy opponent);
    int opponentAttack(enemy opponent, playableCharacter player);
};

class enemy : public entity{
public:
    enemy(std::string type, int hp, int lvl, int evasiveness, bool doAppearance);
    enemy(std::string type, int hp, int lvl, int evasiveness);
    std::string getType();
    void appearanceMessage();

private:
    std::string type;
};

#endif // CLASSDEF
