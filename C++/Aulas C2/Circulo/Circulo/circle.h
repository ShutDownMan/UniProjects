#ifndef CIRCLE_H
#define CIRCLE_H

#include "point2d.h"

#include <iostream>

using namespace std;


class Circle {
private:
    Point2D* center;
    double radius;
public:
    Circle();
    Circle(Point2D* c, double r);
    Circle(double r);
    ~Circle();

    Point2D* getCenter();
    double getRadius();
    void show();

    void inflate(double d);
    void mover();
    void mover(double x, double y);
    void mover(Point2D &p);
    double getArea();
};

#endif // CIRCLE_H
