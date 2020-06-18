#pragma once

class gameInterface{
public:
    int startAttack(playableCharacter *player, enemy opponent);
    std::string displayHealth(entity target);

private:
    int playerAttack(playableCharacter *player, enemy opponent);
    int opponentAttack(enemy opponent, playableCharacter *player);
};
