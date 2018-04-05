#ifndef PONTO_H
#define PONTO_H

class Ponto {
    protected:
        double x;
        double y;

    public:
        Ponto(double x, double y);
        void setX(double x);
        void setY(double y);
        double getX(void);
        double getY(void);
        void show(void);
        virtual ~Ponto(void);
};

#endif // PONTO_H
