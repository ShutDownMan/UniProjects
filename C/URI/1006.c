#include <stdio.h>

int main() {
    double n1, n2, n3;

    scanf("%lf %lf %lf", &n1, &n2, &n3);

    printf("MEDIA = %.1lf\n", (2*n1+3*n2+5*n3)/10);

    return 0;
}