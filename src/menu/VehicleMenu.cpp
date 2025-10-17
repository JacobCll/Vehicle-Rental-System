#include "../../include/VehicleMenu.h"
#include "../../include/VehicleManager.h"
#include "../../include/Utils.h"
void VehicleMenu::run() {
    int choice;
    while (true) {
        clearScreen();
        cout << "===== VEHICLE MENU =====\n";
        cout << "[1] View All Vehicles\n";
        cout << "[2] Back to Main Menu\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                int subChoice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                clearScreen();
                cout << "=== Vehicles ===\n";
                cout << "[1] Available Vehicles\n";
                cout << "[2] Unavailable Vehicles\n";
                cout << "[3] Back\n";
                cout << "Choose an option: ";
                cin >> subChoice;

                if (subChoice == 1) {
                    showVehicleList(true);
                }else if (subChoice == 2) {
                    showVehicleList(false);
                } else {
                    break;
                }
                break;
            }
            case 2:
                return; // back to main menu
            default:
                cout << "Invalid option. Try again.\n";
                break;
            
        }
    }
}
void VehicleMenu::showVehicleList(bool available) {
    clearScreen();
    vector<Vehicle> allVehicles = vehicleManager.getAllVehicles();
    vector<Vehicle> filtered;

    for(auto& v : allVehicles) {
        if (v.getVehicleAvailability() == available) {
            filtered.push_back(v);
        }
    }

    if (filtered.empty()) {
        cout << "No " << (available ? "available" : "Not Available") << " vehicles.\n";
        cout << "Press Enter to return...";
        cin.ignore();
        cin.get();
        return;
    }

    cout << "=== " << (available ? "Available" : "Unavailable") << " Vehicles ===\n";
    for (size_t i = 0; i < filtered.size(); ++i) {
        cout << "[" << (i + 1) << "] " << filtered[i].getVehicleBrand() << " " << filtered[i].getVehicleModel() << " - " 
             << (filtered[i].getVehicleAvailability() ? "Available" : "Not Available") << "\n";
    }
    cout << "[" << (filtered.size() + 1) << "] Back\n";

    int choice;
    cout << "Choose a vehicle: ";
    cin >> choice;

    if (choice >= 1 && choice <= (int)filtered.size()) {
        showVehicleDetails(filtered[choice - 1]);
    }
}                                                 

void VehicleMenu::showVehicleDetails(Vehicle& v) {
    clearScreen();
    v.displayInfo();

    if (v.getVehicleAvailability()) {
        cout << "\n[1] Rent this vehicle\n";
    } else {
        cout << "\nThis vehicle is not available for rent.\n";
    }

    cout << "[2] Back\n";
    cout << "Choose an option: ";

    int option;
    cin >> option;

    if (option == 1 && v.getVehicleAvailability()) {
        cout << "\n(-> Rent function will go here later)\n";
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }
}
    
