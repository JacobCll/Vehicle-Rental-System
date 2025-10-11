#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer {
private:
    string username;
    string password;
    double balance;

public:
    Customer(string u = "", string p = "", double b = 0.0)
        : username(u), password(p), balance(b) {}

    string getUsername() const { return username; }
    string getPassword() const { return password; }
    double getBalance() const { return balance; }

    void setPassword(string p) { password = p; }
    void setBalance(double b) { balance = b; }

    void displayProfile() const;
};

#endif
