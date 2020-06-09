#include "common.h"

void mainMenu(){

    //creates an object of the UI and the player
    gameInterface ui; //interface.h

    std::cout << "============\n"
              << "Un-Named RPG\n"
              << "============"
              << std::endl;
    std::cout << "\nWelcome! Select an option below!" << std::endl;

    //variables for input (this is pretty self explanatory)
    int input;
    bool validInput = false;

    while(!validInput){
        std::cout << "1) Start a new game" << std::endl;
        std::cout << "2) Load a game" << std::endl;
        std::cin >> input;

        //Ignore any errors and ignore 100 characters until a newline
        std::cin.clear();
        std::cin.ignore(100, '\n');

        /*this is outside of the switch because C++ doesn't like it in the switch
        (I think because there's a switch statement inside of the function?)*/
        if(input == 1){
            playableCharacter player = start(ui);
            beginning(ui, &player);
            validInput = true;
            break;
        }

        switch(input){
            case 2: loadGame(ui); break;
            default : std::cout << "Invalid input" << std::endl; break;
        }
    }
}

int main(){

    //This sets up the game, ready for it to be played
    mainMenu();

    return 0;
}
