#ifndef ENTITY
#define ENTITY
class entity{
public:

    //Simple getters for classes that inherit from entity
    inline int takeDmg(int dmg){ return hp -= dmg; }
    inline int getHp(){ return hp; }
    inline int getMaxHp() { return maxhp; }
    inline int getLvl() { return lvl; }

protected:

    int maxhp;
    int hp;
    int lvl;
};

//The class that defines the player
class playableCharacter : public entity{
public:
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
    playableCharacter(){
        this -> exp = 0;
        this -> evasiveness = 5;
        this -> maxhp = 100;
        this -> hp = 100;
        this -> lvl = 1;
    }
private:
    std::string name;
    int exp;
    int evasiveness;
};

class enemy : public entity{
public:
    /*The enemy constructor sets all of the values required
    by the entity class, which can be found above. It can also
    use the appearance message*/
    enemy(std::string type, int hp, int lvl, bool doAppearance){
        this -> type = type;
        this -> maxhp = hp;
        this -> hp = hp;
        this -> lvl = lvl;
        if(doAppearance) appearanceMessage();
    }

    //Same thing as above but without doAppearance
    enemy(std::string type, int hp, int lvl){
        this -> type = type;
        this -> maxhp = hp;
        this -> hp = hp;
        this -> lvl = lvl;
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
