#ifndef GAMEFUNCTIONS
#define GAMEFUNCTIONS
#include "entities.h"
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

        default:
            std::cout << "Something went wrong! Ending process" << std::endl;
            exit(-1);
    }

    playableCharacter player(hp, evasiveness, attack);

    //sets the name of the player
    player.setName(name);
    std::cout << "Welcome " << player.getName() << "\n" << std::endl;

    viewStats(player, ui);

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
void viewStats(playableCharacter player, interface ui){
    std::cout << "Your HP is " << ui.displayHealth(player)
              << "\nYour evasiveness is " << player.getEvasiveness()
              << "\nYour attack is " << player.getAttack() << std::endl;
    clearScreen();
}

//Playersay and sleep are just here to make the code look cleaner
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
                 " vision. You're currently in a training room, to prepare you for battle!" << std::endl;
    sleep(3);
    playerSay(player, "Battle? What do you mean battle!");
    sleep(2);
    std::cout << "Mysterious Ominous Voice: Oh yeah, we were in a rush to kidnap you, forgot to explain! "
              << "Basically, something something grand adventure something something dragon." << std::endl;
    sleep(3);
    playerSay(player, "Kidnapping? Explains the chloroform bottle next to me. Also what dragon?");
    sleep(2);
    std::cout << "Mysterious Ominous Voice: Let's not dwell on past events. Here's a living test dummy"
              << " for you to fight with!\n" << std::endl;
    sleep(2);
    enemy dummy("Test Dummy", 10, 0, 0, true);
    int won = ui.startAttack(player, dummy);
    switch(won){
    case 0:
        std::cout << "Mysterious Ominous Voice: Well... let's pretend that didn't happen!" << std::endl;
        clearScreen();
        beginning(ui, player);
        break;
    case 1:
        std::cout << "Mysterious Ominous Voice: Congratulations! You won! Time for the dragon!" << std::endl;
        break;
    case 2:
        std::cout << "Mysterious Ominous Voice: Wow what a brave warrior, running away like that." <<
                    " Try running from the dragon. See where that gets you."<< std::endl;
        break;
    default:
        std::cout << "Mysterious Ominous Voice: You find yourself in a strange place..." << std::endl;
        beginning(ui, player);
    }
    sleep(2);
    playerSay(player, "What the hell is going on with this dragon thing?");
    sleep(2);
    std::cout << "Mysterious Ominous Voice: Don't you worry about that!" <<
                 " We'll cross that bridge when we get there." << std::endl;
    sleep(1);
    playerSay(player, "For God's sake! First there's a dragon now there's a bridge?");
    sleep(2);
    std::cout << "Mysterious Ominous Voice: God, someone isn't happy! Just wait till we get to the clowns"
              << std::endl;
    sleep(1);
    playerSay(player, "THERE ARE CLOWNS TOO!?");
    sleep(2);
    std::cout << "Mysterious Ominous Voice: Oh, yeah, they're epic! Lemme show you one!" << std::endl;
    enemy clown("clown", 10000, 500, 100, true);
    ui.startAttack(player, clown);
    //displayMap(1);
}
#endif // GAMEFUNCTIONS
