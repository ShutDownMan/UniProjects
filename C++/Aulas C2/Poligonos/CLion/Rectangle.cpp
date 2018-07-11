//
// Created by Jedson on 7/11/2018.
//

#include "Rectangle.h"

Rectangle::Rectangle(double base, double height) {
    this->base = base;
    this->height = height;
}

double Rectangle::getArea() {
    return this->base * this->height;
}

Rectangle::~Rectangle() = default;
