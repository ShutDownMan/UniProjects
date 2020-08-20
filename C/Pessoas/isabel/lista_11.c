#include <stdio.h>

int main(void) {
    float vetA[10] = {0};
    float somaPositivos;
    int quantNegativos = 0;
    int i = 0;

    /// ler valores
    for(i = 0; i < 10; ++i) {
        scanf("%f", &vetA[i]);
    }

    /// procurar quantidade negativos e soma positivos
    for(i = 0; i < 10; ++i) {
        /// se val eh negativo
        if(vetA[i] < 0) {
            quantNegativos++;
        } else {
            somaPositivos += vetA[i];
        }
    }

    /// quant negativos
    printf("quantNegativos = %d\n", quantNegativos);
    /// print quantidade negativos
    printf("somaPositivos = %f\n", somaPositivos);

    return 0;
}
