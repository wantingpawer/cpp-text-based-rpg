#include "common.h"

void mainMenu(gameInterface ui){
    std::cout << "============\n"
              << "Un-Named RPG\n"
              << "============"
              << std::endl;
    std::cout << "\nWelcome! Select an option below!" << std::endl;
    int input;
    bool validInput = false;
    while(!validInput){
        std::cout << "1) Start a new game" << std::endl;
        std::cout << "2) Load a game (WIP)" << std::endl;
        std::cin >> input;
        if(input == 1){
            std::cin.clear();
            std::cin.ignore(100, '\n');
            playableCharacter player = start(ui);
            beginning(ui, &player);
            validInput = true;
            break;
        }
        switch(input){
            case 2: std::cout << "ERROR: This is WIP" << std::endl; break;
            default : std::cout << "Invalid input" << std::endl; break;
        }
    }
}

int main(){

    //creates an object of the UI and the player
    gameInterface ui; //interface.h

    //This sets up the game, ready for it to be played
    mainMenu(ui);

    return 0;
}
