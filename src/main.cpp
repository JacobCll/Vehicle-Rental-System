#include "../include/InterfaceManager.h"
#include "../include/CustomerManager.h"
#include "../include/MainMenu.h"
#include "../include/ProfileMenu.h"
#include "../include/Utils.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    InterfaceManager interfaceManager;
    CustomerManager customerManager;
    // create menu instances
    MainMenu mainMenu(interfaceManager, customerManager);
    ProfileMenu profileMenu(interfaceManager, customerManager);

    // while the current interface is not EXIT, display the appropriate menu
    while (interfaceManager.getCurrentInterface() != EXIT) {
        switch (interfaceManager.getCurrentInterface()) {
            case MAIN_MENU: {
                mainMenu.run();
                break;
            }
            case PROFILE_MENU: {
                profileMenu.run();
                break;
            }
            default:
                interfaceManager.setInterface(EXIT);
                break;
        }   
    }

    cout << "Exiting the system. Goodbye!\n";
    return 0;
}