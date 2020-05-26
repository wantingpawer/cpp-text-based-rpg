#ifndef COMMON
#define COMMON

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <array>

#ifdef WINDOWS
#define __CLEARSCREENPROMPTLESS(){system("CLS");}
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

