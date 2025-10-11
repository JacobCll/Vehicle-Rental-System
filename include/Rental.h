#ifndef RENTAL_H
#define RENTAL_H

#include <string>
#include <iostream>
#include <ctime>

using namespace std;

class Rental {
private:
    int rentalID;
    int customerID;
    int vehicleID;
    string startDate; // YYYY-MM-DD
    string endDate;   // YYYY-MM-DD
    double totalCost;
    int numberOfDays;

    // Helper functions
    tm stringToTm(const string& dateStr);
    int daysBetween();

public:
    // Constructors
    Rental();
    Rental(int rentalID, int customerID, int vehicleID, string startD, string endD, double dailyRate);

    // Getters
    int getRentalID();
    int getCustomerID();
    int getVehicleID();
    string getStartDate();
    string getEndDate();
    double getTotalCost();

    // Setters
    void setRentalID(int id);
    void setCustomerID(int id);
    void setVehicleID(int id);
    void setStartDate(string& s);
    void setEndDate(string& e);
};

#endif
