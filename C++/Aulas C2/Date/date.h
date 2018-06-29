#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Date {
private:
    int day, month, year;
    int monDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    Date(int day, int month, int year);

    int getDay();
    int getMonth();
    int getYear();

    int getMonDay(int year, int month);

    string *toString();

    int toInt();

    int isLeap(int year);

    double calcDist(Date *&date);

    ~Date();
};

#endif // DATE_H
