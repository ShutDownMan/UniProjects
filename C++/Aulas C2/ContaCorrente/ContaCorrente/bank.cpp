#include "bank.h"

Bank::Bank() {
    this->accounts = new vector<Account*>();
}

Account *Bank::addAccount(bool special, double limit) {
    int id = this->accounts->size();
    Account *newAccount = new Account(id, special, limit);

    this->accounts->push_back(newAccount);

    return newAccount;
}

Account *Bank::findAccountById(int id) {
    int i;

    for(i = 0; i < (int)this->accounts->size(); ++i) {
        if(this->accounts->at(i)->getID() == id) {
            return this->accounts->at(i);
        }
    }

    return NULL;
}

void Bank::deleteAccount(int id) {
    Account *foundAccount = findAccountById(id);

    if(foundAccount) foundAccount->active = false;
}

bool Bank::withdraw(int id, double quant, TransactionType t) {
    Account *acc = findAccountById(id);

    char descStr[MAXSTR] = "withdraw of (%lf) from (%d);";
    string *desc = new string(sscanf(descStr, quant, id));

    if(acc && acc->active && acc->isSpecial() && t == Credit) {
        if(acc->getBalance() + acc->limit >= quant) {
            acc->setBalance(acc->getBalance() - quant);
            acc->addTransaction(desc, quant, t);

            return true;
        }
    }

    return false;
}

bool Bank::deposit(int id, double quant) {
    Account *acc = findAccountById(id);

    char descStr[MAXSTR] = "deposit of (%lf) to (%d);";
    string *desc = new string(sscanf(descStr, quant, id));

    if(acc) {
        acc->setBalance(acc->getBalance() + quant);
        acc->addTransaction(desc, quant, t);
        return true;
    }

    return false;
}

double Bank::extrato(int id) {
    Account *acc = findAccountById(id);

    if(acc) {
        return acc->getBalance();
    }

    return 0;
}

bool Bank::transfer(int idFrom, int idTo, double quant, TransactionType t) {
    Account *accFrom = findAccountById(idFrom);
    Account *accTo = findAccountById(idTo);

    char descStr[MAXSTR] = "transfer from (%d) to (%d) of (%lf);";
    string *desc = new string(sscanf(descStr, idFrom, idTo, quant));

    if(accFrom && accFrom->active && accTo && accTo->active) {
        accFrom->setBalance(acc->getBalance() - quant);
        accFrom->addTransaction(desc, quant, t);

        accTo->setBalance(acc->getBalance() + quant);
        accTo->addTransaction(desc, quant, t);
    }

    return false;
}

void Bank::showAccounts() {
    int i, j;
    Account *acc;
    Transaction *tran;

    for(i = 0; i < (int)this->accounts->size(); ++i) {
        acc = this->accounts->at(i);

        cout << "(" << acc->getID() << ") - " << acc->getBalance() << ";" << endl;
        cout << "\tTransactions:" << endl;
        for(j = 0; j < acc->getTransactions()->size(); ++j) {
            tran = acc->getTransactions()->at(j);

            cout << *tran->getDescription() << endl;
        }

    }
}

