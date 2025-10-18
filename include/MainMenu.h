#ifndef MAINMENU_H
#define MAINMENU_H

#include "CustomerManager.h"
#include "InterfaceManager.h"
#include "Utils.h"
#include <iostream>
#include <string>

using namespace std;

class MainMenu {
private:
    // add vehicle manager here later
    InterfaceManager& interfaceManager;
    CustomerManager& customerManager;

    void handleLoggedInInput(string& choice);
    void handleLoggedOutInput(string& choice);
    void handleInput();      
public:
    MainMenu(InterfaceManager& im, CustomerManager& cm); 
    
    void run();                 
};

#endif
