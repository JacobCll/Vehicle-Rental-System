#include "../../include/RentalManager.h"

RentalManager::RentalManager(VehicleManager& vm): vehicleManager(vm) {
    loadRentals();
}

// Load rentals from file
void RentalManager::loadRentals() {
    ifstream inFile(rentalFile);
    if (!inFile) return;

    rentals.clear();
    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        
        int rentalID, customerID, vehicleID;
        string startDate, endDate;
        double totalCost;

        // Example file format: rentalID customerID vehicleID startDate endDate totalCost isActive
        ss >> rentalID >> customerID >> vehicleID >> startDate >> endDate >> totalCost;

        // get vehicle by ID to fetch daily rate
        Vehicle* v = vehicleManager.getVehicleByID(vehicleID);
        double dailyRate = v->getDailyRate();
        
        Rental r(rentalID, customerID, vehicleID, startDate, endDate, dailyRate);
        
        rentals.push_back(r);
    }

    inFile.close();
}

// Save rentals to file
void RentalManager::saveRentals() {
    ofstream outFile(rentalFile);
    if (!outFile) return;

    for (Rental& r : rentals) {
        outFile << r.getRentalID() << " "
                << r.getCustomerID() << " "
                << r.getVehicleID() << " "
                << r.getStartDate() << " "
                << r.getEndDate() << " "
                << r.getTotalCost() << " ";
    }

    outFile.close();
}


