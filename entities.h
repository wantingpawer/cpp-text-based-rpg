#ifndef ENTITY
#define ENTITY
class entity{
public:

    //Simple getters for classes that inherit from entity
    inline int takeDmg(int dmg){ return hp -= dmg; }
    inline int getHp(){ return hp; }
    inline int getMaxHp() { return maxhp; }
    inline int getLvl() { return lvl; }
    inline int getEvasiveness() { return evasiveness; }

protected:

    int maxhp;
    int hp;
    int lvl;
    int evasiveness;
};

//The class that defines the player
class playableCharacter : public entity{
public:
    inline std::string getAttack() { return attack; }
    void setName(std::string name){
        this->name = name;
    }
    std::string getName() {
        return name;
    }

    bool tryToEscape() {
        //random value up to 100
        int random = (std::rand() % 100);
        //if that value is higher than the evasiveness, then you didn't escape
        if(random > evasiveness) return false;
        return true;
    }
    /*The playable character constructor
    sets all of the values required by the
    entity class, which can be found above.*/
    playableCharacter(int hp, int evasiveness, std::string attack){
        this -> exp = 0;
        this -> evasiveness = evasiveness;
        this -> maxhp = hp;
        this -> hp = hp;
        this -> lvl = 1;
        this -> attack = attack;
    }
private:
    std::string attack;
    std::string name;
    int exp;
};

class enemy : public entity{
public:
    /*The enemy constructor sets all of the values required
    by the entity class, which can be found above. It can also
    use the appearance message*/
    enemy(std::string type, int hp, int lvl, int evasiveness, bool doAppearance){
        this -> type = type;
        this -> maxhp = hp;
        this -> hp = hp;
        this -> lvl = lvl;
        this -> evasiveness = evasiveness;
        if(doAppearance) appearanceMessage();
    }

    //Same thing as above but without doAppearance
    enemy(std::string type, int hp, int lvl, int evasiveness){
        this -> type = type;
        this -> maxhp = hp;
        this -> hp = hp;
        this -> lvl = lvl;
        this -> evasiveness = evasiveness;
    }


    std::string getType(){
        return type;
    }


    void appearanceMessage(){
        std::cout << "A wild level " << lvl  << " " << type << " has appeared!" << std::endl;
    }
private:
    std::string type;
};
#endif //ENTITIES
