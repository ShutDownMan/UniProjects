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
    double dailyLimit;
    double dailyWithdraw;
    vector<Transaction*> *transactions;

public:
    Account(int id, double dailyLimit);
    Account(int id, double dailyLimit, double limit);

    int getID() const;
    double getBalance() const;
    bool isSpecial() const;
    double getLimit() const;
    bool isActive() const;
    bool getSpecial() const;

    void setDailyLimit(double value);
    double getDailyWithdraw() const;
    double getDailyLimit() const;

    void setBalance(double value);
    void setActive(bool value);
    void setDailyWithdraw(double value);

    void addTransaction(string *desc, double quant, TransactionType t);
    void addTransaction(string *desc, double quant);

    vector<Transaction *> *getTransactions() const;

    ~Account();
};

#endif // ACCOUNT_H
