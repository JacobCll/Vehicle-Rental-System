#ifndef VEHICLE_MANAGER_H
#define VEHICLE_MANAGER_H

#include "Vehicle.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class VehicleManager {
private:
    const string vehicleFile = "../data/vehicles.txt";
    string vehicleIDFile = "../data/vehicleID.txt";
    vector<Vehicle> vehicles;

    void loadVehicles();
    void saveVehicles();

public:
    VehicleManager(); // load vehicles from file

    // Vehicle operations
    void addVehicle(Vehicle& v);
    void removeVehicle(int vehicleID);
    void updateVehicle(Vehicle& v);
    Vehicle* getVehicleByID(int vehicleID);
    vector<Vehicle> getAllVehicles();

    void listAllVehicles();

    //Filtering and searching
    vector<Vehicle> filterByAvailability(bool available);
    vector<Vehicle> filterByBrand(const string& brand);
    vector<Vehicle> filterByModel(const string& model);
    vector<Vehicle> filterByFuelType(const string& fuel);
    vector<Vehicle> filterByCarType(const string& type);
    vector<Vehicle> filterByRating(double minRating);
    vector<Vehicle> sortByPrice(bool ascending);
    vector<Vehicle> sortByMileage(bool ascending);
};

#endif
