#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

using namespace std;

class Vehicle {
private:
    int vehicleID;
    string vehicleBrand;
    string vehicleModel;
    string vehiclePlateNumber;
    double dailyRate;
    bool vehicleAvailability;
    double rating;
    double mileage;
    string fuelType;
    string carType; // new field for car type (e.g., SUV, Sedan, etc.)

public:
    // Constructor
    Vehicle();
    Vehicle(int id, string brand, string model, string plate, double rate,
            bool available, double rating, double mileage, string fuelType, string carType);

    // Display info
    void displayInfo();

    // Getters
    int getVehicleID();
    string getVehiclePlateNumber();
    string getVehicleBrand();
    string getVehicleModel();
    string getFuelType();
    string getCarType(); // new getter for car type
    double getDailyRate();
    bool getVehicleAvailability(); // check if it is rented or not
    double getMileage();
    double getRating();

    // Setters
    void setVehiclePlateNumber(string plateNumber);
    void setVehicleBrand(string brand);
    void setVehicleModel(string model);
    void setDailyRate(double dRate);
    void setVehicleAvailability(bool status);
    void setRating(double rating);
    void setMileage(double mileage);
    void setFuelType(string fuelType);
    void setCarType(string type); // new setter for car type
    
    
};

#endif
