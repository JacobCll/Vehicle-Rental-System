#include <iostream>
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
    // ✅ Default constructor
    Rental()
        : rentalID(0), customerID(0), vehicleID(0),
          startDate("N/A"), endDate("N/A"),
          totalCost(0.0), isActive(false) {}

    // ✅ Parameterized constructor
    Rental(int rID, int cID, int vID, string start, string end,
           double cost, bool active)
        : rentalID(rID), customerID(cID), vehicleID(vID),
          startDate(start), endDate(end),
          totalCost(cost), isActive(active) {}

    // ✅ Display info
    void displayInfo() {
        cout << "----------------------------------------\n";
        cout << "Rental ID: " << rentalID << endl;
        cout << "Customer ID: " << customerID << endl;
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Start Date: " << startDate << endl;
        cout << "End Date: " << endDate << endl;
        cout << "Total Cost: ₱" << totalCost << endl;
        cout << "Status: " << (isActive ? "Active" : "Ended") << endl;
        cout << "----------------------------------------\n";
    }

    // ✅ Calculation
    double calculateTotal(double rate, int days) {
        totalCost = rate * days;
        return totalCost;
    }

    // ✅ Getters
    int getRentalID() { return rentalID; }
    int getCustomerID() { return customerID; }
    int getVehicleID() { return vehicleID; }
    double getTotalCost() { return totalCost; }

    // ✅ Setters
    void setIsActive(bool active) { isActive = active; }
    void setStartDate(string start) { startDate = start; }
    void setEndDate(string end) { endDate = end; }

    // ✅ End rental
    void endRental(string end) {
        endDate = end;
        isActive = false;
    }
};
