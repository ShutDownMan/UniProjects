#include <iostream>

#include "bank.h"
#include "account.h"
#include "transaction.h"

using namespace std;

int main() {
    Bank *bank = new Bank();

    bank->addAccount(1000);
    bank->addAccount();
    bank->addAccount();
    bank->addAccount();

    bank->deleteAccount(1);

    bank->deposit(0, 500);
    bank->deposit(2, 250);
    bank->deposit(3, 25);

    bank->withdraw(0, 250, Debit);
    bank->transfer(0, 2, 100, Debit);

    bank->showAccounts();

    return 0;
}

