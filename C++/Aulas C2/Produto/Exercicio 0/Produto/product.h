#ifndef PRODUTO_H
#define PRODUTO_H

#define MAXSTR 256

#include <iostream>
#include <string>

using namespace std;

class Product {
private:
    unsigned int code, quant;
    string *name;
    double price;

    double totalPrice();

public:
    Product();
    Product(unsigned int code);
    Product(unsigned int code, unsigned int quant, string *name, double price);

    unsigned int getCode() const;
    unsigned int getQuant() const;
    string *getName() const;
    double getPrice() const;

    void setName(string *value);
    void setQuant(unsigned int value);
    void updatePrice(double percentage);

    string *toString();

    ~Product();
};

#endif // PRODUTO_H
