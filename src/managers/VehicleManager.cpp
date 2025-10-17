#include "../../include/VehicleManager.h"
#include <vector>
#include <algorithm>

using namespace std;

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
        string brand, model, plate, fuel, type;
        double rate, r, m;
        bool available;

        ss >> id >> brand >> model >> plate >> rate >> available >> r >> m >> fuel >> type;

        // create vehicle object
        Vehicle v(id, brand, model, plate, rate, available, r, m, fuel, type);

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
                << v.getFuelType() << " "
                << v.getCarType() << "\n";
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

//Filter by availability
vector<Vehicle> VehicleManager::filterByAvailability(bool available) {
    vector<Vehicle> result;
    for (auto& v : vehicles) {
        if (v.getVehicleAvailability() == available) {
            result.push_back(v);
        }
    }
    return result;
}

//Filter by brand
vector<Vehicle> VehicleManager::filterByBrand(const string& brand) {
    vector<Vehicle> result;
    for (auto& v : vehicles) {
        if (v.getVehicleBrand() == brand) {
            result.push_back(v);
        }
    }
    return result;
}

//Filter by model
vector<Vehicle> VehicleManager::filterByModel(const string& model) {
    vector<Vehicle> result;
    for (auto& v : vehicles) {
        if (v.getVehicleModel() == model) {
            result.push_back(v);
        }
    }
    return result;
}

//Filter by fuel type
vector<Vehicle> VehicleManager::filterByFuelType(const string& fuel) {
    vector<Vehicle> result;
    for (auto& v : vehicles) {
        if (v.getFuelType() == fuel) {
            result.push_back(v);
        }
    }
    return result;
}

//Filter by car type(two-wheeler, four-wheeler)
vector<Vehicle> VehicleManager::filterByCarType(const string& type) {
    vector<Vehicle> result;
    for (auto& v : vehicles) {
        if (v.getCarType() == type) {
            result.push_back(v);
        }
    }
    return result;
}

//Filter by minimum rating
vector<Vehicle> VehicleManager::filterByRating(double minRating) {
    vector<Vehicle> result;
    for (auto& v : vehicles) {
        if (v.getRating() >= minRating) {
            result.push_back(v);
        }
    }
    return result;
}

//sort by price (low -> high | high -> low)
vector<Vehicle> VehicleManager::sortByPrice(bool ascending) {
    vector<Vehicle> result = vehicles;
    sort(result.begin(), result.end(), [ascending](Vehicle& a, Vehicle& b) {
        return ascending ? a.getDailyRate() < b.getDailyRate() : a.getDailyRate() > b.getDailyRate();
    });
    return result;
}

//Sort by mileage (low -> high | high -> low)
vector<Vehicle> VehicleManager::sortByMileage(bool ascending) {
    vector<Vehicle> result = vehicles;
    sort(result.begin(), result.end(), [ascending](Vehicle& a, Vehicle& b) {
        return ascending ? a.getMileage() < b.getMileage() : a.getMileage() > b.getMileage();
    });
    return result;
}

vector<Vehicle> VehicleManager::getAllVehicles() {
    return vehicles;
}
