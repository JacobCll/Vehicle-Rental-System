#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H

#include "Customer.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class CustomerManager {
private:
    const string customerFile = "../data/customers.txt";
    string customerIDFile = "../data/customerID.txt";
    string lastLoggedInFile = "../data/lastLoggedIn.txt";
    vector<Customer> customers;
    Customer* currentCustomer = nullptr;

    void loadCustomers();
    void saveCustomers();
    int generateNewCustomerID();
    void saveLastLoggedIn();
    int loadLastLoggedIn();
 
public:
    // constructor to load customers from file
    CustomerManager(); 

    vector<Customer>& getAllCustomers() { return customers; }
    Customer* getCurrentUser() {return currentCustomer; }
    Customer* getCustomerByID(int customerID);

    bool signup();
    bool login();
    bool logout();
};

#endif
