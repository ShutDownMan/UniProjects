#include "complexpolygon.h"

ComplexPolygon::ComplexPolygon() : Polygon() {

}

double ComplexPolygon::getArea() {
    double sum = 0;

    for(int i = 0; i < (int)this->polygons->size(); ++i) {
        sum += this->polygons->at(i)->getArea();
    }

    return sum;
}

