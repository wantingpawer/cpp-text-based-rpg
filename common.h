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
#define WINDOWS
//#define LINUX

#define __BEGINNINGLEVEL 1

#ifdef WINDOWS
#define __CLEARSCREENPROMPTLESS(){system("CLS");} //Just a macro to clear the screen depending on the platform
#elif LINUX
#define __CLEARSCREENPROMPTLESS(){system("clear");}
#endif // WINDOWS

#ifdef WINDOWS
#include "windows.h"
#endif // WINDOWS

#include "classDefinitions.h"
#include "dialogue.h"
#include "OSdependent.h"
#include "interface.h"
#include "entities.h"
#include "attacks.h"
#include "gameFunctions.h"

#endif // COMMON
