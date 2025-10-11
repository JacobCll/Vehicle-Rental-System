#ifndef VEHICLE_H
#define VEHICLE_H

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
    // Constructor
    Vehicle(int id, string brand, string model, string plate, double price,
            bool available, double rating, double mileage, string fuelType);

    // Display info
    void displayInfo();

    // Getters
    int getVehicleID();
    double getRentalPrice();
    bool getVehicleAvailability();
    double getMileage();

    // Setters
    void setVehiclePlateNumber(string plateNumber);
    void setVehicleBrand(string brand);
    void setVehicleModel(string model);
    void setRentalPrice(double price);
    void setVehicleAvailability(bool status);
    void setRating(double rating);
    void setMileage(double mileage);
    void setFuelType(string fuelType);
};

#endif
