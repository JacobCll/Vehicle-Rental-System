#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
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
    vector<int> rentedVehicleIDs;
    double balance;

public:
    // Constructors
    Customer()
        : customerID(0), firstName(""), lastName(""), userName(""), password(""),
          licenseNumber(""), contactNumber(""), emailAddress(""), balance(0.0) {};
    Customer(int id, string fName, string lName, string uName, string pass, string license, string contact, string email, double bal = 0.0, vector<int> rentedList = {});

    // Getters
    int getCustomerID();
    string getFirstName();
    string getLastName();
    string getUserName();
    string getPassword();
    string getLicenseNumber();
    string getContactNumber();
    string getEmailAddress();
    double getBalance();
    vector<int> getRentedVehicles();

    // Setters
    void setCustomerID(int newCustomerID);
    void setFirstName(string newFirstName);
    void setLastName(string newLastName);
    void setUserName(string username);
    void setPassword(string newPassword);
    void setLicenseNumber(string license);
    void setContactNumber(string newNumber);
    void setEmailAddress(string email);
    void setBalance(double newBalance);
    void setRentedVehicles(vector<int> rentedList);

    // Rented vehicle management
    void addRentedVehicle(int vehicleID);
};

#endif // CUSTOMER_H
