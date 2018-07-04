#include "bank.h"

Bank::Bank() {
    this->accounts = new vector<Account*>();
}

Account *Bank::addAccount() {
    int id = this->accounts->size();
    Account *newAccount = new Account(id);

    this->accounts->push_back(newAccount);

    return newAccount;
}

Account *Bank::addAccount(double limit) {
    int id = this->accounts->size();
    Account *newAccount = new Account(id, limit);

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

    if(foundAccount) foundAccount->setActive(false);
}

bool Bank::withdraw(int id, double quant, TransactionType t) {
    Account *acc = findAccountById(id);

    char descStr[MAXSTR];
    sprintf(descStr, "withdraw of (%lf) from (%d);", quant, id);
    string *desc = new string(descStr);

    if(quant >= 0 && acc && acc->isActive() && acc->isSpecial() && t == Credit) {
        if(acc->getBalance() + acc->getLimit() >= quant) {
            acc->setBalance(acc->getBalance() - quant);
            acc->addTransaction(desc, quant, t);

            return true;
        }
    }

    return false;
}

bool Bank::deposit(int id, double quant) {
    Account *acc = findAccountById(id);

    char descStr[MAXSTR];
    sprintf(descStr, "deposit of (%lf) to (%d);", quant, id);
    string *desc = new string(descStr);

    if(quant >= 0 && acc) {
        acc->setBalance(acc->getBalance() + quant);
        acc->addTransaction(desc, quant);
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

    char descStr[MAXSTR];
    sprintf(descStr, "transfer from (%d) to (%d) of (%lf);", idFrom, idTo, quant);
    string *desc = new string(descStr);

    if(accFrom && accFrom->isActive() && accTo && accTo->isActive()) {
        accFrom->setBalance(accFrom->getBalance() - quant);
        accFrom->addTransaction(desc, quant, t);

        accTo->setBalance(accTo->getBalance() + quant);
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
        for(j = 0; j < (int)acc->getTransactions()->size(); ++j) {
            tran = acc->getTransactions()->at(j);

            cout << "\t\t" << *tran->getDescription() << endl;
        }
    }
}

