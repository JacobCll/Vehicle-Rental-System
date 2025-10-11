#include "../../include/Vehicle.h"


// Parameterized constructor
Vehicle::Vehicle(int id, string brand, string model, string plate, double rate, bool available, double r, double m, string fuel) {
    vehicleID = id;
    vehicleBrand = brand;
    vehicleModel = model;
    vehiclePlateNumber = plate;
    dailyRate = rate;
    vehicleAvailability = available;
    rating = r;
    mileage = m;
    fuelType = fuel;
}

// Display vehicle information
void Vehicle::displayInfo() {
    cout << "----------------------------------------\n";
    cout << "Vehicle ID: " << vehicleID << endl;
    cout << "Brand: " << vehicleBrand << endl;
    cout << "Model: " << vehicleModel << endl;
    cout << "Plate Number: " << vehiclePlateNumber << endl;
    cout << "Fuel Type: " << fuelType << endl;
    cout << "Mileage: " << mileage << " km" << endl;
    cout << "Daily Rate: ₱" << dailyRate << endl;
    cout << "Rating: " << rating << "/5" << endl;
    cout << "Availability: " << (vehicleAvailability ? "Available" : "Not Available") << endl;
    cout << "----------------------------------------\n";
}

// Getters
int Vehicle::getVehicleID() { return vehicleID; }
string Vehicle::getVehiclePlateNumber() { return vehiclePlateNumber; }
string Vehicle::getVehicleBrand() { return vehicleBrand; }
string Vehicle::getVehicleModel() { return vehicleModel; }
string Vehicle::getFuelType() { return fuelType; }
double Vehicle::getDailyRate() { return dailyRate; }
bool Vehicle::getVehicleAvailability() { return vehicleAvailability; }
double Vehicle::getMileage() { return mileage; }
double Vehicle::getRating() { return rating; }

// Setters
void Vehicle::setVehiclePlateNumber(string plateNumber) { vehiclePlateNumber = plateNumber; }
void Vehicle::setVehicleBrand(string brand) { vehicleBrand = brand; }
void Vehicle::setVehicleModel(string model) { vehicleModel = model; }
void Vehicle::setDailyRate(double dRate) { dailyRate = dRate; }
void Vehicle::setVehicleAvailability(bool status) { vehicleAvailability = status; }
void Vehicle::setRating(double r) { rating = r; }
void Vehicle::setMileage(double m) { mileage = m; }
void Vehicle::setFuelType(string fType) { fuelType = fType; }
