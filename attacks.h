#ifndef ATTACKS
#define ATTACKS
class base_atk{
public:
    int calculateDmg(){
        if(missAttack()) return 0;
        return getDmg();
    }
protected:
    int minDmg;
    int maxDmg;
    int missChance;

    bool missAttack(){
        int random = (std::rand() % 100);
        if (random > missChance) return 0;
        return 1;
    }

    int getDmg(){
        int range = maxDmg - minDmg;
        return minDmg + (std::rand() % range);
    }
};

class basic_atk : public base_atk{
public:
    basic_atk() {
        this -> minDmg = 5;
        this -> maxDmg = 10;
        this -> missChance = 20;
    }
private:

};
#endif //ATTACKS
