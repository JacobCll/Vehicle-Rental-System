#include "../../include/CustomerManager.h"

// load customers on initialization
CustomerManager::CustomerManager() {
    loadCustomers();
    // load last logged-in customer ID
    int lastID = loadLastLoggedIn();
    if (lastID != 0) {
        currentCustomer = getCustomerByID(lastID); // set last logged in user as current
    } else {
        currentCustomer = nullptr;
    }
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
// save the current logged-in customer's ID to file
void CustomerManager::saveLastLoggedIn() {
    ofstream outFile(lastLoggedInFile);
    if(outFile.is_open()) {
        outFile << currentCustomer->getCustomerID();
        outFile.close();
    }
}
// load the last logged-in customer ID from file
int CustomerManager::loadLastLoggedIn() {
    ifstream inFile(lastLoggedInFile);
    int lastID = 0;
    if(inFile.is_open()) {
        inFile >> lastID;
        inFile.close();
    }
    return lastID;
}

bool CustomerManager::signup() {
    string firstName, lastName, username, password, license, contact, email;

    system("cls");
    cout << "========== SIGN UP ==========\n";
    cout << "Enter Email Address: ";
    cin >> email;
    // Check for duplicate email
    for (Customer& c : customers) {
        if (c.getEmailAddress() == email) {
            cout << "Email already taken. Please try again.\n";
            return false;
        }
    }
    cout << "Enter Username: "; cin >> username;
    cout << "Enter First Name: "; cin >> firstName;
    cout << "Enter Last Name: "; cin >> lastName;
    cout << "Enter License Number: "; cin >> license;
    cout << "Enter Contact Number: "; cin >> contact;
    cout << "Choose Password: "; cin >> password;

    int newID = generateNewCustomerID();
    Customer newC(newID, firstName, lastName, username, password, license, contact, email); // creates a new customer object
    customers.push_back(newC); // push new customer to customers vector
    
    saveCustomers();
    return true;
}
bool CustomerManager::login() {
    string email, password;

    system("cls");
    cout << "===== LOGIN =====\n";
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;
    
    // iterate through customers and find a match
    for (Customer& c : customers) {
        if (c.getEmailAddress() == email && c.getPassword() == password) {
            currentCustomer = &c;
            saveLastLoggedIn();
            return true;
        } 
    }

    return false;
}
bool CustomerManager::logout() {
    currentCustomer = nullptr;
    ofstream outFile(lastLoggedInFile);
    if(outFile.is_open()) {
        outFile << 0; // reset last logged-in ID
        outFile.close();
    }
    return true;
}


Customer* CustomerManager::getCustomerByID(int customerID) {
    auto it = find_if(customers.begin(), customers.end(), [customerID](Customer& c) { return c.getCustomerID() == customerID; });
    if (it != customers.end()) {
        return &(*it);
    }
    return nullptr;
}
