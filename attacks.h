#pragma once
class entity;

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
