#ifndef MATRIX_H
#define MATRIX_H

#define MAX_HEIGHT 64
#define MAX_WIDTH 64

#include <iostream>
#include <math.h>

using namespace std;

class Matrix {
private:
    int height, width;
    double mArray[MAX_HEIGHT][MAX_WIDTH];
public:
    Matrix();
    Matrix(int height, int width);
    ~Matrix();

    int getHeight();
    int getWidth();
    double getElem(int x, int y);

    void setHeight(int d);
    void setWidth(int d);
    void setElem(int x, int y, double d);

    bool sizeEquals(Matrix *other);

    bool equals(Matrix *other);
    Matrix* transpose();
    Matrix* negative();
    Matrix* clone();
    void empty();

    bool isSquare();
    bool isIdentity();
    bool isDiagonal();
    bool isSingular();
    bool isSymmetric();
    bool isSkewSymmetric();

    void sum(Matrix *other);
    void subtraction(Matrix *other);
    void multiply(Matrix *other);
    void copy(Matrix *other);

    Matrix *operator+(Matrix &other);
    Matrix *operator-(Matrix &other);
    Matrix *operator*(Matrix &other);

    double *operator[] (int ind);

    Matrix *triangulate();
    double getDeterminant();

    void sanizite();

    void show();
};

#endif // MATRIX_H
