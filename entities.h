#ifndef ENTITY
#define ENTITY
class entity{
public:
    inline int takeDmg(int dmg){ return hp -= dmg; }
    inline int getHp(){ return hp; }
    inline int getMaxHp() { return maxhp; }

protected:

    int maxhp;
    int hp;
    int lvl;
};

class actions{
public:
    int attack(){return 0;}
};

class playableCharacter : public entity{
public:
    void setName(std::string name){
        this->name = name;
    }
    std::string getName() {
        return name;
    }

    /*The playable character constructor
    sets all of the values required by the
    entity class, which can be found above.*/
    playableCharacter(){
        this -> maxhp = 100;
        this -> hp = 100;
        this -> lvl = 1;
    }
private:
    std::string name;
    int exp = 0;
};

class enemy : public entity{
public:
    enemy(std::string type, int hp, int lvl, bool doAppearance){
        this -> type = type;
        this -> maxhp = hp;
        this -> hp = hp;
        this -> lvl = lvl;
        if(doAppearance) appearanceMessage();
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
