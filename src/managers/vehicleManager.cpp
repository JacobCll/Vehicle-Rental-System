#include "../../include/VehicleManager.h"

VehicleManager::VehicleManager() {
    loadVehicles();
}

// Load vehicles from file
void VehicleManager::loadVehicles() {
    ifstream inFile(vehicleFile);
    if (!inFile) return;

    vehicles.clear();
    string line;
    
    // iterate through each line of the file
    while (getline(inFile, line)) {
        if (line.empty()) continue;
        stringstream ss(line);

        int id;
        string brand, model, plate, fuel;
        double rate, r, m;
        bool available;

        ss >> id >> brand >> model >> plate >> rate >> available >> r >> m >> fuel;

        // create vehicle object
        Vehicle v(id, brand, model, plate, rate, available, r, m, fuel);

        vehicles.push_back(v);
    }

    inFile.close();
}

// Save vehicles to file
void VehicleManager::saveVehicles() {
    ofstream outFile(vehicleFile);
    if (!outFile) return;

    for (Vehicle& v : vehicles) {
        outFile << v.getVehicleID() << " "
                << v.getVehicleBrand() << " "
                << v.getVehicleModel() << " "
                << v.getVehiclePlateNumber() << " "
                << v.getDailyRate() << " "
                << v.getVehicleAvailability() << " "
                << v.getRating() << " "
                << v.getMileage() << " "
                << v.getFuelType() << "\n";
    }

    outFile.close();
}

// Add a new vehicle
void VehicleManager::addVehicle(Vehicle& v) {
    vehicles.push_back(v);
    saveVehicles();
}

Vehicle* VehicleManager::getVehicleByID(int vehicleID) {
    for (Vehicle& v : vehicles) {
        if (v.getVehicleID() == vehicleID)
            return &v;
    }
    return nullptr;
}
