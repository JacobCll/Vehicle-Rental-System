#ifndef VEHICLE_MENU_H
#define VEHICLE_MENU_H
#include "InterfaceManager.h"
#include "VehicleManager.h"
#include "Vehicle.h"
#include <iostream>
#include <limits>
using namespace std;

class VehicleMenu {
    private:
        VehicleManager vehicleManager;
        InterfaceManager& interfaceManager;

    public:
        VehicleMenu(InterfaceManager& im) : interfaceManager(im) {}
        void run();                             //vehicle menu(main)
        void showVehicleList(bool available);   //list of available/unavailable vehicles
        void showVehicleDetails(Vehicle& v);       //show specific vehicle details
};

#endif // VEHICLE_MENU_H