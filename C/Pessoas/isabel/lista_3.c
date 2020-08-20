#include <stdio.h>

int main(void) {
    float vetA[10] = {0};
    float vetAQuadrado[10] = {0};
    int i = 0;

    /// ler valores
    for(i = 0; i < 10; ++i) {
        scanf("%f", &vetA[i]);
    }

    /// calcular quadrado
    for(i = 0; i < 10; ++i) {
        vetAQuadrado[i] = vetA[i]*vetA[i];
    }

    /// print vetor quadrado
    for(i = 0; i < 10; ++i) {
        printf("vetAQuadrado[%d] = %f\n", i, vetAQuadrado[i]);
    }

    return 0;
}
