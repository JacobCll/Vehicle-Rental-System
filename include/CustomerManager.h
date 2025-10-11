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
    vector<Customer> customers;
    Customer currentCustomer;

    // helper functions
    void loadCustomers();
    // save customers to file
    void saveCustomers();
    // generate next customer ID from file
    int generateNewCustomerID();

public:
    // constructor to load customers from file
    CustomerManager(); 

    vector<Customer>& getAllCustomers() { return customers; }
    Customer* getCurrentUser() {return &currentCustomer; }
    Customer* getCustomerByID(int customerID);

    bool signup();
    bool login();
};

#endif
