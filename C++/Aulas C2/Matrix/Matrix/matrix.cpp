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

int Matrix::getElem(int row, int col) {
    if(row < this->getHeight() && col < this->getWidth()) {
        return this->mArray[row][col];
    }

    return 0;
}

void Matrix::setHeight(int d) {
    this->height = d;
}

void Matrix::setWidth(int d) {
    this->width = d;
}

void Matrix::setElem(int row, int col, int d) {
    if(row < this->getWidth() && col < this->getHeight())
        this->mArray[row][col] = d;
}

bool Matrix::sizeEquals(Matrix *other) {
    return (this->getHeight() == other->getHeight() &&
            this->getWidth() == other->getWidth());
}

bool Matrix::equals(Matrix *other) {
    if(!this->sizeEquals(other)) return false;

    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            if(this->getElem(row, col) != other->getElem(row, col)) {
                return false;
            }
        }
    }
    return true;
}

Matrix *Matrix::transpose() {
    Matrix *newMat = new Matrix(this->getWidth(), this->getHeight());

    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            newMat->setElem(row, col, this->getElem(col, row));
        }
    }

    return newMat;
}

Matrix *Matrix::negative() {
    Matrix *n = new Matrix(this->getHeight(), this->getWidth());

    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            n->setElem(row, col, -this->getElem(row, col));
        }
    }

    return n;
}

Matrix *Matrix::clone() {
    Matrix *m = new Matrix(this->getHeight(), this->getWidth());

    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            m->setElem(row, col, this->getElem(row, col));
        }
    }

    return m;
}

void Matrix::empty() {
    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            this->setElem(row, col, 0);
        }
    }
}

bool Matrix::isSquare() {
    return (this->getHeight() == this->getWidth());
}

bool Matrix::isIdentity() {
	if(!this->isSquare()) return false;

    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            if(row == col) {
                if(this->getElem(row, col) != 1)
                    return false;
            } else {
                if(this->getElem(row, col))
                    return false;
            }
        }
    }

    return true;
}

bool Matrix::isDiagonal() {
	if(!this->isSquare()) return false;

    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            if(row == col) {
                if(!this->getElem(row, col))
                    return false;
            } else {
                if(this->getElem(row, col))
                    return false;
            }
        }
    }

    return true;
}

bool Matrix::isSingular() {
    if(!this->isSingular()) return false;

    for(int i = 1; i < this->getHeight(); i++) {
    	if(this->getElem(i, i) != this->getElem(i-1, i-1)) {
    		return false;
    	}
    }

    return true;
}

bool Matrix::isSymmetric() {
	if(!this->isSquare()) return false;

    for(int row = 0; row < this->getHeight()/2; row++) {
        for(int col = 0; col < this->getWidth()/2; col++) {
            if(this->getElem(row, col) != this->getElem(col, row))
                return false;
        }
    }

    return true;
}

bool Matrix::isSkewSymmetric() {
    for(int row = 0; row < this->getHeight()/2; row++) {
        for(int col = 0; col < this->getWidth()/2; col++) {
            if(row != col)
                if(-(this->getElem(row, col)) != this->getElem(col, row))
                    return false;
        }
    }

    return true;
}

void Matrix::sum(Matrix *other) {
    if(!this->sizeEquals(other)) return;

    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            this->setElem(row, col, this->getElem(row, col) + other->getElem(row, col));
        }
    }
}

Matrix *Matrix::operator+(Matrix &other) {
    Matrix *res = new Matrix(this->getHeight(), this->getWidth());
    if(!this->sizeEquals(&other)) return res;

    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            res->setElem(row, col, this->getElem(row, col) + other.getElem(row, col));
        }
    }

    return res;
}

void Matrix::subtraction(Matrix *other) {
    if(!this->sizeEquals(other)) return;

    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            this->setElem(row, col, this->getElem(row, col) - other->getElem(row, col));
        }
    }
}

Matrix *Matrix::operator-(Matrix &other) {
    Matrix *res = new Matrix(this->getHeight(), this->getWidth());
    if(!this->sizeEquals(&other)) return res;

    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            res->setElem(row, col, this->getElem(row, col) - other.getElem(row, col));
        }
    }

    return res;
}

void Matrix::multiply(Matrix *other) {
    if(!this->isSquare()) return;

    Matrix *r = new Matrix(this->getHeight(), this->getWidth());

    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < other->getWidth(); col++) {
            for(int k = 0; k < this->getWidth(); k++) {
                r->setElem(row, col, r->getElem(row, col) + this->getElem(k, row) * other->getElem(col, k));
            }
        }
    }

    this->copy(r);

    delete r;
}

Matrix *Matrix::operator*(Matrix &other) {
    Matrix *res = new Matrix(this->getHeight(), this->getWidth());

    if(this->getWidth() != other.getHeight()) {
        this->empty();
        return res;
    }

    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < other.getWidth(); col++) {
            res->setElem(row, col, 0);
            for(int k = 0; k < this->getWidth(); k++) {
                res->setElem(row, col, res->getElem(row, col) + this->getElem(row, k) * other.getElem(k, col));
            }
        }
    }

    return res;
}

int *Matrix::operator[] (int ind) {
    return this->mArray[ind];
}

void Matrix::copy(Matrix *other) {
    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            this->setElem(row, col, other->getElem(row, col));
        }
    }
}

void Matrix::show() {
    for(int row = 0; row < this->getHeight(); row++) {
        for(int col = 0; col < this->getWidth(); col++) {
            cout << this->getElem(row, col) << " ";
        }
        cout << endl;
    }
}
