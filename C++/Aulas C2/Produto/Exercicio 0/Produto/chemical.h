#ifndef CHEMICAL_H
#define CHEMICAL_H

#define MAXSTR 256

#include <iostream>
#include <string>
#include "product.h"

using namespace std;

class Chemical : public Product {
private:
    bool flamable;
public:
    Chemical();
    Chemical(unsigned int code);
    Chemical(unsigned int code, unsigned int quant, string *name, double price);

    bool getFlamable() const;
    void setFlamable(bool value);

    string *toString();

    ~Chemical();
};

#endif // CHEMICAL_H
