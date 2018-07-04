#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <vector>

#include "transaction.h"

using namespace std;

class Account {
private:
    int ID;
    bool active;
    double balance;
    bool special;
    double limit;
    vector<Transaction*> *transactions;

public:
    Account(int id);
    Account(int id, double limit);

    int getID() const;
    double getBalance() const;
    void setBalance(double value);
    bool isSpecial() const;
    double getLimit() const;
    bool isActive() const;
    void setActive(bool value);
    bool getSpecial() const;

    void addTransaction(string *desc, double quant, TransactionType t);
    void addTransaction(string *desc, double quant);

    vector<Transaction *> *getTransactions() const;

    ~Account();
};

#endif // ACCOUNT_H
