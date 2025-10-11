#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Customer {
private:
    int customerID;
    string firstName;
    string lastName;
    string userName;
    string password;
    string licenseNumber;
    string contactNumber;
    string emailAddress;
    vector<string> rentedVehicleIDs; 
    double balance;

public:
    // ✅ Display basic info
    void displayInfo() {
        cout << "----------------------------------------\n";
        cout << "Customer ID: " << customerID << endl;
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Username: " << userName << endl;
        cout << "Email: " << emailAddress << endl;
        cout << "Contact: " << contactNumber << endl;
        cout << "License: " << licenseNumber << endl;
        cout << "Balance: ₱" << balance << endl;
        cout << "Rented Vehicles: ";
        if (rentedVehicleIDs.empty()) cout << "None";
        else {
            for (const auto& id : rentedVehicleIDs)
                cout << id << " ";
        }
        cout << "\n----------------------------------------\n";
    }

    // ✅ Getters
    int getCustomerID() { return customerID; }
    string getFirstName() { return firstName; }
    string getLastName() { return lastName; }
    string getUserName() { return userName; }
    string getPassword() { return password; }
    string getLicenseNumber() { return licenseNumber; }
    string getContactNumber() { return contactNumber; }
    string getEmailAddress() { return emailAddress; }
    double getBalance() { return balance; }
    vector<string> getRentedVehicles() { return rentedVehicleIDs; }

    // ✅ Setters
    void setFirstName(string newFirstName) { firstName = newFirstName; }
    void setLastName(string newLastName) { lastName = newLastName; }
    void setUserName(string username) { userName = username; }
    void setPassword(string newPassword) { password = newPassword; }
    void setLicenseNumber(string license) { licenseNumber = license; }
    void setContactNumber(string newNumber) { contactNumber = newNumber; }
    void setEmailAddress(string email) { emailAddress = email; }
    void setBalance(double newBalance) { balance = newBalance; }
    void setRentedVehicles(vector<string> rentedList) { rentedVehicleIDs = rentedList; }

    // ✅ Rented vehicle management
    void addRentedVehicle(string vehicleID) {
        rentedVehicleIDs.push_back(vehicleID);
    }

    void removeRentedVehicle(string vehicleID) {
        auto it = find(rentedVehicleIDs.begin(), rentedVehicleIDs.end(), vehicleID);
        if (it != rentedVehicleIDs.end())
            rentedVehicleIDs.erase(it);
    }
};
