#include "../../include/Utils.h"
#include <cstdlib>
using namespace std;

void clearScreen() { //clears screen based on OS

    #ifdef _WIN32 // Windows system           
        system("cls");
    #else
        system("clear"); // Unix/Linux/Mac system
    #endif
}
void pauseScreen() { //pauses screen until user presses enter
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

