#include <stdio.h>

 int main () {
    int quant; 
    double val, total = 0;

    for (int i = 0;i<2;i++){
        scanf("%*d %d %lf", &quant, &val);

        total += quant*val;
    }

    printf("VALOR A PAGAR: R$ %.2lf\n", total);

    return 0;
}