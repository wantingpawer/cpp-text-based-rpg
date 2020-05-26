#ifndef GAMEFUNCTIONS
#define GAMEFUNCTIONS

int classSelection();
void viewStats(playableCharacter *player, gameInterface ui);

void died(playableCharacter *player){
    std::cout << "And thus, the adventures of " << player->getName() << " are over." << std::endl;
    clearScreen();
    exit(0);
}

playableCharacter start(gameInterface ui){

    std::srand((int) std::time(0));

    int hp;
    int evasiveness;
    std::string attack, initialClass;

    std::cout << "============\n"
              << "Un-Named RPG\n"
              << "============"
              << std::endl;

    std::string name;
    std::cout << "What is your name adventurer?" << std::endl;
    std::getline(std::cin, name);

    clearScreen();

    switch(classSelection()){
        case 1:
            hp = 100;
            evasiveness = 25;
            attack = "Crossbow";
            initialClass = "Archer";
            break;

        case 2:
            hp = 150;
            evasiveness = 1;
            attack = "Crushing_strike";
            initialClass = "Knight";
            break;

        case 3:
            hp = 75;
            evasiveness = 10;
            attack = "Fireball";
            initialClass = "Mage";
            break;

        default:
            std::cout << "Something went wrong! Ending process" << std::endl;
            exit(-1);
    }

    playableCharacter player(hp, evasiveness, attack, initialClass);

    //sets the name of the player
    player.setName(name);
    std::cout << "Welcome " << player.getName() << "\n" << std::endl;

    viewStats(&player, ui);

    return player;
}

int classSelection(){
    std::cout << "Select a class:\n"
          << "1) Archer\n"
          << "2) Knight\n"
          << "3) Mage\n"
          << std::endl;

    int choice;
    std::cin >> choice;
    if(choice > 3 || choice < 1) {
        std::cout << "Invalid selection!" << std::endl;
        clearScreen();
        choice = classSelection();
    }

    return choice;
}

//The view stats function just allows the user to see their stats
void viewStats(playableCharacter *player, gameInterface ui){
    std::cout << "Your HP is " << ui.displayHealth(*player)
              << "\nYour evasiveness is " << player->getEvasiveness()
              << "\nYour attack is " << player->getAttack()
              << "\nYour class is " << player->getClass() << std::endl;
    clearScreen();
}

void useHealingPotion(playableCharacter *player){
    if(player->inventory.healingPotions > 0){
        player->inventory.healingPotions--;
        int maxHeal = 30;
        int minHeal = 20;
        int heal = minHeal + (std::rand() % maxHeal - minHeal);
        int recovered = heal + (player->getLvl() * 10);
        std::cout << "You healed " << recovered << " HP!" << std::endl;
        recovered += player->getHp();
        if(recovered > player->getMaxHp()) recovered = player->getMaxHp();
        player->setHp(recovered);
        std::cout << "You recovered to " << recovered << " HP!" << std::endl;
        return;
    }
    std::cout << "You have no healing potions!" << std::endl;
}

void useMaxHeal(playableCharacter *player){
    if(player->inventory.maxHeal > 0){
        player->inventory.maxHeal--;
        player->setHp(player->getMaxHp());
        std::cout << "You healed to max HP!" << std::endl;
        return;
    }
    std::cout << "You have no max heal potions!" << std::endl;
}

void useLevelUp(playableCharacter *player){
    if(player->inventory.levelUp > 0){
        player->inventory.levelUp--;
        int exp = player->getNextLvl();
        player->gainExp(exp);
        std::cout << "You gained " << exp << " experience!" << std::endl;
    }
    std::cout << "You have no level up potions" << std::endl;
}

void selectInventoryItem(playableCharacter *player){
    __CLEARSCREENPROMPTLESS();
    int input;
    std::cout << "1) Healing Potions: " << player->inventory.healingPotions << std::endl;
    std::cout << "2) Max heal Potions: " << player->inventory.maxHeal << std::endl;
    std::cout << "3) Level up Potions: " << player->inventory.levelUp << std::endl;
    std::cout << "4) Cancel (if in battle you'll lose your move)" << std::endl;
    std::cin >> input;
    switch(input){
        case 1: useHealingPotion(player); break;
        case 2: useMaxHeal(player); break;
        case 3: useLevelUp(player); break;
        default: break;
    }
}

void shop(playableCharacter *player){
    __CLEARSCREENPROMPTLESS();
    int input;
    std::cout << "1) Buy a healing potion [$5]" << std::endl;
    std::cout << "2) Buy a max heal potion [$15]" << std::endl;
    std::cout << "3) Buy a level up potion [$25]" << std::endl;
    std::cout << "4) Cancel" << std::endl;
    std::cin >> input;
    switch(input){
        case 1: player->inventory.healingPotions += 1; break;
        case 2: player->inventory.maxHeal += 1; break;
        case 3: player->inventory.levelUp += 1; break;
        default: break;
    }
}

#endif // GAMEFUNCTIONS
