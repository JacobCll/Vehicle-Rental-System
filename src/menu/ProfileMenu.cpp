#include "../../include/ProfileMenu.h"

ProfileMenu::ProfileMenu(InterfaceManager& im, CustomerManager& cm)
    : interfaceManager(im), customerManager(cm) {}

void ProfileMenu::run() {
    if (customerManager.getCurrentUser() == nullptr) {
        cout << "No user is currently logged in.\n";
        pauseScreen();
        interfaceManager.setInterface(MAIN_MENU);
        return;
    }

    clearScreen();
    cout << "==============================\n";
    cout << "        PROFILE MENU\n";
    cout << "==============================\n";
    cout << "[1] View Profile\n";
    cout << "[2] Edit Profile\n";
    cout << "[3] Change Password\n";
    cout << "[4] Delete Account\n";
    cout << "[5] Back to Main Menu\n";
    cout << "Choose an option: ";

    handleInput();
}

void ProfileMenu::handleInput() {
    string choice;
    cin >> choice;
    cin.ignore();

    if (choice == "1") {
        viewProfile();
    } else if (choice == "2") {
    } else if (choice == "3") {
    } else if (choice == "4") {
    } else if (choice == "5") {
        interfaceManager.setInterface(MAIN_MENU);
    } else {
        cout << "Invalid option. Please try again.\n";
        pauseScreen();
    }
}

void ProfileMenu::viewProfile() {
    clearScreen();
    Customer* user = customerManager.getCurrentUser();
    cout << "===== PROFILE DETAILS =====\n";
    cout << "Customer ID: " << user->getCustomerID() << "\n";
    cout << "First Name: " << user->getFirstName() << "\n";
    cout << "Last Name: " << user->getLastName() << "\n";
    cout << "Username: " << user->getUserName() << "\n";
    cout << "Email: " << user->getEmailAddress() << "\n";
    cout << "Phone: " << user->getContactNumber() << "\n";
    cout << "License Number: " << user->getLicenseNumber() << "\n";
    cout << "Balance: ₱" << user->getBalance() << "\n";
    vector<int> rentedVehicles = user->getRentedVehicles();
    cout << "Rented Vehicles IDs: ";
    if (rentedVehicles.empty()) {
        cout << "None";
    } else {
        for (int id : rentedVehicles) {
            cout << id << " ";
        }
    }
    cout << "\n";
    cout << "===========================\n";
    pauseScreen();
}
