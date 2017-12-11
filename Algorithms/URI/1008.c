#include <stdio.h>

int main() {
    int numero, horasT;
    double salarioH;

    scanf("%d %d %lf", &numero, &horasT, &salarioH);

    printf("NUMBER = %d\n", numero);
    printf("SALARY = U$ %.2lf\n", horasT*salarioH);

    return 0;
}