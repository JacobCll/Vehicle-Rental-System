#ifndef ADMINMENU_H
#define ADMINMENU_H

#include "CustomerManager.h"
#include "InterfaceManager.h"
#include "Utils.h"
#include <iostream>
#include <string>
using namespace std;

class AdminMenu {
private:
    InterfaceManager& interfaceManager;
    CustomerManager& customerManager;

    void handleInput();
public:
    AdminMenu(InterfaceManager& im, CustomerManager& cm);
    void run();
};

#endif
