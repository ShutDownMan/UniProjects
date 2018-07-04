#include "transaction.h"


Transaction::Transaction(string *description, double quantity, TransactionType transactionType) {
    this->description = description;
    this->quantity = quantity;
    this->transactionType = transactionType;
}

string *Transaction::getDescription() const {
    return description;
}

double Transaction::getQuantity() const {
    return quantity;
}

TransactionType Transaction::getTransactionType() const {
    return transactionType;
}
