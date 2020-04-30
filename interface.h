#ifndef INTERFACE
#define INTERFACE


    //When run, this'll start the attack sequence
int interface::startAttack(playableCharacter player, enemy opponent){

    bool escaped = false;
    std::cout << "=== A BATTLE HAST BEGUN ===\n" <<
            player.getName() << ": " << displayHealth(player) << "\n" <<
            opponent.getType() << ": " << displayHealth(opponent) << "\n"<< std::endl;

    while(player.getHp() > 0 && opponent.getHp() > 0) {

        //These just store the damage done by both parties
        int playerDmg = playerAttack(player, opponent);
        int opponentDmg = opponentAttack(opponent, player);

        //Checks if the player escaped and if so, breaks the loop
        if(playerDmg == -1){
                escaped = true;
                break;
        }
        //Calculates damage on both parties
        opponent.takeDmg(playerDmg);
        player.takeDmg(opponentDmg);

        clearScreen(); //OSdependent.h

        //This simply displays the health of the players
        std::cout << player.getName() << ": " << displayHealth(player) << "\n" <<
                opponent.getType() << ": " << displayHealth(opponent) << "\n"<< std::endl;
    }

    /*This is just where it figures out the winner and prints
    the appropriate thing */
    if(escaped) {
        std::cout << "You successfully fled!" << std::endl;
        clearScreen();
        return 2;
    }
    int won;
    player.getHp() <= 0 ? won = 0 : won = 1;
    std::cout << (won ? "You" : opponent.getType()) << " won the battle!" << std::endl;
    clearScreen();
    return won;
}

//This function is just here so that it's cleaner to display the health of entities
std::string interface::displayHealth(entity target){
    return std::to_string(target.getHp()) + "/" + std::to_string(target.getMaxHp());
}

int interface::playerAttack(playableCharacter player, enemy opponent){
    int choice;
    int dmg = 0;
    std::cout << "Choose an action:\n" << "1) " << player.getAttack() << "\n2) Run" << std::endl;
    std::cin >> choice;

    //This switch statement just checks for the choice the player made and acts appropriately
    switch(choice){
        case 1: dmg = player.fight.calculateDmg(&player, &opponent); break;
        case 2: player.tryToEscape() ? dmg = -1 : dmg = 0; break;
        default: std::cout << "Invalid selection! No damage dealt." << std::endl; break;
    }
    if(dmg != -1) std::cout << "You dealt " << dmg << " damage!\n" << std::endl;  //don't wanna display -1 dmg
    return dmg;
}

/*As there is no choice this is a separate function that doesn't have a choice and just
calculates the damage done*/
interface::opponentAttack(enemy opponent, playableCharacter player){
    int dmg = opponent.fight.calculateDmg(&opponent, &player);
    std::cout << opponent.getType() << " dealt " << dmg << " damage to you!\n" << std::endl;
    return dmg;
}


#endif // INTERFACE
