#ifndef CIRCULO_H
#define CIRCULO_H

#include "ponto.h"

class Circulo:Ponto {
    protected:
        double raio;

    public:
        Circulo(double x, double y, double r);
        void mover(double x, double y);
        void mover(Ponto *p);
        void show(void);
        void aumentar(void);
        void diminuir(void);
        double getRaio(void);
        ~Circulo(void);
};

#endif // CIRCULO_H
