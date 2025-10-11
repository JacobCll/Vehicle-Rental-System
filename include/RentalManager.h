#ifndef RENTAL_MANAGER_H
#define RENTAL_MANAGER_H

#include <vector>
#include <string>
#include "Rental.h"
#include "Vehicle.h"
using namespace std;

class RentalManager {
private:
    vector<Rental> rentals;
    int nextRentalID = 1;

public:
    void createRental(int customerID, int vehicleID, string startDate, double rate, int days, vector<Vehicle>& vehicles);
    void endRental(int rentalID, string endDate, vector<Vehicle>& vehicles);
    void listAllRentals();
    void listRentalsByCustomer(int customerID);
};

#endif
