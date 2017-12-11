#include <stdio.h>

int main() {
    int diasTotais, anos, meses, dias;

    scanf("%d", &diasTotais);

    anos = diasTotais/365;
    meses = diasTotais%365/30;
    dias = diasTotais%365%30;

    printf("%i ano(s)\n", anos);
    printf("%i mes(es)\n", meses);
    printf("%i dia(s)\n", dias);

    return 0;
}