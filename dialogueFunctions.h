#pragma once

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

inline void NPCSay(std::string npcName, std::string msg){
    std::cout << npcName << ": " << msg << std::endl;
    sleep(2);
}

inline void NPCSay(std::string npcName, std::string msg, int wait){
    std::cout << npcName << ": " << msg << std::endl;
    sleep(wait);
}
