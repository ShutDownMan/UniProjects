#include "chemical.h"

Chemical::Chemical() : Product() {
    this->flamable = false;
}

Chemical::Chemical(unsigned int code) : Product(code) {
    this->flamable = false;
}

Chemical::Chemical(unsigned int code, unsigned int quant, string *name, double price) : Product(code, quant, name, price) {
    this->flamable = false;
}

bool Chemical::getFlamable() const {
    return flamable;
}

void Chemical::setFlamable(bool value) {
    flamable = value;
}

string *Chemical::toString() {
    string *newStr;
    char str[MAXSTR] = {0};
    sprintf(str, "[%u]:\n\tname = %s\n\tflamable = %s\n\tprice = %lf\n\tquant = %u\n",
                              this->getCode(),
                              this->getName()->c_str(),
                              (this->flamable) ? "yes" : "no",
                              this->getPrice(),
                              this->getQuant()
            );
    newStr = new string(str);
    return newStr;
}
