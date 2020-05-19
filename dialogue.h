#ifndef DIALOGUE
#define DIALOGUE

//From other files
inline void clearScreen();
void displayMap(int level, playableCharacter* player, gameInterface ui);

//Playersay, MOVSay and sleep are just here to make the code look cleaner
inline void sleep(int duration){
    #ifndef NOSLEEP

    std::chrono::seconds wait(duration);
    std::this_thread::sleep_for(wait);

    #endif // NOSLEEP
}

inline void playerSay(playableCharacter *player, std::string msg){
    std::cout << player->getName() << ": " << msg << std::endl;
    sleep(2);
}

inline void playerSay(playableCharacter *player, std::string msg, int wait){
    std::cout << player->getName() << ": " << msg << std::endl;
    sleep(wait);
}

inline void MOVSay(std::string msg){
    std::cout << "Mysterious Ominous Voice: " << msg << std::endl;
    sleep(2);
}

inline void MOVSay(std::string msg, int wait){
    std::cout << "Mysterious Ominous Voice: " << msg << std::endl;
    sleep(wait);
}

void beginning(gameInterface ui, playableCharacter *player){
    std::cout << "..." << std::endl;
    sleep(3);
    playerSay(player, "Where am I?");
    MOVSay("I'm a mysterious ominous voice, not a GPS!");
    MOVSay("Buuut... I'm a mysterious ominous voice with vision. You're currently in a training room, to prepare you for battle!",
           3);
    playerSay(player, "Battle? What do you mean battle!");
    MOVSay("Oh yeah, we were in a rush to kidnap you, forgot to explain! Basically, something something grand adventure something something dragon.",
           3);
    playerSay(player, "Kidnapping? Explains the chloroform bottle next to me. Also what dragon?");
    MOVSay("Let's not dwell on past events. Here's a living test dummy for you to fight with!\n");
    enemy dummy("Test Dummy", 10, 0, 0, 10, true);
    int won = ui.startAttack(player, dummy);
    switch(won){
    case 0:
        MOVSay("Well... let's pretend that didn't happen!");
        player->setLives(2);
        clearScreen();
        beginning(ui, player);
        break;
    case 1:
        MOVSay("Congratulations! You won! Time for the dragon!");
        break;
    case 2:
        MOVSay("Wow what a brave warrior, running away like that. Try running from the dragon. See where that gets you.");
        playerSay(player, "I presume away from the dragon. Wait");
        break;
    default:
        MOVSay("You find yourself in a strange place...");
        beginning(ui, player);
    }
    playerSay(player, "What the hell is going on with this dragon thing?");
    MOVSay("Don't you worry about that! We'll cross that bridge when we get there.");
    playerSay(player, "For God's sake! First there's a dragon now there's a bridge?");
    MOVSay("God, someone isn't happy! Just wait till we get to the clowns");
    playerSay(player, "THERE ARE CLOWNS TOO!?");
    MOVSay("Oh, yeah, they're epic! Lemme show you one!");
    enemy clown("clown", 10000, 500, 100, 10000, true);
    ui.startAttack(player, clown);
    MOVSay("HA! DID YOU SEE YOUR DEAD FACE JUST THEN?");
    playerSay(player, "How the hell am I still here? I thought I died");
    MOVSay("Oh, yeah I forgot to say, you only have 2 lives.");
    playerSay(player, "Wait, so I've only got 1 life left?");
    MOVSay("That does make sense.");
    playerSay(player, "Bloody hell.");
    MOVSay("You're acting like I killed someone!");
    playerSay(player, "I wonder why...");
    MOVSay("Anyways, I'll let you into the training room now!");
    displayMap(1, player, ui);
}

void theEmptyRoom(gameInterface ui, playableCharacter *player){
    clearScreen();
    MOVSay("Congrats on killing all those dummies!");
    playerSay(player, "What happened to the door?");
    MOVSay("What door?");
    playerSay(player, "The door I got here through");
    MOVSay("You didn't get here through a door");
    playerSay(player, "Then what was that?");
    MOVSay("What was what?");
    playerSay(player, "The thing I came through?");
    MOVSay("What did you come through?");
    playerSay(player, "I came through a door!");
    MOVSay("No you didn't");
    playerSay(player, "Then what did I come through?");
    MOVSay("I have no idea!");
    playerSay(player, "Then how do you know it wasn't a door?");
    MOVSay("I have no idea!");
    playerSay(player, "How'd I end up in this situation!");
    MOVSay("We both established that we have no idea");
    playerSay(player, "...");
    MOVSay("Oh also, there are these holes in the wall that close when you go through.");
    playerSay(player, "THAT'S WHAT A DOOR IS!");
    MOVSay("No, a door is a mysterious 4 letter word.");
    playerSay(player, "ANYWAYS. Where am I?");
    MOVSay("In an empty room");
    playerSay(player, "I can see that...");
    playerSay(player, "I mean, what do I do here?");
    MOVSay("Apparently, there's a living wall here");
    playerSay(player, "Thank god, you finally said something useful.");
    MOVSay("Yay! Onwards we go then!");
}

void enterTheRealWorld(gameInterface ui, playableCharacter *player){
    clearScreen();
    MOVSay("Welcome to the outside world, and congrats on making it out of training!");
    playerSay(player, "But I was literally in the real world before you kidnapped me.");
    MOVSay("Nah, this is the *real* real world!");
    playerSay(player, "That's why the building I just left is labelled \"Simulation Training Room\"");
    MOVSay("What do you mean?");
    playerSay(player, "Where did... You know what, I don't care, just tell me what to do next");
    MOVSay("Well, you stand in a small town. There is a health building which will refill your HP");
    playerSay(player, "Yeah... that's oddly convenient... just like real life...");
    MOVSay("Exactly! Now let's go!");
}

#endif // DIALOGUE
