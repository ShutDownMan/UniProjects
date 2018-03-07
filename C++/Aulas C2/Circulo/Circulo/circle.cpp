#include "circle.h"
#include "point2d.h"
#include <math.h>

#include <iostream>

using namespace std;

Circle::Circle() {
    this->center = new Point2D();
    this->radius = 0;
}

Circle::Circle(Point2D* c, double r) {
    this->center = c;
    this->radius = r;
}

Circle::Circle(double r) {
    this->center = new Point2D();
    this->radius = r;
}

Circle::~Circle() {
    cout << "(Circle) Freeing memory." << endl;
}

Point2D* Circle::getCenter() {
    return this->center;
}

double Circle::getRadius() {
    return this->radius;
}

void Circle::inflate(double d) {
    this->radius = d;
}

void Circle::mover() {
    this->center->mover();
}

void Circle::mover(double x, double y) {
    this->center->mover(x, y);
}

void Circle::mover(Point2D &p) {
    this->center->mover(p);
}

double Circle::getArea() {
    return M_PI/pow(this->getRadius(), 2);
}

void Circle::show() {
    cout << "Center: (" << this->getCenter()->getX() << "," << this->getCenter()->getY() << ")" << endl
         << "Radius: " << this->getRadius() << endl;
}
