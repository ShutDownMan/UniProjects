#include <cstdarg>
#include "complexpolygon.h"

ComplexPolygon::ComplexPolygon(int argc, ...) {
    this->polygons = new vector<Polygon*>();

    va_list argv;
    va_start(argv, argc);

    for(int i = 0; i < argc; i++) {
        this->polygons->push_back(va_arg(argv, Polygon*));
    }

    va_end(argv);
}

double ComplexPolygon::getArea() {
    double sum = 0;

    for(Polygon* polygon : *this->polygons) {
        sum += polygon->getArea();
    }

    return sum;
}

ComplexPolygon::~ComplexPolygon() = default;

