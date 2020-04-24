#define WINDOWS
//#define LINUX

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "OSdependent.h"
#include "entities.h"
#include "attacks.h"
#include "interface.h"

int main(){
    std::srand((int) std::time(0));
    interface ui;
    playableCharacter player;
    std::string name;
    std::cout << "What is your name adventurer?" << std::endl;
    std::getline(std::cin, name);
    player.setName(name);
    std::cout << "Welcome " << player.getName() << "\n" << std::endl;
    enemy gob1("Goblin", 50, 3, true);
    ui.startAttack(player, gob1);
    return 0;
}
