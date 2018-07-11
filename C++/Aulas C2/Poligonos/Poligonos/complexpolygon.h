#ifndef COMPLEXPOLYGON_H
#define COMPLEXPOLYGON_H

#include <iostream>

#include <vector>
#include "polygon.h"

using namespace std;

class ComplexPolygon : public Polygon {
private:
    vector<Polygon*> *polygons;
public:
    ComplexPolygon();

    double getArea();
};

#endif // COMPLEXPOLYGON_H
