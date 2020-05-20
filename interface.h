#ifndef GAMEINTERFACE
#define GAMEINTERFACE

//Functions from other files
void died(playableCharacter *player);
void selectInventoryItem(playableCharacter *player);

//This function is just here so that it's cleaner to display the health of entities
std::string gameInterface::displayHealth(entity target){
    return std::to_string(target.getHp()) + "/" + std::to_string(target.getMaxHp());
}

    //When run, this'll start the attack sequence
int gameInterface::startAttack(playableCharacter *player, enemy opponent){

    bool escaped = false;
    std::cout << "=== A BATTLE HAST BEGUN ===\n" <<
        "Level " << player->getLvl() << " " << player->getName() << ": " << displayHealth(*player) << "\n"
        << "Level " << opponent.getLvl() << " " <<opponent.getType() << ": " << displayHealth(opponent) << "\n"
        << std::endl;

    while(player->getHp() > 0 && opponent.getHp() > 0) {

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
        player->takeDmg(opponentDmg);

        clearScreen(); //OSdependent.h

        //This simply displays the health of the players
        std::cout << "Level " << player->getLvl() << " " << player->getName() << ": " << displayHealth(*player) << "\n"
                << "Level " << opponent.getLvl() << " " <<opponent.getType() << ": " << displayHealth(opponent) << "\n"
                << std::endl;
    }

    /*This is just where it figures out the winner and prints
    the appropriate thing */
    if(escaped) {
        std::cout << "You successfully fled!" << std::endl;
        clearScreen();
        return 2;
    }
    int won;
    player->getHp() <= 0 ? won = 0 : won = 1;
    std::cout << (won ? "You" : opponent.getType()) << " won the battle!" << std::endl;
    if(!won){
        int lives = player->getLives();
        player->setLives(--lives);
        std::string lifeOrLives = lives == 1 ? " life" : " lives";
        std::cout << "You have " << lives << lifeOrLives << " remaining!" << std::endl;
        if(lives > 0){
            player->setHp(player->getMaxHp());
        }else died(player);
    }else{
        int gained = opponent.getExp();
        std::cout << "You gained " << gained << " experience!" << std::endl;
        player->gainExp(gained);
    }
    clearScreen();
    return won; //0 if lost,  1 if won
}

int gameInterface::playerAttack(playableCharacter *player, enemy opponent){
    int choice;
    int dmg = 0;
    std::cout << "Choose an action:\n" << "1) " << player->getAttack() << "\n2) Run\n3) Inventory" << std::endl;
    std::cin >> choice;

    //This switch statement just checks for the choice the player made and acts appropriately
    switch(choice){
        case 1: dmg = player->fight.calculateDmg(player, &opponent); break;
        case 2: player->tryToEscape() ? dmg = -1 : dmg = 0; break;
        case 3: selectInventoryItem(player); break;
        default:
            std::cout << "Invalid selection! No damage dealt." << std::endl;
            break;
    }
    std::cin.clear();
    std::cin.ignore(100, '\n');
    if(dmg == -1) return dmg;
    if(dmg == 0) {std::cout << "You missed your attack!\n" << std::endl; return dmg; }
    std::cout << "You dealt " << dmg << " damage!\n" << std::endl;  //don't wanna display -1 dmg
    return dmg;
}

/*As there is no choice this is a separate function that doesn't have a choice and just
calculates the damage done*/
int gameInterface::opponentAttack(enemy opponent, playableCharacter *player){
    int dmg = opponent.fight.calculateDmg(&opponent, player);
    if(dmg == 0) {std::cout << opponent.getType() << " missed!" << std::endl; return dmg;}
    std::cout << opponent.getType() << " dealt " << dmg << " damage to you!\n" << std::endl;
    return dmg;
}


#endif // GAMEINTERFACE
