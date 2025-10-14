#include "../../include/CustomerManager.h"
#include "../../include/Utils.h"

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

        vector<string> tokens;
        string token;
        stringstream ss(line);

        // Split by commas
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        
        // Ensure there are enough tokens
        if (tokens.size() < 9) continue;

        int id = stoi(tokens[0]);
        string firstName = tokens[1];
        string lastName = tokens[2];
        string username = tokens[3];
        string password = tokens[4];
        string license = tokens[5];
        string contact = tokens[6];
        string email = tokens[7];
        double balance = stod(tokens[8]);

        vector<int> rentedIDs;
        for (size_t i = 9; i < tokens.size(); ++i)
            rentedIDs.push_back(stoi(tokens[i]));

        customers.emplace_back(id, firstName, lastName, username, password, license, contact, email, balance, rentedIDs);
    }

    inFile.close();
}

// save customers to file
void CustomerManager::saveCustomers() {
    ofstream outFile(customerFile);
    for (Customer& c : customers) {
        outFile << c.getCustomerID() << ","
                << c.getFirstName() << ","
                << c.getLastName() << ","
                << c.getUserName() << ","
                << c.getPassword() << ","
                << c.getLicenseNumber() << ","
                << c.getContactNumber() << ","
                << c.getEmailAddress() << ","
                << c.getBalance();

        for (int& id : c.getRentedVehicles())
            outFile << "," << id;

        outFile << "\n";
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

//checks if username input is valid
bool isValidUsername(const string& username) {
    for (char c : username) {
        if (!(isalnum(c) || c == '_')) {
            return false;
        }
    }
    return true;
}

bool emailExists(vector<Customer>& customers, string& email) {
    for (Customer& c : customers) {
        if (c.getEmailAddress() == email) {
            return true;
        }
    }
    return false;
}

bool CustomerManager::signup() {
    string firstName, lastName, username, password, license, contact, email;

    clearScreen();
    cout << "========== SIGN UP ==========\n";
    // Check for duplicate email
    while (true) {
        cout << "Enter Email Address: "; 
        cin >> email;
        if (emailExists(customers, email)) {
            cout << "Email already in use. Please enter a different email.\n";
        } else {
            break;
        }
    }

    //fix signup issue --- spaces for username is not allowed --- first and last name spaces are allowed --- 
    cin.ignore(); // clear newline from input buffer
    while (true) {//checks if username input is valid
        cout << "Enter Username: "; 
        getline(cin, username);
        if (isValidUsername(username)) {
            break;
        } else {
            cout << "Invalid username. Letters, numbers, and underscores only with no spaces.\n";
        }
    }

    cout << "Enter First Name: "; getline(cin, firstName);
    cout << "Enter Last Name: "; getline(cin, lastName);
    cout << "Enter License Number: "; cin >> license;
    cout << "Enter Contact Number: "; cin >> contact;
    cout << "Choose Password: "; cin >> password;
    cin.ignore(); // clear newline from input buffer

    int newID = generateNewCustomerID();
    Customer newC(newID, firstName, lastName, username, password, license, contact, email); // creates a new customer object
    customers.push_back(newC); // push new customer to customers vector
    
    saveCustomers();
    
    return true;
}

bool CustomerManager::login() {
    string email, password;

    clearScreen();
    cout << "===== LOGIN =====\n";
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;
    cin.ignore();
    
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
