#ifndef OSDEPENDENT
#define OSDEPENDENT

//functions from other files
void selectInventoryItem(playableCharacter *player);

std::array<std::string, 10> handleMove(int x, int y, std::array<std::string, 10> map, int direction,
                                       enemy onHitX, playableCharacter *player, gameInterface ui, int level);

/*This is a simple function that clears the screen
based on what operating system used, since they're different
for whatever reason*/
inline void clearScreen(){

    #ifdef WINDOWS

    system("PAUSE");
    system("CLS");

    #endif // WINDOWS
    #ifdef LINUX

    //Cont is just a variable that'll be used for getline()
    std::string cont;

    //Prompts player to press enter, flushes buffer and clears screen
    std::cout << "Press enter to continue..." << std::endl;
    std::cin.clear();
    std::cin.ignore(1);
    std::getline(std::cin, cont);

    system("clear");

    #endif // LINUX
}

inline void clearScreenPromptless(){

    #ifdef WINDOWS
    system("CLS");
    #endif // WINDOWS
    #ifdef LINUX
    system("clear");
    #endif // LINUX
}


/*This looks surprisingly cryptic for what it is. Basically just pauses the execution until a key is pressed,
and the boolean parameter is just to specify whether you want a prompt to show up or not for the pause*/
inline void pause(bool showPromp){

    if(showPromp){
        #ifdef WINDOWS
        system("PAUSE");
        #endif //WINDOWS
        #ifdef LINUX
        std::cout << "Press enter to continue..." << std::endl;
        #endif // LINUX
    } else {
        #ifdef WINDOWS
        system("PAUSE > NUL");
        #endif // WINDOWS
    }

    #ifdef LINUX
    std::string cont;
    std::cin.clear();
    std::cin.ignore(1);
    std::getline(std::cin, cont);
    #endif // LINUX
}

void displayMap(int level, playableCharacter *player, gameInterface ui){

    //declares the map array, and the x and y co ords
    std::array<std::string, 10> map;
    int playerX, playerY;
    enemy onHitX;
    std::string key = "\nKEY:\nO = Player\n# = Wall\nX = Enemy\n";
    std::string controls = "Controls:\nWASD to move\ni for inventory";

    //Just sets the level based on the level provided to the function
    switch(level){
        case 1:
            map[0] = "###################";
            map[1] = "#O       #        #";
            map[2] = "#        ###      #";
            map[3] = "#        X #      #";
            map[4] = "########## #      #";
            map[5] = "#          X      #";
            map[6] = "#          #      #";
            map[7] = "#                 #";
            map[8] = "#          #      D";
            map[9] = "###################";
            playerX = 1; playerY = 1;
            onHitX.setAttributes("Training Dummy", 50, 0, 0, 35);
            break;
        case 2:
            theEmptyRoom(ui, player);
            map[0] = "###############D###";
            map[1] = "#                 #";
            map[2] = "##X################";
            map[3] = "#                 #";
            map[4] = "#                 #";
            map[5] = "#                 #";
            map[6] = "#                 #";
            map[7] = "#                 #";
            map[8] = "#O                #";
            map[9] = "###################";
            playerX = 1; playerY = 8;
            onHitX.setAttributes("WALL", 250, -10, 0, 100);
            break;

        case 3:
            enterTheRealWorld(ui, player);
            map[0] = "###############D###";
            map[1] = "#                 #";
            map[2] = "# #####    ###### #";
            map[3] = "# #   H    #    # #";
            map[4] = "# #####    ###### #";
            map[5] = "# #   #    #  #   #";
            map[6] = "# #####    #  #   #";
            map[7] = "#          ####   #";
            map[8] = "#O                #";
            map[9] = "###################";
            playerX = 1; playerY = 8;
            onHitX.setAttributes("How'd you even get here?", 9999999, 9999999, 9999999, -99999);
            key += "H = Health Stop\n";
            break;

        default:
            map[0] = "============";
            map[1] = "YOU";
            map[2] = "FIND";
            map[3] = "YOURSELF";
            map[4] = "IN";
            map[5] = "A";
            map[6] = "STRANGE";
            map[7] = "PLACE";
            map[8] = "============";
            map[9] = "";
            playerX = 100; playerY = 100;
    }

    bool running = true;
    #ifdef WINDOWS

    while(running == true){
        //prints out the map
        system("CLS");
        for(int i = 0; i < 10; i++){
            std::cout << map[i] << std::endl;
        }
        std::cout << key << std::endl;
        std::cout << controls << std::endl;
        system("PAUSE > NUL");

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

        if(GetAsyncKeyState(0x49)){
            selectInventoryItem(player);
            clearScreen();
        }
    }

    #endif // WINDOWS
    #ifdef LINUX

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

    #endif // LINUX
}

inline int startBattle(enemy opponent, playableCharacter *player, gameInterface ui){
    clearScreen();
    opponent.appearanceMessage();
    return ui.startAttack(player, opponent);
}

//0 = up, 1 = right, 2 = down, 3 = left for the direction
std::array<std::string, 10> handleMove(int x, int y, std::array<std::string, 10> map, int direction,
                                       enemy onHitX, playableCharacter *player, gameInterface ui, int level){
    //basically, if you hit a wall, do nothing, if you hit a door, load map, if you hit an enemy, battle
    if(map[y][x] == '#') return map;
    if(map[y][x] == 'D') displayMap(++level, player, ui);
    if(map[y][x] == 'H') {
        player->setHp(player->getMaxHp());
        std::cout << "Here, take your health back!" << std::endl;
        pause(false);
        return map;
    }
    if(map[y][x] == 'X') {
        int won = startBattle(onHitX, player, ui);
        if(!won || won == 2) return map;
    }
    //changes the current location to the player, replaces old location with space
    map[y][x] = 'O';
    switch(direction){
        case 0: map[y + 1][x] = ' '; break;
        case 1: map[y][x - 1] = ' '; break;
        case 2: map[y - 1][x] = ' '; break;
        case 3: map[y][x + 1] = ' '; break;
    }
    return map;
}

#endif // OSDEPENDENT

