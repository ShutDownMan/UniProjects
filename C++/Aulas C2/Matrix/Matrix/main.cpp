#include "matrix.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char *argv[]) {
    int nl = 10, nc = 10;
    Matrix *m1 = new Matrix(nl, nc);
    Matrix *m2 = new Matrix(nl, nc);
    Matrix *m3 = NULL;

    srand(time(NULL));

    for(int row = 0; row < nl; row++) {
        for(int col = 0; col < nc; col++) {
            m1->setElem(col, row, (row + 1)*nc + (col + row));
            m2->setElem(col, row, rand()%nl);
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

    m3 = m2->triangulate();
    m3->sanizite();
    m3->show();
    cout << "-------------" << endl;

//    delete m1;
//    delete m2;

    return 0;
}
