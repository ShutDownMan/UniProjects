//
// Created by Jedson on 7/11/2018.
//

#include "Triangle.h"

Triangle::Triangle(double base, double height) : Polygon() {
    this->base = base;
    this->height = height;
}

double Triangle::getArea() {
    return (this->base * this->height)/2;
}

Triangle::~Triangle() = default;
