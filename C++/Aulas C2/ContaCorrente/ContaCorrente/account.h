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
    Account();
    Account(int id, bool special, double limit);

    int getID() const;
    double getBalance() const;
    void setBalance(double value);
    bool isSpecial() const;
    double getLimit() const;

    void addTransaction(string *desc, double quant, TransactionType t);

    vector<Transaction *> *getTransactions() const;

    ~Account();
};

#endif // ACCOUNT_H
