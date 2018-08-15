#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>
#include <ctime>

#include "date.h"
#include "pessoa.h"

using namespace std;

class Person {
private:
    string *name;
    Date *birthdate;
    double height;
public:
    Person(string *name, Date *birthdate, double height);

    string *getName();
    Date *getBirthdate();
    double getHeight();

    void setName(string *name);
    void setBirthdate(Date *date);
    void setHeight(double height);

    void show();

    int getAge();

    ~Person();
};

#endif // PESSOA_H
