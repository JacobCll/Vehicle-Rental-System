#ifndef PROFILE_MENU_H
#define PROFILE_MENU_H

#include "CustomerManager.h"
#include "InterfaceManager.h"
#include "Utils.h"
#include <iostream>
#include <string>

using namespace std;

class ProfileMenu {
private:
    InterfaceManager& interfaceManager;
    CustomerManager& customerManager;
    
    void viewProfile();
    void editProfile();
    void changePassword();
    void deleteAccount();
    void handleInput(); 
public:
    ProfileMenu(InterfaceManager& im, CustomerManager& cm);

    void run(); 
};

#endif
