#include "circle.h"

Circle::Circle(double radius) : Polygon() {
    this->radius = radius;
}

double Circle::getArea() {
    return M_PI * this->radius * this->radius;
}

Circle::~Circle() = default;
