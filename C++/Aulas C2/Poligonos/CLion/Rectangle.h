//
// Created by Jedson on 7/11/2018.
//

#ifndef CLION_RECTANGLE_H
#define CLION_RECTANGLE_H

#include "polygon.h"

class Rectangle : Polygon {
private:
    double base;
    double height;
public:
    Rectangle(double base, double height);

    double getArea() override;

    ~Rectangle();
};


#endif //CLION_RECTANGLE_H
