#include "matrix.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    Matrix* m1 = new Matrix(2, 2);
    Matrix* m2 = new Matrix(2, 2);

    for(int row = 0; row < 2; row++) {
        for(int col = 0; col < 2; col++) {
            m1->setElem(col, row, col + 1);
            if(row == col)
                m2->setElem(col, row, col+row+1);
            else
                m2->setElem(col, row, -(col+row+1));

        }
    }

    m1->show();
    cout << "-------------" << endl;
    m2->show();
    cout << "-------------" << endl;

    ((*m1) - (*m2)).show();
    cout << "-------------" << endl;

    delete m1;
    delete m2;

    return 0;
}
