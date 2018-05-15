#include <stdio.h>

#define PI 3.14159

int fac(int n);

double pow(double n, unsigned int exp);

double seno(double rad);

double cos(double rad);

double rad(double degrees);

double redux(double angle);

double newSen(double angle);

double newCos(double angle);

int main() {
    double degrees;

    printf("Entre com um angulo: ");

    scanf("%lf", &degrees);

    printf("%.1lf graus em radianos eh %.1lf\n", degrees, rad(degrees));

    printf("O seno de %.1lf graus eh %.1lf\n", degrees, seno(redux(rad(degrees))));
    printf("O cosseno de %.1lf graus eh %.1lf\n", degrees, cos(redux(rad(degrees))));

    printf("O newSeno de %.1lf graus eh %.1lf\n", degrees, newSen(redux(rad(degrees))));
    printf("O newCos de %.1lf graus eh %.1lf\n", degrees, newCos(redux(rad(degrees))));

    return 0;
}

int fac(int n){
    if(n > 1) {
        return n * fac(n-1);
    } else {
        return 1;
    }
}

double pow(double n, unsigned int exp){
    if(exp == 0){
        return 1;
    } else if(exp%2 == 0) {
        return pow(n, exp/2)*pow(n, exp/2);
    } else {
        return n*pow(n, exp/2)*pow(n, exp/2);
    }
}

double rad(double degrees) {
    return (degrees * PI) / 180;
}

double redux(double radAngle) {
    double y;
    y = (radAngle/(2*PI));
    return (y - ((int)y)) * (2*PI);
}

double seno(double x) {
    return x - ((double)pow(x, 3)/fac(3)) + ((double)pow(x, 5)/fac(5)) - ((double)pow(x, 7)/fac(7)) + ((double)pow(x, 9)/fac(9));
}

double cos(double x){
    return 1 - ((double)pow(x, 2)/fac(2)) + ((double)pow(x, 4)/fac(4)) - ((double)pow(x, 6)/fac(6)) + ((double)pow(x, 8)/fac(8));
}

double newSen(double x){
    float s = 0, t = 1;

    s += x;

    t *= -pow(x, 2)/3*2;

    s += t;

    t *= -pow(x, 2)/5*4;

    s += t;

    t *= -pow(x, 2)/7*6;

    s += t;

    t *= -pow(x, 2)/9*8;

    s += t;

    return s;
}

double newCos(double x){
    float s = 0, t = 1;

    s += 1;

    t *= -pow(x, 2)/2*1;

    s += t;

    t *= -pow(x, 2)/4*3;

    s += t;

    t *= -pow(x, 2)/6*5;

    s += t;

    t *= -pow(x, 2)/8*7;

    s += t;

    return s;
}