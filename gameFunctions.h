#ifndef GAMEFUNCTIONS
#define GAMEFUNCTIONS

int classSelection();
void viewStats(playableCharacter player, interface ui);

playableCharacter start(interface ui){

    int hp;
    int evasiveness;
    std::string attack;

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
            break;

        case 2:
            hp = 150;
            evasiveness = 1;
            attack = "Crushing_strike";
            break;

        case 3:
            hp = 75;
            evasiveness = 10;
            attack = "Fireball";
            break;
    }

    playableCharacter player(hp, evasiveness, attack);

    //sets the name of the player
    player.setName(name);
    std::cout << "Welcome " << player.getName() << "\n" << std::endl;

    viewStats(player, ui);

    return player;
}

int classSelection(){
    std::cout << "\nSelect a class:\n"
          << "1) Archer\n"
          << "2) Knight\n"
          << "3) Mage\n"
          << std::endl;

    int choice;
    std::cin >> choice;
    if(choice > 3 || choice < 1) {
        std::cout << "Invalid selection!" << std::endl;
        clearScreen();
        classSelection();
    }

    return choice;
}

void viewStats(playableCharacter player, interface ui){
    std::cout << "Your HP is " << ui.displayHealth(player)
              << "\nYour evasiveness is " << player.getEvasiveness()
              << "\nYour attack is " << player.getAttack() << std::endl;
    clearScreen();
}

#endif // GAMEFUNCTIONS
