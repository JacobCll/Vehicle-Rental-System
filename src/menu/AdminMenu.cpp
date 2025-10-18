#include "../../include/AdminMenu.h"

AdminMenu::AdminMenu(InterfaceManager& im, CustomerManager& cm) 
    : interfaceManager(im), customerManager(cm) {}

void AdminMenu::run() {
    clearScreen();
    if (customerManager.getCurrentUser() == nullptr) {
        cout << "No user is currently logged in.\n";
        pauseScreen();
        interfaceManager.setInterface(MAIN_MENU);
        return;
    }

    cout << "==============================\n";
    cout << "         ADMIN MENU\n";
    cout << "==============================\n";
    cout << "[1] Manage Users\n";
    cout << "[2] Manage Vehicles\n";
    cout << "[3] Logout\n";
    cout << "[4] Exit\n";
    cout << "Choose an option: ";

    handleInput();
}

void AdminMenu::handleInput() {
    string choice;
    cin >> choice;
    cin.ignore();

    if (choice == "1") {
        clearScreen();
        cout << "Managing users...\n";
        pauseScreen();
    } else if (choice == "2") {
        clearScreen();
        cout << "Managing vehicles...\n";
        pauseScreen();
    } else if (choice == "3") {
        if (customerManager.logout()) {
            cout << "Logged out successfully.\n";
        } else {
            cout << "No user is currently logged in.\n";
        }
        pauseScreen();
        interfaceManager.setInterface(MAIN_MENU);
    } else if (choice == "4") {
        interfaceManager.setInterface(EXIT);
    } else {
        cout << "Invalid option. Please try again.\n";
        pauseScreen();
    }
}

