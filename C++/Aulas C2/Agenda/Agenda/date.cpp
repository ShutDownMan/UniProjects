#include "date.h"

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

int Date::getDay() {
    return this->day + 1;
}

int Date::getMonth() {
    return this->month + 1;
}

int Date::getYear() {
    return this->year + 1;
}

int Date::getMonDay(int month) {
    if(month == 2) {
        if(this->isLeap()) {
            return this->monDays[month-1] + 1;
        } else {
            return this->monDays[month-1];
        }
    }

    return this->monDays[month];
}

string *Date::toString() {
    string *str = new string();

    *str = to_string(this->day) + "/" + to_string(this->month) + "/" + to_string(this->year);

    return str;
}

int Date::toInt() {
    int sum = this->year * 365;

    sum += (this->year/4 - this->year/100 + this->year/400);

    for(int i = 0; i < this->month-1; ++i) {
        sum += this->getMonDay(i+1);
    }

    sum += this->day;

    return sum;
}

int Date::isLeap() {
    return ((this->year%400==0 || this->year%100!=0) && (this->year%4==0));
}

double Date::calcDist(Date *&date) {
    int dateANum = this->toInt();
    int dateBNum = date->toInt();

    return (max(dateANum, dateBNum) - min(dateANum, dateBNum)) / 365.0;
}

Date::~Date() {
    cout << "liberando data (" << *this->toString() << ")" << endl;
}

