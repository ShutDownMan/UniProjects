#include "matrix.h"

#include <iostream>

using namespace std;

Matrix::Matrix() {
    this->setHeight(0);
    this->setWidth(0);
    this->empty();
}

Matrix::Matrix(int height, int width) {
    this->setHeight(height);
    this->setWidth(width);
    this->empty();
}

Matrix::~Matrix() {
    cout << "(Matrix) Freeing memory." << endl;
}

int Matrix::getHeight() {
    return this->height;
}

int Matrix::getWidth() {
    return this->width;
}

int Matrix::getElem(int x, int y) {
    if(x < this->getWidth() && y < this->getHeight())
        return this->mArray[y][x];
    return 0;
}

void Matrix::setHeight(int d) {
    this->height = d;
}

void Matrix::setWidth(int d) {
    this->width = d;
}

void Matrix::setElem(int x, int y, int d) {
    if(x < this->getWidth() && y < this->getHeight())
        this->mArray[y][x] = d;
}

bool Matrix::checkDim(Matrix &other) {
    if(this->getHeight() != other.getHeight() ||
            this->getWidth() != other.getWidth())
        return false;
    return true;
}

bool Matrix::equals(Matrix &other) {
    if(!this->checkDim(other)) return false;

    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            if(this->getElem(col, row) != other.getElem(col, row)) {
                return false;
            }
        }
    }
    return true;
}

Matrix* Matrix::transpose() {
    Matrix* t = new Matrix(this->getWidth(), this->getHeight());

    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            t->setElem(col, row, this->getElem(row, col));
        }
    }

    return t;
}

Matrix* Matrix::negative() {
    Matrix* n = new Matrix(this->getHeight(), this->getWidth());

    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            n->setElem(col, row, -this->getElem(col, row));
        }
    }

    return n;
}

Matrix* Matrix::clone() {
    Matrix* m = new Matrix(this->getHeight(), this->getWidth());

    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            m->setElem(col, row, this->getElem(col, row));
        }
    }

    return m;
}

void Matrix::empty() {
    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            this->setElem(col, row, 0);
        }
    }
}

bool Matrix::isIdentity() {
    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            if(row == col) {
                if(this->getElem(col, row) != 1)
                    return false;
            } else {
                if(this->getElem(col, row))
                    return false;
            }
        }
    }

    return true;
}

bool Matrix::isDiagonal() {
    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            if(row == col) {
                if(!this->getElem(col, row))
                    return false;
            } else {
                if(this->getElem(col, row))
                    return false;
            }
        }
    }

    return true;
}

bool Matrix::isSingular() {
    int d = this->getElem(0, 0);

    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 1; col < this->getWidth(); col++) {
            if(row == col) {
                if(this->getElem(col, row) != d)
                    return false;
            } else {
                if(this->getElem(col, row))
                    return false;
            }
        }
    }

    return true;
}

bool Matrix::isSymmetric() {

    for(int row = 0; row < this->getHeight()/2; row++) {
        for(int col = 0; col < this->getWidth()/2; col++) {
            if(this->getElem(col, row) != this->getElem(row, col))
                return false;
        }
    }

    return true;
}

bool Matrix::isSkewSymmetric() {
    for(int row = 0; row < this->getHeight()/2; row++) {
        for(int col = 0; col < this->getWidth()/2; col++) {
            if(row != col)
                if(-(this->getElem(col, row)) != this->getElem(row, col))
                    return false;
        }
    }

    return true;
}

void Matrix::sum(Matrix &other) {
    if(!this->checkDim(other)) return;

    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            this->setElem(col, row, this->getElem(col, row) + other.getElem(col, row));
        }
    }
}

void Matrix::subtraction(Matrix &other) {
    if(!this->checkDim(other)) return;

    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            this->setElem(col, row, this->getElem(col, row) - other.getElem(col, row));
        }
    }
}

void Matrix::multiply(Matrix &other) {
    if(this->getWidth() != other.getHeight()) {
        this->empty();
        return;
    }

    Matrix* r = new Matrix(this->getHeight(), this->getWidth());

    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < other.getWidth(); col++) {
            for(int k = 0; k < this->getWidth(); k++) {
                r->setElem(col, row, r->getElem(col, row) + this->getElem(k, row) * other.getElem(col, k));
            }
        }
    }

    this->copy(*r);

    delete r;
}

void Matrix::copy(Matrix &other) {
    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            this->setElem(col, row, other.getElem(col, row));
        }
    }
}

void Matrix::show() {
    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            cout << this->getElem(col, row) << " ";
        }
        cout << endl;
    }
}
