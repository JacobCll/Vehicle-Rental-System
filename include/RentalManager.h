#ifndef RENTAL_MANAGER_H
#define RENTAL_MANAGER_H

#include "VehicleManager.h"
#include "Rental.h"
#include "Vehicle.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class RentalManager {
private:
    const string rentalFile = "../data/rentals.txt"; // file to store rentals
    string rentalIDFile = "../data/rentalID.txt"; // file to store last rental ID
    vector<Rental> rentals;
    VehicleManager& vehicleManager; // Reference to VehicleManager for vehicle operations
    
    void loadRentals();
    void saveRentals();

public:
    RentalManager(VehicleManager& vm);

    void createRental(int customerID, int vehicleID, string startDate, string endDate);
    void endRental(int rentalID);
    void listAllRentals();
    void listRentalsByCustomer(int customerID);
    void getRentalByID(int rentalID);
};

#endif
