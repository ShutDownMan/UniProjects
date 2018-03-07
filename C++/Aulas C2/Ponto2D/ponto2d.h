#ifndef PONTO2D_H
#define PONTO2D_H

class Point2D {

private:
    double x;
    double y;
public:
    Point2D();
    Point2D(double x, double y);
    Point2D(Point2D &other);
    ~Point2D();

    double getX();
    double getY();

    void setX(double d);
    void setY(double d);

    void mover();
    void mover(double x, double y);
    void mover(Point2D &other);

    bool equals(Point2D &other);

    double distance(Point2D &other);

    Point2D* clone();

    void show();
};

#endif // PONTO2D_H
