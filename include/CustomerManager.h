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
    string adminsFile = "../data/admins.txt";
    vector<Customer> customers;
    Customer* currentCustomer = nullptr;
    bool isAdmin = false;

    void loadCustomers();
    int generateNewCustomerID();
    void saveLastLoggedIn();
    int loadLastLoggedIn();
    
 
public:
    // constructor to load customers from file and check if admin
    CustomerManager(); 

    vector<Customer>& getAllCustomers() { return customers; }
    Customer* getCurrentUser() {return currentCustomer; }
    Customer* getCustomerByID(int customerID);
    void saveCustomers();

    bool checkIsAdmin();
    bool signup();
    bool login();
    bool logout();
};

#endif
