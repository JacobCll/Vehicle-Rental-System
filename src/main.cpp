#include "../include/InterfaceManager.h"
#include "../include/CustomerManager.h"
#include "../include/MainMenu.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    InterfaceManager interfaceManager;
    CustomerManager customerManager;
    MainMenu mainMenu(interfaceManager, customerManager);

    // while the current interface is not EXIT, display the appropriate menu
    while (interfaceManager.getCurrentInterface() != EXIT) {
        switch (interfaceManager.getCurrentInterface()) {
            case MAIN_MENU:
                mainMenu.run();
                break;
            default:
                interfaceManager.setInterface(EXIT);
                break;
        }   
    }

    cout << "Exiting the system. Goodbye!\n";
    return 0;
}