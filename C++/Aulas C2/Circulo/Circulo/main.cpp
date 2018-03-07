#include <circle.h>
#include <point2d.h>

#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    Point2D* p1 = new Point2D(1, 1);
    Circle* c1 = new Circle(1);

    c1->show();

    cout << "Circle area: " << c1->getArea() << endl;

    delete p1;
    delete c1;

    return 0;
}
