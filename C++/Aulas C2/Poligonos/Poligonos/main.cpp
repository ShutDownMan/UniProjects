#include <iostream>
#include <math.h>

#include "circle.h"

using namespace std;

int main() {
    Circle *circle = new Circle(M_PI);

    cout << "Area of circle = " << circle->getArea() << endl;

    delete circle;

    return 0;
}
