#include "matrix.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int nl = 3, nc = 3;
    Matrix* m1 = new Matrix(nl, nc);
    Matrix* m2 = new Matrix(nl, nc);

    for(int row = 0; row < nl; row++) {
        for(int col = 0; col < nc; col++) {
            m1->setElem(col, row, row*nc + col);
            m2->setElem(col, row, (row + 1)*nc + (col + row));
        }
    }

//    printf("m1[%d][%d] = %d\n", 1, 1, (*m1)[1][1] = 5);
//    cout << "-------------" << endl;

    m1->show();
    cout << "-------------" << endl;
    m2->show();
    cout << "-------------" << endl;

//    ((*m1) * (*m2))->show();
//    cout << "-------------" << endl;

    (m2->triangulate())->show();
    cout << "-------------" << endl;

//    delete m1;
//    delete m2;

    return 0;
}
