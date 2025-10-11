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
    const string vehicleFile = "vehicles.txt";
    string vehicleIDFile = "vehicleID.txt";
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
};

#endif
