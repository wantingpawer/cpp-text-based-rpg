#ifndef GAMEFUNCTIONS
#define GAMEFUNCTIONS

int classSelection();
void viewStats(playableCharacter player, interface ui);

playableCharacter start(interface ui){

    std::srand((int) std::time(0));

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

inline void playerSay(playableCharacter player, std::string msg){
    std::cout << player.getName() << ": " << msg << std::endl;
}

inline void sleep(int duration){
    std::chrono::seconds wait(duration);
    std::this_thread::sleep_for(wait);
}

void beginning(interface ui, playableCharacter player){
    std::cout << "..." << std::endl;
    sleep(3);
    playerSay(player, "Where am I?");
    sleep(2);
    std::cout << "Mysterious Ominous Voice: I'm a mysterious ominous voice, not a GPS!" << std::endl;
    sleep(2);
    std::cout << "Mysterious Ominous Voice: Buuut... I'm a mysterious ominous voice with" <<
                 " a vision. You're currently in a training room, to prepare you for battle!" << std::endl;
    sleep(3);
    playerSay(player, "Battle? What do you mean battle!");
    sleep(2);
    std::cout << "Mysterious Ominous Voice: Oh yeah, we were in a rush to kidnap you, forgot to explain!\n"
              << "Basically, something something grand adventure something something dragon." << std::endl;
    sleep(5);
    playerSay(player, "Kidnapping? Explains the chloroform bottle next to me. Also what dragon?");
    std::cout << "Mysterious Ominous Voice: Let's not dwell on past events. Here's a living test dummy"
              << " for you to fight with!\n" << std::endl;
    enemy dummy("Test Dummy", 10, 0, 0, true);
    ui.startAttack(player, dummy);
}
#endif // GAMEFUNCTIONS
