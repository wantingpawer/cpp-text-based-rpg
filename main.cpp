//#define NOSLEEP
#define WINDOWS
//#define LINUX

#include "common.h"

int main(){

    //creates an object of the UI and the player
    gameInterface ui; //interface.h

    //This sets up the game, ready for it to be played
    playableCharacter player = start(ui);

    beginning(ui, &player);
    return 0;
}
