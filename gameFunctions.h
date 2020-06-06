#ifndef GAMEFUNCTIONS
#define GAMEFUNCTIONS

int classSelection();
void viewStats(playableCharacter *player, gameInterface ui);

void died(playableCharacter *player){
    std::cout << "And thus, the adventures of " << player->getName() << " are over." << std::endl;
    clearScreen();
    exit(0);
}

playableCharacter start(gameInterface ui){

    std::srand((int) std::time(0));

    int hp;
    int evasiveness;
    std::string attack, initialClass;

    std::string name;
    std::cout << "What is your name adventurer?" << std::endl;
    std::getline(std::cin, name);
    name.erase(std::remove(name.begin(), name.end(), ','), name.end());
    clearScreen();

    switch(classSelection()){
        case 1:
            hp = 100;
            evasiveness = 25;
            attack = "Crossbow";
            initialClass = "Archer";
            break;

        case 2:
            hp = 150;
            evasiveness = 1;
            attack = "Crushing_strike";
            initialClass = "Knight";
            break;

        case 3:
            hp = 75;
            evasiveness = 10;
            attack = "Fireball";
            initialClass = "Mage";
            break;

        default:
            std::cout << "Something went wrong! Ending process" << std::endl;
            exit(-1);
    }

    playableCharacter player(hp, evasiveness, attack, initialClass);

    //sets the name of the player
    player.setName(name);
    std::cout << "Welcome " << player.getName() << "\n" << std::endl;

    viewStats(&player, ui);

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
void viewStats(playableCharacter *player, gameInterface ui){
    std::cout << "Your HP is " << ui.displayHealth(*player)
              << "\nYour evasiveness is " << player->getEvasiveness()
              << "\nYour attack is " << player->getAttack()
              << "\nYour class is " << player->getClass() << std::endl;
    clearScreen();
}

void useHealingPotion(playableCharacter *player){
    if(player->inventory.healingPotions > 0){
        //Remove 1 healing potion from player if there's any in the inventory
        player->inventory.healingPotions--;
        int maxHeal = 30;
        int minHeal = 20;
        //Generate a random value within the range to heal the player with
        int heal = minHeal + (std::rand() % maxHeal - minHeal);
        int recovered = heal + (player->getLvl() * 10);
        std::cout << "You healed " << recovered << " HP!" << std::endl;
        recovered += player->getHp();
        if(recovered > player->getMaxHp()) recovered = player->getMaxHp();
        //Set the HP to what the player should have recovered to
        player->setHp(recovered);
        std::cout << "You recovered to " << recovered << " HP!" << std::endl;
        return;
    }
    std::cout << "You have no healing potions!" << std::endl;
}

void useMaxHeal(playableCharacter *player){
    if(player->inventory.maxHeal > 0){
        //Same as above but without the random value
        player->inventory.maxHeal--;
        player->setHp(player->getMaxHp());
        std::cout << "You healed to max HP!" << std::endl;
        return;
    }
    std::cout << "You have no max heal potions!" << std::endl;
}

void useLevelUp(playableCharacter *player){
    if(player->inventory.levelUp > 0){
        //Same kind of logic, it just adds the required experience to level up with
        player->inventory.levelUp--;
        int exp = player->getNextLvl();
        player->gainExp(exp);
        std::cout << "You gained " << exp << " experience!" << std::endl;
    }
    std::cout << "You have no level up potions" << std::endl;
}

void selectInventoryItem(playableCharacter *player){
    __CLEARSCREENPROMPTLESS();
    //A menu of sorts, which allows the user to pick an item, pretty self explanatory
    int input;
    std::cout << "1) Healing Potions: " << player->inventory.healingPotions << std::endl;
    std::cout << "2) Max heal Potions: " << player->inventory.maxHeal << std::endl;
    std::cout << "3) Level up Potions: " << player->inventory.levelUp << std::endl;
    std::cout << "4) Cancel (if in battle you'll lose your move)" << std::endl;
    std::cin >> input;
    switch(input){
        case 1: useHealingPotion(player); break;
        case 2: useMaxHeal(player); break;
        case 3: useLevelUp(player); break;
        default: break;
    }
}

//A self explanatory function that returns true if the player has enough money, false if the player doesn't
bool checkMoney(float price, playableCharacter *player){
    if(price > player->inventory.money){
        std::cout << "You is deficient in the funds!" << std::endl;
        return false;
    }else{
        std::cout << "My money! Here take your stupid item!" << std::endl;
        player->inventory.money -= price;
        return true;
    }
}

void shop(playableCharacter *player){
    __CLEARSCREENPROMPTLESS();
    bool showMenu = true;
    //Same as above, except the menu doesn't go after an action except cancel
    while(showMenu){
        int input;
        std::cout << "1) Buy a healing potion [$5]" << std::endl;
        std::cout << "2) Buy a max heal potion [$15]" << std::endl;
        std::cout << "3) Buy a level up potion [$25]" << std::endl;
        std::cout << "4) Cancel" << std::endl;
        std::cout << "\nMonies: " << player->inventory.money << std::endl;
        std::cin >> input;
        switch(input){
            case 1: if(checkMoney(5, player)) player->inventory.healingPotions += 1; break;
            case 2: if(checkMoney(15, player)) player->inventory.maxHeal += 1; break;
            case 3: if(checkMoney(25, player)) player->inventory.levelUp += 1; break;
            default: showMenu = false; break;
        }
        clearScreen();
    }
}

inline int startBattle(enemy opponent, playableCharacter *player, gameInterface ui){
    //Clears screen, does the appearance message and starts the battle
    clearScreen();
    opponent.appearanceMessage();
    return ui.startAttack(player, opponent);
}

//0 = up, 1 = right, 2 = down, 3 = left for the direction
std::array<std::string, 10> handleMove(int x, int y, std::array<std::string, 10> map, int direction,
                                       enemy onHitX, playableCharacter *player, gameInterface ui, int level){
    //basically, if you hit a wall, do nothing, if you hit a door, load map, if you hit an enemy, battle
    if(map[y][x] == '#') return map;
    else if(map[y][x] == 'D') displayMap(++level, player, ui);
    else if(map[y][x] == 'X') {
        int won = startBattle(onHitX, player, ui);
        if(!won || won == 2) return map;
    }
    //H and S are the same as above, just that they're introduced later in the game
    else if(map[y][x] == 'H') {
        player->setHp(player->getMaxHp());
        std::cout << "Here, take your health back!" << std::endl;
        pause(false);
        return map;
    }
    else if(map[y][x] == 'S'){ shop(player); return map; }
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

void loadError(){
    std::cerr << "Something went wrong whilst loading, execution terminating" << std::endl;
    pause(true);
    exit(-1);
}

bool saveGame(playableCharacter *player, int level){
    std::cout << "Please note that you will have to restart the current level after loading" << std::endl;
    pause(true);
    std::ofstream saveFile;
    saveFile.open("save.unnamedgame");
    if(!saveFile) return false;
    try{
        saveFile << level << ","
                 << player->getName() << ","
                 << player->getAttack() << ","
                 << player->getHp() << ","
                 << player->getMaxHp() << ","
                 << player->getLvl() << ","
                 << player->getEvasiveness() << ","
                 << player->getClass() << ","
                 << player->getLives() << ","
                 << player->getExp() << ","
                 << player->getNextLvl() << ","
                 << player->inventory.healingPotions << ","
                 << player->inventory.maxHeal << ","
                 << player->inventory.levelUp << ","
                 << player->inventory.money << std::endl;
        return true;
    }catch(...){
        return false;
    }
}

void loadGame(gameInterface ui){
    std::ifstream loadFile;
    std::vector<std::string> playerStrings;
    std::vector<int> playerInts;
    loadFile.open("save.unnamedgame");
    if(!loadFile) loadError();
    std::string loadedData;
    loadFile >> loadedData;
    try{
        for(int i = 0; i < 14; i++){
            std::size_t pos = loadedData.find(",");
            std::string data = loadedData.substr(0, pos);
            if(i == 1 || i == 2 || i == 7) playerStrings.push_back(data);
            else playerInts.push_back(std::stoi(data));
            loadedData.erase(0, pos + 1);
        }

        //playableCharacter player(hp, evasiveness, attack, initialClass);
        playableCharacter player((playerInts[2]), (playerInts[4]),
                                 playerStrings[1], playerStrings[2]);
        player.setName(playerStrings[0]);
        player.setLvl(playerInts[3]);
        player.setHp(playerInts[1]);
        player.setLives(playerInts[5]);
        player.setExp(playerInts[6]);
        player.setNextLvl(playerInts[7]);
        player.inventory.healingPotions = playerInts[8];
        player.inventory.maxHeal = playerInts[9];
        player.inventory.levelUp = playerInts[10];
        player.inventory.money = std::stof(loadedData);
        displayMap(playerInts[0], &player, ui);
    }catch(...){
        loadError();
    }
}

#endif // GAMEFUNCTIONS
