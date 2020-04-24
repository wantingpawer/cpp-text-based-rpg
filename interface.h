#ifndef INTERFACE
#define INTERFACE


class interface{
public:
    basic_atk basic_attack;
    void startAttack(playableCharacter player, enemy opponent){
        std::string cont;
        std::cout << "=== A BATTLE HAST BEGUN ===\n" <<
                player.getName() << ": " << displayHealth(player) << "\n" <<
                opponent.getType() << ": " << displayHealth(opponent) << "\n"<< std::endl;

        while(player.getHp() > 0 && opponent.getHp() > 0) {
            opponent.takeDmg(playerAttack());
            player.takeDmg(opponentAttack(opponent));
            std::cout << "Press enter to continue..." << std::endl;
            std::cin.clear();
            std::cin.ignore(1);
            std::getline(std::cin, cont);
            clearScreen();
            std::cout << player.getName() << ": " << displayHealth(player) << "\n" <<
                    opponent.getType() << ": " << displayHealth(opponent) << "\n"<< std::endl;
        }
    }

private:

    std::string displayHealth(entity target){
        return std::to_string(target.getHp()) + "/" + std::to_string(target.getMaxHp());
    }
    int playerAttack(){
        int choice;
        int dmg = 0;
        std::cout << "Choose an action:\n" << "1) Basic attack" << std::endl;
        std::cin >> choice;
        switch(choice){
            case 1: dmg = basic_attack.calculateDmg(); break;
            default: std::cout << "Invalid selection! No damage dealt." << std::endl; break;
        }
        std::cout << "You dealt " << dmg << " damage!\n" << std::endl;
        return dmg;
    }

    int opponentAttack(enemy opponent){
        int dmg = basic_attack.calculateDmg();
        std::cout << opponent.getType() << " dealt " << dmg << " damage to you!\n" << std::endl;
        return dmg;
    }
};

#endif // INTERFACE
