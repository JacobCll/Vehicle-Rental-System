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
    cout << "[3] Back to Main Menu\n";
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
        editProfile();
    } else if (choice == "3") {
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
    cout << "Balance: " << fixed << setprecision(2) << user->getBalance() << "\n";
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

void ProfileMenu::editProfile() {
    while (true) {
        clearScreen();
        Customer* user = customerManager.getCurrentUser();

        cout << "===== EDIT PROFILE =====\n";
        cout << "[1] First Name: " << user->getFirstName() << "\n";
        cout << "[2] Last Name: " << user->getLastName() << "\n";
        cout << "[3] Username: " << user->getUserName() << "\n";
        cout << "[4] Email: " << user->getEmailAddress() << "\n";
        cout << "[5] Phone: " << user->getContactNumber() << "\n";
        cout << "[6] License Number: " << user->getLicenseNumber() << "\n";
        cout << "[7] Delete Account\n";
        cout << "[8] Back to Profile Menu\n";
        cout << "Choose a field to edit: ";

        string choice;
        getline(cin, choice);

        if (choice == "1") {
            string newFirstName;
            cout << "Enter new first name: ";
            getline(cin, newFirstName);
            user->setFirstName(newFirstName);
            cout << "First name updated successfully.\n";
        } else if (choice == "2") {
            string newLastName;
            cout << "Enter new last name: ";
            getline(cin, newLastName);
            user->setLastName(newLastName);
            cout << "Last name updated successfully.\n";
        } else if (choice == "3") {
            string newUsername;
            cout << "Enter new username: ";
            getline(cin, newUsername);
            user->setUserName(newUsername);
            cout << "Username updated successfully.\n";
        } else if (choice == "4") {
            string newEmail;
            cout << "Enter new email address: ";
            getline(cin, newEmail);
            user->setEmailAddress(newEmail);
            cout << "Email address updated successfully.\n";
        } else if (choice == "5") {
            string newPhone;
            cout << "Enter new contact number: ";
            getline(cin, newPhone);
            user->setContactNumber(newPhone);
            cout << "Contact number updated successfully.\n";
        } else if (choice == "6") {
            string newLicense;
            cout << "Enter new license number: ";
            getline(cin, newLicense);
            user->setLicenseNumber(newLicense);
            cout << "License number updated successfully.\n";
        } else if (choice == "7") {
            cout << "Are you sure you want to delete your account? This action cannot be undone. (y/n): ";
            string confirm;
            getline(cin, confirm);
            if (confirm == "y" || confirm == "Y") {
                int userID = user->getCustomerID();
                auto& customers = customerManager.getAllCustomers();
                customers.erase(remove_if(customers.begin(), customers.end(),
                    [userID](Customer& c) { return c.getCustomerID() == userID; }), customers.end());
                cout << "Account deleted successfully. Returning to main menu.\n";
                pauseScreen();
                customerManager.logout();
                customerManager.saveCustomers();
                interfaceManager.setInterface(MAIN_MENU);
                return;
            } else {
                cout << "Account deletion canceled.\n";
            }
        }
        else if (choice == "8") {
            break;
        } else {
            cout << "Invalid option. Please try again.\n";
        }
        customerManager.saveCustomers(); // save changes to file
        pauseScreen();
    }
}