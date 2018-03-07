#include "line.h"

#include <iostream>

using namespace std;

Line::Line() {
    this->ca = 0;
    this->cl = 0;
}

Line::Line(double ca, double cl) {
    this->ca = ca;
    this->cl = cl;
}

Line::Line(Point2D &a, Point2D &b) {
    this->ca =
            (b.getY()-a.getY())/
            (b.getX()-a.getX());
    this->cl = a.getY() -
            this->ca*a.getX();
}

Line::~Line() {
    cout << "(Line) Liberando memória." << endl;
}

void Line::show() {
    cout << "Coeficiente linear: " << this->ca
         << endl
         << "Coeficiente Angular: " << this->cl
         << endl;
}

bool Line::contains(Point2D &p) {
    return (p.getY() == this->ca * p.getX() + this->cl);
}

Point2D* Line::intersect(Line &l) {
    Point2D *p = NULL;

    if (this->ca != l.ca) {
       double x = (this->cl - l.cl) / (this->ca - l.ca);
       double y = this->cl + x * l.ca;

       p = new Point2D(x, y);
    }

    return p;
}
