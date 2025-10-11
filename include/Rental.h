#ifndef RENTAL_H
#define RENTAL_H

#include <string>
using namespace std;

class Rental {
private:
    int rentalID;
    int customerID;
    int vehicleID;
    string startDate;
    string endDate;
    double totalCost;
    bool isActive;

public:
    // Constructor
    Rental(int rID, int cID, int vID, string startDate);

    // Methods
    void displayInfo();
    double calculateTotal(double rate, int days);
    void endRental(string endDate, double rate, int days);

    // Getters
    int getRentalID();
    int getVehicleID();
    int getCustomerID();
    double getTotalCost();
    bool getIsActive();

    // Setters
    void setIsActive(bool active);
    void setStartDate(string s);
    void setEndDate(string e);
};

#endif
