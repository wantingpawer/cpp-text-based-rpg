#ifndef COMMON
#define COMMON

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <array>

//#define NOSLEEP
//#define DEBUG

#define __BEGINNINGLEVEL 1

#ifdef _WIN32
#define __CLEARSCREENPROMPTLESS(){system("CLS");} //Just a macro to clear the screen depending on the platform
#elif __linux__
#define __CLEARSCREENPROMPTLESS(){system("clear");}
#endif // _WIN32

#ifdef _WIN32
#include "windows.h"
#endif // _WIN32

#include "attacks.cpp"
#include "entities.cpp"
#include "interface.cpp"
#include "attacks.h"
#include "entities.h"
#include "interface.h"
#include "dialogue.h"
#include "OSdependent.h"
#include "gameFunctions.h"

#endif // COMMON
