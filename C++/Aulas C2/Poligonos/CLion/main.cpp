#include <iostream>
#include <cmath>

#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include "complexpolygon.h"

using namespace std;

int main() {
    Circle *circle = new Circle(5);
    Triangle *triangle = new Triangle(10, 25);
    Rectangle *rectangle = new Rectangle(15, 5);
    ComplexPolygon *complexPolygon = new ComplexPolygon(3, circle, triangle, rectangle);


    cout << "Area of circle = " << circle->getArea() << endl;
    cout << "Area of triangle = " << triangle->getArea() << endl;
    cout << "Area of rectangle = " << rectangle->getArea() << endl;
    cout << "Area of complex polygon = " << complexPolygon->getArea() << endl;

    delete circle;
    delete triangle;
    delete rectangle;
    delete complexPolygon;

    return 0;
}
