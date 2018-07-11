#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>

#include "polygon.h"

class Circle : public Polygon {
private:
    double radius;
public:
    explicit Circle(double radius);

    double getArea() override;

    ~Circle();
};

#endif // CIRCLE_H
