#include "CustomerManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// load customers on initialization
CustomerManager::CustomerManager() {
    loadCustomers();
}

// load customers from file
void CustomerManager::loadCustomers() {
    ifstream inFile(customerFile);
    if (!inFile) return;

    customers.clear();
    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;
        stringstream ss(line);

        Customer c;
        int id;
        string firstName, lastName, username, password, license, contact, email;
        double balance;
        string rentedStr;

        ss >> id >> firstName >> lastName >> username >> password
           >> license >> contact >> email >> balance;

        vector<string> rentedIDs;
        while (ss >> rentedStr)
            rentedIDs.push_back(rentedStr);

        // ✅ You should have a setter for ID instead of the pointer hack
        // Assuming you add: void setCustomerID(int id) { customerID = id; }
        c.setCustomerID(id);
        c.setFirstName(firstName);
        c.setLastName(lastName);
        c.setUserName(username);
        c.setPassword(password);
        c.setLicenseNumber(license);
        c.setContactNumber(contact);
        c.setEmailAddress(email);
        c.setBalance(balance);
        c.setRentedVehicles(rentedIDs);

        customers.push_back(c);
    }

    inFile.close();
}

// save customers to file
void CustomerManager::saveCustomers() {
    ofstream outFile(customerFile);
    for (Customer& c : customers) {
        outFile << c.getCustomerID() << " "
                << c.getFirstName() << " "
                << c.getLastName() << " "
                << c.getUserName() << " "
                << c.getPassword() << " "
                << c.getLicenseNumber() << " "
                << c.getContactNumber() << " "
                << c.getEmailAddress() << " "
                << c.getBalance();
        
        for (int& id : c.getRentedVehicles())
            outFile << " " << id;
        outFile << endl;
    }
    outFile.close();
}

int CustomerManager::generateNewCustomerID() {
    if (customers.empty()) return 1;
    return customers.back().getCustomerID() + 1;
}

bool CustomerManager::signup() {
    // creates a new customer object
    Customer newC;
    string firstName, lastName, username, password, license, contact, email;

    cout << "\n========== SIGN UP ==========\n";
    cout << "Enter Email Address: ";
    cin >> email;
    // Check for duplicate email
    for (const Customer& c : customers) {
        if (c.getEmailAddress() == email) {
            cout << "❌ Email already taken. Please try again.\n";
            return false;
        }
    }
    cout << "Choose Username: ";
    cin >> username;
    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Last Name: ";
    cin >> lastName;
    cout << "Enter License Number: ";
    cin >> license;
    cout << "Enter Contact Number: ";
    cin >> contact;
    cout << "Choose Password: ";
    cin >> password;

    // Assign collected info
    newC.setEmailAddress(email);
    newC.setUserName(username);
    newC.setFirstName(firstName);
    newC.setLastName(lastName);
    newC.setLicenseNumber(license);
    newC.setContactNumber(contact);
    newC.setPassword(password);

    // set default values
    newC.setBalance(0.0);
    newC.setCustomerID(generateNewCustomerID());

    // push new customer to customers vector
    customers.push_back(newC);
    // save latest customers
    saveCustomers();
    return true;
}


bool CustomerManager::login() {
    string email, password;

    cout << "\n===== LOGIN =====\n";
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;
    
    // iterate through customers and find a match
    for (Customer& c : customers) {
        if (c.getEmailAddress() == email && c.getPassword() == password) {
            cout << "Login successfull" << endl;
            currentCustomer = c;
            return true;
        } 
    }

    return false;
}
