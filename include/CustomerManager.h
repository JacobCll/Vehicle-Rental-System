#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H

#include "Customer.h"
#include <vector>
#include <string>
using namespace std;

class CustomerManager {
private:
    string customerFile = "customers.txt";
    vector<Customer> customers;
    Customer currentCustomer;

    void loadCustomers();
    void saveCustomers();
    int generateNewCustomerID();

public:
    CustomerManager();

    vector<Customer>& getAllCustomers() { return customers; }

    Customer* getCurrentUser() {return &currentCustomer; }

    bool signup();
    bool login();
};

#endif
