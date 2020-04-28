#define WINDOWS
//#define LINUX

#include "common.h"

int main(){
    std::srand((int) std::time(0));

    //creates an object of the UI and the player
    interface ui; //interface.h

    playableCharacter player = start(ui);

    //creates an instance of the Goblin, with 50 hp, level 3, and it displays an entrance message
    enemy gob1("Goblin", 50, 3, 5, true);

    //gets the UI to start the attack, since that's where it's handled
    ui.startAttack(player, gob1);
    return 0;
}
