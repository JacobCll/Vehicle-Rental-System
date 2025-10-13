#include "../../include/MainMenu.h"
#include "../../include/Utils.h"

MainMenu::MainMenu(InterfaceManager& im, CustomerManager& cm) : interfaceManager(im), customerManager(cm) {};

void MainMenu::run() {
    clearScreen();
    cout << "==============================\n";
    cout << "   VEHICLE RENTAL SYSTEM\n";
    cout << "==============================\n";
    if (customerManager.getCurrentUser() == nullptr) {
        cout << "[1] Login\n";
        cout << "[2] Sign Up\n";
        cout << "[3] Exit\n";
    } else {
        cout << "Welcome, " << customerManager.getCurrentUser()->getFirstName() << "!\n";
        cout << "[1] Browse Vehicles\n";
        cout << "[2] View Profile\n";
        cout << "[3] Logout\n";
        cout << "[4] Exit\n";
    }
    cout << "Choose an option: ";

    handleInput();
}

bool MainMenu::handleInput() {
    string choice;
    cin >> choice;
    cin.ignore();
    
    if (customerManager.getCurrentUser() == nullptr) {
        handleLoggedOutInput(choice);
    } else {
        handleLoggedInInput(choice);
    }

    return true;
}

void MainMenu::handleLoggedOutInput(string& choice) {
    if (choice == "1") {
        if (customerManager.login()) {
            cout << "Login successful!\n";
            cout << "Welcome, " << customerManager.getCurrentUser()->getFirstName() << "!\n";
        } else {
            cout << "Login failed. Please try again.\n";
        }
        pauseScreen();
    } else if (choice == "2") {
        if (customerManager.signup()) {
            cout << "Sign up successful!\n";
        } else {
            cout << "Sign up failed. Please try again.\n";
        }
        pauseScreen();
    } else if (choice == "3") {
        interfaceManager.setInterface(EXIT);
    } else {
        cout << "Invalid option. Please try again.\n";
        pauseScreen();
    }
}

void MainMenu::handleLoggedInInput(string& choice) {
    if (choice == "1") {
        cout << "Browsing vehicles...\n";
        pauseScreen();
    } else if (choice == "2") {
        cout << "Viewing profile...\n";
        pauseScreen();
    } else if (choice == "3") {
        if (customerManager.logout()) {
            cout << "Logged out successfully.\n";
        } else {
            cout << "Logout failed. Please try again.\n";
        }
        pauseScreen();
    } else if (choice == "4") {
        interfaceManager.setInterface(EXIT);
    } else {
        cout << "Invalid option. Please try again.\n";
        pauseScreen();
    }
}
