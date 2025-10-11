#include <iostream>
#include <vector>
#include "Rental.h"
using namespace std;

class RentalManager {
private:
    vector<Rental> rentals;
    int nextRentalID = 1; // auto increment ID

public:
    // Create a new rental
    void createRental(int customerID, int vehicleID, string startDate) {
        Rental newRental(nextRentalID++, customerID, vehicleID, startDate);
        rentals.push_back(newRental);
        cout << "✅ Rental created successfully!" << endl;
    }

    // End a rental by rentalID
    void endRental(int rentalID, string endDate, double rate, int days) {
        for (auto &r : rentals) {
            if (r.getRentalID() == rentalID && r.getIsActive()) {
                r.endRental(endDate, rate, days);
                cout << "✅ Rental " << rentalID << " ended successfully!" << endl;
                return;
            }
        }
        cout << "❌ Rental not found or already ended!" << endl;
    }

    // List all rentals
    void listAllRentals() {
        if (rentals.empty()) {
            cout << "No rentals found." << endl;
            return;
        }
        for (auto &r : rentals)
            r.displayInfo();
    }

    // List only active rentals
    void listActiveRentals() {
        bool found = false;
        for (auto &r : rentals) {
            if (r.getIsActive()) {
                r.displayInfo();
                found = true;
            }
        }
        if (!found)
            cout << "No active rentals." << endl;
    }

    // List ended rentals
    void listEndedRentals() {
        bool found = false;
        for (auto &r : rentals) {
            if (!r.getIsActive()) {
                r.displayInfo();
                found = true;
            }
        }
        if (!found)
            cout << "No ended rentals." << endl;
    }
};
