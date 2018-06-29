#include "pessoa.h"

Person::Person(string *name, Date *birthdate, double height) {
    this->name = name;
    this->birthdate = birthdate;
    this->height = height;
}

string *Person::getName() {
    return this->name;
}

Date *Person::getBirthdate() {
    return this->birthdate;
}

double Person::getHeight() {
    return this->height;
}

void Person::setName(string *name) {
    this->name = name;
}

void Person::setBirthdate(Date *date) {
    this->birthdate = date;
}

void Person::setHeight(double height) {
    this->height = height;
}

void Person::show() {
    string *dateToString = this->birthdate->toString();

    cout << "My name is " << *this->name
         << " and I was born in " << *dateToString << ".\n"
         << "I'm also " << this->getHeight() << "m tall." << endl;

    delete dateToString;
}

int Person::getAge() {
    time_t t = time(0);
    tm *now = localtime(&t);
    Date *today = new Date(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    int res = (int)this->birthdate->calcDist(today);

    delete today;
    delete now;

    return res;
}

Person::~Person()
{

}
