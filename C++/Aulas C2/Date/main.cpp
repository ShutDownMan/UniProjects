#include <iostream>

#include "date.h"

using namespace std;

int main() {
    Date *date1, *date2;

    date1 = new Date(12, 9, 1995);
    date2 = new Date(28, 6, 2018);

    cout << *(date1->toString()) << ": " << date1->toInt() << endl;
    cout << *(date2->toString()) << ": " << date2->toInt() << endl;

    cout << date1->calcDist(date2)*365 << endl;

    return 0;
}

