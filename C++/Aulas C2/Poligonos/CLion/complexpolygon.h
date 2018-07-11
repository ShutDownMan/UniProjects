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
    explicit ComplexPolygon(int argc, ...);

    double getArea() override;

    ~ComplexPolygon();
};

#endif // COMPLEXPOLYGON_H
