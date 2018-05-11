#include "ponto2d.h"
#include "line.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    Point2D* p1 = NULL;
    Point2D* p2 = new Point2D(2, 7);
    Point2D* p3 = new Point2D(-1, -5);

    Line* l1 = new Line(*p2, *p3);
    Line* l2 = new Line(2, 1);

    p1 = (l1->intersect(*l2))->clone();

    printf("cl = %lf\n", l1->cl);

    if(p1 != NULL) {
        cout << "l1 intersects l2" << endl;
        p1->show();
    } else {
        cout << "l1 does not intersect l2" << endl;
    }

    return 0;
}
