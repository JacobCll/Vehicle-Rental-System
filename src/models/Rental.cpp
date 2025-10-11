#include "../../include/Rental.h"

Rental::Rental(int id, int cus, int veh, string startD, string endD, double dailyRate) {
    rentalID = id;
    customerID = cus;
    vehicleID = veh;
    startDate = startD;
    endDate = endD;
    numberOfDays = daysBetween();
    totalCost = numberOfDays * dailyRate;
}

// Convert string date to tm struct
// calculate days between two dates
tm Rental::stringToTm(const string& dateStr) {
    tm tm = {};
    int year, month, day;
    if (sscanf(dateStr.c_str(), "%d-%d-%d", &year, &month, &day) == 3) {
        tm.tm_year = year - 1900; // tm_year is years since 1900
        tm.tm_mon = month - 1;    // tm_mon is 0-based
        tm.tm_mday = day;
        tm.tm_hour = 0;            
        tm.tm_min = 0;
        tm.tm_sec = 0;
    }
    return tm;
}
int Rental::daysBetween() {
    tm tmStart = stringToTm(startDate);
    tm tmEnd = stringToTm(endDate);
    time_t timeStart = mktime(&tmStart);
    time_t timeEnd = mktime(&tmEnd);
    const int secondsPerDay = 60 * 60 * 24;
    return static_cast<int>(difftime(timeEnd, timeStart) / secondsPerDay) + 1;
}
 
// Getters
int Rental::getRentalID() { return rentalID; }
int Rental::getCustomerID() { return customerID; }
int Rental::getVehicleID() { return vehicleID; }
string Rental::getStartDate() { return startDate; }
string Rental::getEndDate() { return endDate; }
double Rental::getTotalCost() { return totalCost; }

// Setters
void Rental::setRentalID(int id) { rentalID = id; }
void Rental::setCustomerID(int id) { customerID = id; }
void Rental::setVehicleID(int id) { vehicleID = id; }
void Rental::setStartDate(string& start) { startDate = start; }
void Rental::setEndDate(string& end) { endDate = end; }