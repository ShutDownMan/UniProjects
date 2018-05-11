#ifndef MATRIX_H
#define MATRIX_H

#define MAX_HEIGHT 64
#define MAX_WIDTH 64

class Matrix {
private:
    int height, width;
    int mArray[MAX_HEIGHT][MAX_WIDTH];
public:
    Matrix();
    Matrix(int height, int width);
    ~Matrix();

    int getHeight();
    int getWidth();
    int getElem(int x, int y);

    void setHeight(int d);
    void setWidth(int d);
    void setElem(int x, int y, int d);

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

    int *operator[] (int ind);

    Matrix *triangulate();
    double getDeterminant();

    void show();
};

#endif // MATRIX_H
