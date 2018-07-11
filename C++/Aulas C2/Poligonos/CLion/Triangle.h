//
// Created by Jedson on 7/11/2018.
//

#ifndef CLION_TRIANGLE_H
#define CLION_TRIANGLE_H

#include "polygon.h"

class Triangle : Polygon {
private:
    double base;
    double height;
public:
    Triangle(double base, double height);

    double getArea() override;

    ~Triangle();
};


#endif //CLION_TRIANGLE_H
