#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "account.h"

#define MAXSTR 256

using namespace std;

class Bank {
private:
    vector<Account *> *accounts;

public:
    Bank();

    Account *addAccount(double limit, double dailyLimit);
    Account *addAccount(double limit);

    Account *findAccountById(int id);

    void deleteAccount(int id);

    bool withdraw(int id, double quant);

    bool deposit(int id, double quant);

    void showTransactions(int id);

    void showBalance(int id);

    bool transfer(int idFrom, int idTo, double quant);

    void showAccounts();

    ~Bank();
};

#endif // BANK_H
