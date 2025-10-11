#include "../../include/CustomerManager.h"

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

        int id;
        string firstName, lastName, username, password, license, contact, email;
        double balance;
        string rentedStr;

        ss >> id >> firstName >> lastName >> username >> password
           >> license >> contact >> email >> balance;

        vector<int> rentedIDs;
        while (ss >> rentedStr)
            rentedIDs.push_back(stoi(rentedStr));
        
        Customer c(id, firstName, lastName, username, password, license, contact, email, balance, rentedIDs);
        
        // add to customers vector
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

// generate a new unique customer ID
int CustomerManager::generateNewCustomerID() {
    ifstream inFile(customerIDFile);
    int lastID = 0;

    if (inFile.is_open()) { // file exists
        inFile >> lastID; // read last ID
        inFile.close(); // close file
    }

    int newID = lastID + 1; // increment ID

    // Save the new ID back to the file
    ofstream outFile(customerIDFile);
    if (outFile.is_open()) {
        outFile << newID;
        outFile.close();
    }

    return newID;
}


bool CustomerManager::signup() {
    string firstName, lastName, username, password, license, contact, email;

    cout << "\n========== SIGN UP ==========\n";
    cout << "Enter Email Address: ";
    cin >> email;
    // Check for duplicate email
    for (Customer& c : customers) {
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

    
    int newID = generateNewCustomerID();
    
    // creates a new customer object
    Customer newC(newID, firstName, lastName, username, password, license, contact, email);

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
            cout << "Login successful" << endl;
            currentCustomer = c;
            return true;
        } 
    }

    return false;
}
