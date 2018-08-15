#include "product.h"

double Product::totalPrice() {
    return this->quant * this->price;
}

Product::Product() {

}

Product::Product(unsigned int code) {
    this->code = code;
}

Product::Product(unsigned int code, unsigned int quant, string *name, double price) {
    this->code = code;
    this->quant = quant;
    this->name = name;
    this->price = price;
}

unsigned int Product::getCode() const {
    return code;
}

unsigned int Product::getQuant() const {
    return quant;
}

string *Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

void Product::setQuant(unsigned int value) {
    quant = value;
}

void Product::setName(string *value) {
    name = value;
}

void Product::updatePrice(double percentage) {
    price += price*percentage;
}

string *Product::toString() {
    string *newStr;
    char str[MAXSTR] = {0};
    sprintf(str, "[%u]:\n\tname = %s\n\tprice = %lf\n\tquant = %u\n\tTotal = R$ %.2lf\n",
                              this->code,
                              this->getName()->c_str(),
                              this->price,
                              this->quant,
                              this->totalPrice()
            );
    newStr = new string(str);
    return newStr;
}

Product::~Product() {
    cout << "destruindo produto (" << *this->name << ")." << endl;
}
