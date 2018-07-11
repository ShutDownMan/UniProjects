#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>

#include <math.h>
#include "polygon.h"

using namespace std;

class Circle : public Polygon {
private:
    double radius;
public:
    Circle(double radius);

    double getArea();

    ~Circle();
};

#endif // CIRCLE_H
