void clearScreen() {
    #ifdef WINDOWS
    system("CLS");
    #endif // WINDOWS
    #ifdef LINUX
    system("clear");
    #endif // LINUX
}
