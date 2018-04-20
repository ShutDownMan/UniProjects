#ifndef LINE_H
#define LINE_H

#include "ponto2d.h"

class Line {
private:
    double ca, cl;
    Point2D p1, p2;
public:
    Line();
    Line(double ca, double cl);
    Line(Point2D &p1, Point2D &p2);
    ~Line();
    void show();
    bool contains(Point2D &p);
    Point2D* intersect(Line &l);
};

#endif // LINE_H
