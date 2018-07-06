#include "bank.h"

Bank::Bank() {
    this->accounts = new vector<Account*>();
}

Account *Bank::addAccount(double dailyLimit) {
    int id = this->accounts->size();
    Account *newAccount = new Account(id, dailyLimit);

    this->accounts->push_back(newAccount);

    return newAccount;
}

Account *Bank::addAccount(double limit, double dailyLimit) {
    int id = this->accounts->size();
    Account *newAccount = new Account(id, dailyLimit, limit);

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

bool Bank::withdraw(int id, double quant) {
    Account *acc = findAccountById(id);

    char descStr[MAXSTR];
    sprintf(descStr, "withdraw of R$ %.2lf from [%04d];", quant, id);
    string *desc = new string(descStr);

    if(quant >= 0 && acc && acc->isActive()) {
        if(acc->getDailyWithdraw() < acc->getDailyLimit()) {
            if(acc->getBalance() >= quant) {
                acc->setBalance(acc->getBalance() - quant);
                acc->addTransaction(desc, quant, Debit);
                acc->setDailyWithdraw(acc->getDailyWithdraw() + quant);

                return true;
            } else if(acc->isSpecial() && acc->getBalance() + acc->getLimit() >= quant){
                acc->setBalance(acc->getBalance() - quant);
                acc->addTransaction(desc, quant, Credit);
                acc->setDailyWithdraw(acc->getDailyWithdraw() + quant);

                return true;
            }
        }
    }

    return false;
}

bool Bank::deposit(int id, double quant) {
    Account *acc = findAccountById(id);

    char descStr[MAXSTR];
    sprintf(descStr, "deposit of R$ %.2lf to [%04d];", quant, id);
    string *desc = new string(descStr);

    if(quant >= 0 && acc) {
        acc->setBalance(acc->getBalance() + quant);
        acc->addTransaction(desc, quant);
        return true;
    }

    return false;
}

void Bank::showTransactions(int id) {
    Account *acc = findAccountById(id);
    Transaction *tran;
    int i;

    if(acc) {
        cout << "Transactions of " << "[" << acc->getID() << "]" << ":" << endl;
        for(i = 0; i < (int)acc->getTransactions()->size(); ++i) {
            tran = acc->getTransactions()->at(i);
            cout << "\t" << *tran->getDescription() << endl;
        }
    }
}

void Bank::showBalance(int id) {
    Account *acc = findAccountById(id);

    if(acc) {
        cout << "Balance of [" << acc->getID() << "] = " << acc->getBalance() << ";" << endl;
    }
}

bool Bank::transfer(int idFrom, int idTo, double quant) {
    Account *accFrom = findAccountById(idFrom);
    Account *accTo = findAccountById(idTo);

    char descStr[MAXSTR];
    sprintf(descStr, "transfer from [%04d] to [%04d] of R$ %.2lf;", idFrom, idTo, quant);
    string *desc = new string(descStr);

    if(accFrom && accFrom->isActive() && accTo && accTo->isActive()) {

        if(accFrom->getBalance() >= quant) {
            accFrom->setBalance(accFrom->getBalance() - quant);
            accFrom->addTransaction(desc, quant, Credit);

            accTo->setBalance(accTo->getBalance() + quant);
            accTo->addTransaction(desc, quant);

            return true;
        } else if(accFrom->isSpecial() && accFrom->getBalance() + accFrom->getLimit() >= quant){
            accFrom->setBalance(accFrom->getBalance() - quant);
            accFrom->addTransaction(desc, quant, Debit);

            accTo->setBalance(accTo->getBalance() + quant);
            accTo->addTransaction(desc, quant);

            return true;
        }
    }

    return false;
}

void Bank::showAccounts() {
    int i, j;
    Account *acc;
    Transaction *tran;

    for(i = 0; i < (int)this->accounts->size(); ++i) {
        acc = this->accounts->at(i);

        cout << "[" << acc->getID() << "] - " << acc->getBalance() << ";" << endl;
        cout << "\tTransactions:" << endl;
        for(j = 0; j < (int)acc->getTransactions()->size(); ++j) {
            tran = acc->getTransactions()->at(j);

            cout << "\t\t" << *tran->getDescription() << endl;
        }
    }
}

