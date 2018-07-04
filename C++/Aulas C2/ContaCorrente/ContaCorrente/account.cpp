#include "account.h"

Account::Account(int id) {
    this->ID = id;
    this->active = true;
    this->transactions = new vector<Transaction*>();
    this->balance = 0;
}

Account::Account(int id, double limit) {
    this->ID = id;
    this->special = true;
    this->limit = limit;

    this->active = true;
    this->transactions = new vector<Transaction*>();
    this->balance = 0;
}

int Account::getID() const {
    return ID;
}

double Account::getBalance() const {
    return balance;
}

void Account::setBalance(double value) {
    balance = value;
}

bool Account::isSpecial() const {
    return special;
}

double Account::getLimit() const {
    return limit;
}

bool Account::isActive() const {
    return active;
}

void Account::setActive(bool value) {
    active = value;
}

bool Account::getSpecial() const {
    return special;
}

void Account::addTransaction(string *desc, double quant, TransactionType t) {
    Transaction *newT = new Transaction(desc, quant, t);
    this->transactions->push_back(newT);
}

void Account::addTransaction(string *desc, double quant) {
    Transaction *newT = new Transaction(desc, quant);
    this->transactions->push_back(newT);
}

vector<Transaction *> *Account::getTransactions() const {
    return transactions;
}

Account::~Account() {
    cout << "Destruindo conta (" << this->ID << ");" << endl;
}
