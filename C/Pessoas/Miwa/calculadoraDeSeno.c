#include <stdio.h>
#include <math.h>
#define pi 3.14159

double rad(double degrees);

double sen(double rad);

int main() {
    double x;

    printf("Entre com um angulo: ");

    scanf("%lf", &x);

    printf("%lf em radianos eh: %lf\n", x, rad(x));

    printf("O seno de %lf eh: %lf\n", x, sen(rad(x)));

    return 0;
}

double rad(double degrees){
    return (degrees*pi)/180;
}

double sen(double rad){
    return (rad-(pow(rad, 3))/fac(3)+(pow(rad, 5))/fac(5));
}