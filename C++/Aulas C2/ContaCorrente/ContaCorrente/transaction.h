#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>

using namespace std;

enum TransactionType {
    NONE,
    Debit,
    Credit
};

class Transaction {
    string *description;
    double quantity;
    TransactionType transactionType;

public:
    Transaction(string *description, double quantity);
    Transaction(string *description, double quantity, TransactionType transactionType);

    string *getDescription() const;
    double getQuantity() const;
    TransactionType getTransactionType() const;

    ~Transaction();
};

#endif // TRANSACTION_H
