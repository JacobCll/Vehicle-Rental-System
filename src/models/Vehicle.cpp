#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    int vehicleID;
    string vehicleBrand;
    string vehicleModel;
    string vehiclePlateNumber;
    double rentalPrice;
    bool vehicleAvailability;
    double rating;
    double mileage;
    string fuelType;

public:
    // ✅ Default constructor
    Vehicle()
        : vehicleID(0), vehicleBrand("Unknown"), vehicleModel("Unknown"),
          vehiclePlateNumber("N/A"), rentalPrice(0.0), vehicleAvailability(true),
          rating(0.0), mileage(0.0), fuelType("Unspecified") {}

    // ✅ Parameterized constructor
    Vehicle(int id, string brand, string model, string plate, double price,
            bool availability, double rate, double miles, string fuel)
        : vehicleID(id), vehicleBrand(brand), vehicleModel(model),
          vehiclePlateNumber(plate), rentalPrice(price),
          vehicleAvailability(availability), rating(rate),
          mileage(miles), fuelType(fuel) {}

    // ✅ Display vehicle information
    void displayInfo() {
        cout << "----------------------------------------\n";
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Brand: " << vehicleBrand << endl;
        cout << "Model: " << vehicleModel << endl;
        cout << "Plate Number: " << vehiclePlateNumber << endl;
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Mileage: " << mileage << " km" << endl;
        cout << "Rental Price: ₱" << rentalPrice << endl;
        cout << "Rating: " << rating << "/5" << endl;
        cout << "Availability: " << (vehicleAvailability ? "Available" : "Not Available") << endl;
        cout << "----------------------------------------\n";
    }

    // ✅ Getters
    int getVehicleID() { return vehicleID; }
    string getVehicleBrand() { return vehicleBrand; }
    string getVehicleModel() { return vehicleModel; }
    string getVehiclePlateNumber() { return vehiclePlateNumber; }
    double getRentalPrice() { return rentalPrice; }
    bool getVehicleAvailability() { return vehicleAvailability; }
    double getRating() { return rating; }
    double getMileage() { return mileage; }
    string getFuelType() { return fuelType; }

    // ✅ Setters
    void setVehiclePlateNumber(string plateNumber) { vehiclePlateNumber = plateNumber; }
    void setVehicleBrand(string brand) { vehicleBrand = brand; }
    void setVehicleModel(string model) { vehicleModel = model; }
    void setRentalPrice(double price) { rentalPrice = price; }
    void setVehicleAvailability(bool status) { vehicleAvailability = status; }
    void setRating(double r) { rating = r; }
    void setMileage(double m) { mileage = m; }
    void setFuelType(string fType) { fuelType = fType; }
};
