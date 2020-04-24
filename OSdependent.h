
/*This is a simple function that clears the screen
based on what operating system used, since they're different
for whatever reason*/
void clearScreen() {
    #ifdef WINDOWS
    system("CLS");
    #endif // WINDOWS
    #ifdef LINUX
    system("clear");
    #endif // LINUX
}
