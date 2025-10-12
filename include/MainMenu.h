#ifndef MAINMENU_H
#define MAINMENU_H

#include "CustomerManager.h"
#include "InterfaceManager.h"
#include <iostream>
#include <string>
using namespace std;

class MainMenu {
private:
    InterfaceManager& interfaceManager;
    CustomerManager& customerManager;

    void handleLoggedInInput(string& choice);
    void handleLoggedOutInput(string& choice);
    bool handleInput();       // get and process user input
public:
    MainMenu(InterfaceManager& im, CustomerManager& cm); // constructor
    void run();                 // show the menu
                // process user choice
};

#endif
