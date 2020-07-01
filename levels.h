#pragma once

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
        onHitX.setAttributes("Training Dummy", 50, 0, 0, 35, 3);
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
        onHitX.setAttributes("WALL", 250, -10, 0, 100, 0.5);
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
        onHitX.setAttributes("How'd you even get here?", 9999999, 9999999, 9999999, -99999, -99999);
        break;

    case 4:
        banditAttack(ui, player);
        map[0] = "##D################";
        map[1] = "#    #  #        H#";
        map[2] = "##X####     #######";
        map[3] = " #   X####     #  #";
        map[4] = " ####    ####X##  #";
        map[5] = "    ### X#       ##";
        map[6] = "      #    # ##### ";
        map[7] = "#######  ###   #   ";
        map[8] = "#O    X      ###   ";
        map[9] = "##############     ";
        playerX = 1; playerY = 8;
        onHitX.setAttributes("Bandit", 70, 5, 20, 65, 4);
        break;

    case 5:
        cityOfTown(ui, player);
        map[0] = "###############D###";
        map[1] = "###               #";
        map[2] = "##H   ### ### #####";
        map[3] = "#     ### ### #####";
        map[4] = "####  ###     #####";
        map[5] = "#### ######## #####";
        map[6] = "#### S####### #####";
        map[7] = "#### ######## #####";
        map[8] = "#O                #";
        map[9] = "###################";
        playerX = 1; playerY = 8;
        onHitX.setAttributes("How'd you even get here?", 9999999, 9999999, 9999999, -99999, -99999);
        break;

    case 6:
        theBabyDragon(ui, player);
        map[0] = "###################";
        map[1] = "#       #     #####";
        map[2] = "# #####   ### # ###";
        map[3] = "#  # #####    #  ##";
        map[4] = "##  ###  ### ######";
        map[5] = "###    # #DX #  ###";
        map[6] = "###### # ###   ####";
        map[7] = "#        # # ######";
        map[8] = "#O###### # ########";
        map[9] = "###################";
        playerX = 1; playerY = 8;
        onHitX.setAttributes("Baby Dragon", 300, 10, 0, 1000, 45);
        break;

    case 7:
        theGrandEscape(ui, player);
        map[0] = "###############D###";
        map[1] = "#  XX     X XX X  #";
        map[2] = "#   XXXX X  XXXXX #";
        map[3] = "#XXXX X   XXX   X #";
        map[4] = "#   X XXXX XXX  X #";
        map[5] = "#  XXX    X XXX XX#";
        map[6] = "#XXXXXXXXXXXXXXXXX#";
        map[7] = "#  X  XX XXX     X#";
        map[8] = "#O XX  X    XXXX  #";
        map[9] = "###################";
        playerX = 1; playerY = 8;
        onHitX.setAttributes("Dragon Eggs", 3, -1, 0, 5, 1);
        break;

    case 8:
        theMeetUp(ui, player);
        map[0] = "###############D###";
        map[1] = "#                 #";
        map[2] = "########XXX########";
        map[3] = "###    #   #      #";
        map[4] = "#K#    #XXX#      #";
        map[5] = "###    #   #      #";
        map[6] = "#      #XXX#      #";
        map[7] = "########   ########";
        map[8] = "#O                #";
        map[9] = "###################";
        playerX = 1; playerY = 8;
        onHitX.setAttributes("Meaner test dummies", 100, 4, 20, 100, 7);
        break;

    case 9:
        theRealBattlePreparation(ui, player);
        map[0] = "###############D###";
        map[1] = "#                 #";
        map[2] = "######    ###S### #";
        map[3] = "# X X#    #     # #";
        map[4] = "# X       #     # #";
        map[5] = "# X X#    ####### #";
        map[6] = "######   K#     # #";
        map[7] = "#         ###H### #";
        map[8] = "#O                #";
        map[9] = "###################";
        playerX = 1; playerY = 8;
        onHitX.setAttributes("Even meaner test dummies", 150, 8, 30, 120, 10);
        break;

    case 10:
        theRealBattle(ui, player);
        map[0] = "###############D###";
        map[1] = "#             # # #";
        map[2] = "# #############X# #";
        map[3] = "# #X X X  X  X  # #";
        map[4] = "# # X   X  X   X# #";
        map[5] = "# #X  X  X   X  # #";
        map[6] = "# # X   X  X  XX# #";
        map[7] = "###X############# #";
        map[8] = "#O  #             #";
        map[9] = "###################";
        playerX = 1; playerY = 8;
        onHitX.setAttributes("Very Angry Enemies", 200, 10, 35, 130, 12);
        break;

    case 11:
        theMugHouse(ui, player);
        map[0] = "       #D##        ";
        map[1] = "     ###  ###      ";
        map[2] = "  ####BB#   ####   ";
        map[3] = "### BBBB###    ### ";
        map[4] = "#BBBB B  BB#     # ";
        map[5] = "#BBBBB BB###    H# ";
        map[6] = "### BBB B#     ### ";
        map[7] = "  #### B#   ####   ";
        map[8] = "     ###KO###      ";
        map[9] = "       ####        ";
        playerX = 9; playerY = 8;
        onHitX.setAttributes("How'd you even get here?", 9999999, 9999999, 9999999, -99999, -99999);
        key += "B = bakugan\n";
        break;

    case 12:
        howManyTowns(ui, player);
        map[0] = "###############D###";
        map[1] = "#                 #";
        map[2] = "##X#X#X#X#X#X#X#X##";
        map[3] = "#                 #";
        map[4] = "##X#X#X#X#X#X#X#X##";
        map[5] = "#                 #";
        map[6] = "##X#X#X#X#X#X#X#X##";
        map[7] = "#                 #";
        map[8] = "#O                #";
        map[9] = "###################";
        playerX = 1; playerY = 8;
        onHitX.setAttributes("WALL", 250, -10, 0, 100, 0.5);
        break;

    case 13:
        isntThisTheSame(ui, player);
        map[0] = "###############D###";
        map[1] = "#                 #";
        map[2] = "# #####    ###### #";
        map[3] = "# #   H    S    # #";
        map[4] = "# #####    ###### #";
        map[5] = "# #   #    #  #   #";
        map[6] = "# #####    #  #   #";
        map[7] = "#         K####   #";
        map[8] = "#O                #";
        map[9] = "###################";
        playerX = 1; playerY = 8;
        onHitX.setAttributes("How'd you even get here?", 9999999, 9999999, 9999999, -99999, -99999);
        break;

    case 14:
        DRAGON(ui, player);
        map[0] = "###################";
        map[1] = "#                 #";
        map[2] = "####              #";
        map[3] = "D  X              #";
        map[4] = "####              #";
        map[5] = "#                 #";
        map[6] = "########  #########";
        map[7] = "       #  #        ";
        map[8] = "       # O#        ";
        map[9] = "       ####        ";
        playerX = 9; playerY = 8;
        onHitX.setAttributes("DRAGON!!!", 550, 25, 45, 10000, 1000);
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
        break;
}

