#include <stdio.h>

int main() {
    int quant;
    double valorPeca, somaTotal;

    scanf("%*d %d %lf", &quant, &valorPeca);

    somaTotal += quant*valorPeca;

    scanf("%*d %d %lf", &quant, &valorPeca);

    somaTotal += quant*valorPeca;

    printf("VALOR A PAGAR: R$ %.2lf\n", somaTotal);

    return 0;
}