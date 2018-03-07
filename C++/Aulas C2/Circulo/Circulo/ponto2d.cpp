#include "point2d.h"

#include <math.h>
#include <iostream>

using namespace std;

Point2D::Point2D() {
    this->x = 0;
    this->y = 0;
}

Point2D::Point2D(double x, double y) {
    this->x = x;
    this->y = y;
}

Point2D::Point2D(Point2D &other) {
    this->x = other.x;
    this->y = other.y;
}

Point2D::~Point2D() {
    cout << "(Ponto2D) Freeing memory." << endl;
}

double Point2D::getX() {
    return this->x;
}

double Point2D::getY() {
    return this->y;
}

void Point2D::setX(double d) {
    this->x = d;
}

void Point2D::setY(double d) {
    this->y = d;
}

void Point2D::mover() {
    this->setX(0);
    this->setY(0);
}

void Point2D::mover(double x, double y) {
    this->setX(x);
    this->setY(y);
}

void Point2D::mover(Point2D &other) {
    this->setX(other.getX());
    this->setY(other.getY());
}

bool Point2D::equals(Point2D &other) {
    return (this->getX() == other.getY() && this->getY() == other.getY());
}

double Point2D::distance(Point2D &other) {
    return sqrt(pow(other.getX() - this->getX(), 2) + pow(other.getY() - this->getY(), 2));
}

Point2D* Point2D::clone() {
    return new Point2D(*this);
}

void Point2D::show() {
    cout << "(" << this->getX() << ", " << this->getY() << ")" << endl;
}
