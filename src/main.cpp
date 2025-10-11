//test push inigo agunod HEHE #include "../include/CustomerManager.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    CustomerManager customerManager;

    while (true) {
        system("cls");
        cout << "==============================\n";
        cout << "   VEHICLE RENTAL SYSTEM\n";
        cout << "==============================\n";
        cout << "[1] Login\n";
        cout << "[2] Sign Up\n";
        cout << "[3] Exit\n";
        cout << "Choose an option: ";

        string choice;
        cin >> choice;
        
        if (choice == "1") {
            if (customerManager.login()) {
                cout << "✅ Login successful!\n";
                system("pause");
                break;
            } else {
                cout << "❌ Login failed. Please try again.\n";
                system("pause");
            }
        } else if (choice == "2") {
            if (customerManager.signup()) {
                cout << "✅ Sign up successful! You can now log in.\n";
            } else {
                cout << "❌ Sign up failed. Please try again.\n";
            }
            system("pause");
        } else if (choice == "3") {
            cout << "Exiting the system. Goodbye!\n";
            break;
        } else {
            cout << "Invalid option. Please try again.\n";
            system("pause");
        }

    }
}