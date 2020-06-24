#ifndef OSDEPENDENT
#define OSDEPENDENT
#include "dialogue.h"

//functions from other files
void selectInventoryItem(playableCharacter *player);
void shop(playableCharacter *player);
std::array<std::string, 10> handleMove(int x, int y, std::array<std::string, 10> map, int direction,
                                       enemy onHitX, playableCharacter *player, gameInterface ui, int level);

bool saveGame(playableCharacter *player, int level);
void pauseMenu(gameInterface ui, playableCharacter *player);


/*This is a simple function that clears the screen
based on what operating system used, since they're different
for whatever reason*/
inline void clearScreen(){

    #ifdef _WIN32

    system("PAUSE");
    system("CLS");

    #endif // _WIN32
    #ifdef __linux__

    //Cont is just a variable that'll be used for getline()
    std::string cont;

    //Prompts player to press enter, flushes buffer and clears screen
    std::cout << "Press enter to continue..." << std::endl;
    std::cin.clear();
    std::cin.ignore(1);
    std::getline(std::cin, cont);

    system("clear");

    #endif // __linux__
}

/*This looks surprisingly cryptic for what it is. Basically just pauses the execution until a key is pressed,
and the boolean parameter is just to specify whether you want a prompt to show up or not for the pause*/
inline void pause(bool showPromp){

    if(showPromp){
        #ifdef _WIN32
        system("PAUSE");
        #endif //_WIN32
        #ifdef __linux__
        std::cout << "Press enter to continue..." << std::endl;
        #endif // __linux__
    } else {
        #ifdef _WIN32
        system("PAUSE > NUL");
        #endif // __linux__
    }

    #ifdef __linux__
    std::string cont;
    std::cin.clear();
    std::cin.ignore(1);
    std::getline(std::cin, cont);
    #endif // __linux__
}

void displayMap(int level, playableCharacter *player, gameInterface ui){

    //declares the map array, and the x and y co ords
    std::array<std::string, 10> map;
    int playerX, playerY;
    enemy onHitX;
    std::string key = "\nKEY:\nO = Player\n# = Wall\nX = Enemy\n";
    std::string controls = "Controls:\nWASD to move\ni for inventory\np to save\nESC to pause";

    /*Just sets the level based on the level provided to the function. Also
    sets the player X and Y, and the enemy type on that map*/

    //This switch block is for adding things to key and control and stuff
    switch(level){
        case 8 ... 99:
            key += "K = _kotak\n";
        case 5 ... 7:
            key += "S = Shop\n";
        case 3 ... 4:
            key += "H = Health Stop\n";
    }

    //This is just to have the levels out of the way
    #include "levels.h"

    //I might eventually have something that turns this off (ignore this if I already have)
    bool running = true;
    #ifdef _WIN32

    while(running == true){
        //prints out the map and information about the player
        system("CLS");
        for(int i = 0; i < 10; i++){
            std::cout << map[i] << std::endl;
        }
        std::cout << key << std::endl;
        std::cout << controls << std::endl;
        std::cout << "\nYour Stats:" << std::endl;
        std::cout << "Health: " << ui.displayHealth(*player) << std::endl;
        std::cout << "Class: " << player->getClass() << std::endl;
        std::cout << "Level: " << player->getLvl() << std::endl;
        std::cout << "Exp: " << player->getExp() << "/" << player->getNextLvl() << std::endl;
        std::cout << "Monies: " << player->inventory.money << std::endl;

        //Pauses the program and redirects the message that it's paused into NUL
        system("PAUSE > NUL");

        //Checks for the key pressed by the user
        if(GetAsyncKeyState(VK_UP) || GetAsyncKeyState(0x57)){
            std::array<std::string, 10> newMap = handleMove(playerX, playerY - 1, map, 0, onHitX, player, ui, level);
            if(newMap != map){
                playerY--;
                map = newMap;
            }
        }
        if(GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(0x44)){
            std::array<std::string, 10> newMap = handleMove(playerX + 1, playerY, map, 1, onHitX, player, ui, level);
            if(newMap != map){
                playerX++;
                map = newMap;
            }
        }
        if(GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(0x53)){
            std::array<std::string, 10> newMap = handleMove(playerX, playerY + 1, map, 2, onHitX, player, ui, level);
            if(newMap != map){
                playerY++;
                map = newMap;
            }
        }
        if(GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(0x41)){
            std::array<std::string, 10> newMap = handleMove(playerX - 1, playerY, map, 3, onHitX, player, ui, level);
            if(newMap != map){
                playerX--;
                map = newMap;
            }
        }

        if(GetAsyncKeyState(VK_ESCAPE)){
            pauseMenu(ui, player);
        }

        if(GetAsyncKeyState(0x49)){
            selectInventoryItem(player);
            clearScreen();
        }

        if(GetAsyncKeyState(0x50)){
            bool success = saveGame(player, level);
            if(success){
                std::cout << "Game saved successfully!" << std::endl;
                pause(false);
            }else{
                std::cerr << "Game save failed!" << std::endl;
                pause(false);
            }
        }
    }

    #endif // _WIN32
    #ifdef __linux__

        while(running == true){
        //prints out the map
        system("clear");
        for(int i = 0; i < 10; i++){
            std::cout << map[i] << std::endl;
        }
        std::cout << "\nKEY:\nO = Player\n# = Wall\nX = Enemy\n" << std::endl;
        std::cout << "Controls:\nWASD to move\ni for inventory" << std::endl;
        char c;
        std::cin >> c;

        if(c == 'w' || c == 'W'){
            std::array<std::string, 10> newMap = handleMove(playerX, playerY - 1, map, 0, onHitX, player, ui, level);
            if(newMap != map){
                playerY--;
                map = newMap;
            }
        }
        if(c == 'd' || c == 'D'){
            std::array<std::string, 10> newMap = handleMove(playerX + 1, playerY, map, 1, onHitX, player, ui, level);
            if(newMap != map){
                playerX++;
                map = newMap;
            }
        }
        if(c == 's' || c == 'S'){
            std::array<std::string, 10> newMap = handleMove(playerX, playerY + 1, map, 2, onHitX, player, ui, level);
            if(newMap != map){
                playerY++;
                map = newMap;
            }
        }
        if(c == 'a' || c == 'A'){
            std::array<std::string, 10> newMap = handleMove(playerX - 1, playerY, map, 3, onHitX, player, ui, level);
            if(newMap != map){
                playerX--;
                map = newMap;
            }
        }
        if(c == 'i' || c == 'I'){
            selectInventoryItem(player);
        }

    #endif // __linux__
}

#endif // OSDEPENDENT
