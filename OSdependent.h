#ifndef OSDEPENDENT
#define OSDEPENDENT

/*This is a simple function that clears the screen
based on what operating system used, since they're different
for whatever reason*/
void clearScreen() {

    //Cont is just a variable that'll be used for getline()
    std::string cont;

    //Prompts player to press enter, flushes buffer and clears screen
    std::cout << "Press enter to continue..." << std::endl;
    std::cin.clear();
    std::cin.ignore(1);
    std::getline(std::cin, cont);

    #ifdef WINDOWS

    system("CLS");

    #endif // WINDOWS
    #ifdef LINUX

    system("clear");

    #endif // LINUX
}

#endif // OSDEPENDENT

