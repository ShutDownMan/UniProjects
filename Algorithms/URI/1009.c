#include <stdio.h>

int main() {
    double salarioBase, valorVendas;

    scanf("%*s %lf %lf", &salarioBase, &valorVendas);

    printf("TOTAL = R$ %.2lf\n", salarioBase + valorVendas*0.15);

    return 0;
}