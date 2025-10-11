#include "../../include/Customer.h"

Customer::Customer(int id, string fName, string lName, string uName, string pass, string license, string contact, string email, double bal, vector<int> rentedList) {
    customerID = id;
    firstName = fName;
    lastName = lName;
    userName = uName;
    password = pass;
    licenseNumber = license;
    contactNumber = contact;
    emailAddress = email;
    balance = bal;
    rentedVehicleIDs = rentedList;
}

// Getters
int Customer::getCustomerID() { return customerID; }
string Customer::getFirstName() { return firstName; }
string Customer::getLastName() { return lastName; }
string Customer::getUserName() { return userName; }
string Customer::getPassword() { return password; }
string Customer::getLicenseNumber() { return licenseNumber; }
string Customer::getContactNumber() { return contactNumber; }
string Customer::getEmailAddress() { return emailAddress; }
double Customer::getBalance() { return balance; }
vector<int> Customer::getRentedVehicles() { return rentedVehicleIDs; }

// Setters
void Customer::setCustomerID(int newCustomerID) { customerID = newCustomerID; }
void Customer::setFirstName(string newFirstName) { firstName = newFirstName; }
void Customer::setLastName(string newLastName) { lastName = newLastName; }
void Customer::setUserName(string username) { userName = username; }
void Customer::setPassword(string newPassword) { password = newPassword; }
void Customer::setLicenseNumber(string license) { licenseNumber = license; }
void Customer::setContactNumber(string newNumber) { contactNumber = newNumber; }
void Customer::setEmailAddress(string email) { emailAddress = email; }
void Customer::setBalance(double newBalance) { balance = newBalance; }
void Customer::setRentedVehicles(vector<int> rentedList) { rentedVehicleIDs = rentedList; }

// Rented vehicle management
void Customer::addRentedVehicle(int vehicleID) {
    rentedVehicleIDs.push_back(vehicleID);
}

