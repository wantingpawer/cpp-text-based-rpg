#ifndef INTERFACE
#define INTERFACE


class interface{
public:
    //creates instances of the attacks
    basic_atk basic_attack;

    //When run, this'll start the attack sequence
    void startAttack(playableCharacter player, enemy opponent){

        //Cont is just a variable that'll be used for getline()
        std::string cont;

        bool escaped = false;
        std::cout << "=== A BATTLE HAST BEGUN ===\n" <<
                player.getName() << ": " << displayHealth(player) << "\n" <<
                opponent.getType() << ": " << displayHealth(opponent) << "\n"<< std::endl;

        while(player.getHp() > 0 && opponent.getHp() > 0) {

            //These just store the damage done by both parties
            int playerDmg = playerAttack(player);
            int opponentDmg = opponentAttack(opponent);

            //Checks if the player escaped and if so, breaks the loop
            if(playerDmg == -1){
                    escaped = true;
                    break;
            }
            //Calculates damage on both parties
            opponent.takeDmg(playerDmg);
            player.takeDmg(opponentDmg);

            //Prompts player to press enter, flushes buffer and clears screen
            std::cout << "Press enter to continue..." << std::endl;
            std::cin.clear();
            std::cin.ignore(1);
            std::getline(std::cin, cont);
            clearScreen();

            //This simply displays the health of the players
            std::cout << player.getName() << ": " << displayHealth(player) << "\n" <<
                    opponent.getType() << ": " << displayHealth(opponent) << "\n"<< std::endl;
        }

        /*This is just where it figures out the winner and prints
        the appropriate thing */
        if(escaped) {
            std::cout << "You successfully fled!" << std::endl;
        }else{
            std::string winner;
            if(player.getHp() <= 0){
                winner = opponent.getType();
            }else{
                winner = "You";
            }
            std::cout << winner << " won the battle!" << std::endl;
        }
    }

private:

    //This function is just here so that it's cleaner to display the health of entities
    inline std::string displayHealth(entity target){
        return std::to_string(target.getHp()) + "/" + std::to_string(target.getMaxHp());
    }


    int playerAttack(playableCharacter player){
        int choice;
        int dmg = 0;
        std::cout << "Choose an action:\n" << "1) Basic attack\n2) Run" << std::endl;
        std::cin >> choice;

        //This switch statement just checks for the choice the player made and acts appropriately
        switch(choice){
            case 1: dmg = basic_attack.calculateDmg(player); break;
            case 2: player.tryToEscape() ? dmg = -1 : dmg = 0; break;
            default: std::cout << "Invalid selection! No damage dealt." << std::endl; break;
        }
        if(dmg != -1) std::cout << "You dealt " << dmg << " damage!\n" << std::endl;
        return dmg;
    }

    /*As there is no choice this is a separate function that doesn't have a choice and just
    calculates the damage done*/
    int opponentAttack(enemy opponent){
        int dmg = basic_attack.calculateDmg(opponent);
        std::cout << opponent.getType() << " dealt " << dmg << " damage to you!\n" << std::endl;
        return dmg;
    }
};

#endif // INTERFACE
