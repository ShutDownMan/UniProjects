#include <stdio.h>

int main(void) {
    float vetA[5] = {0};
    float maiorVal = 0, menorVal = 0;
    int maiorValPos = 0, menorValPos = 0; 
    int i = 0;

    /// ler valores
    for(i = 0; i < 5; ++i) {
        scanf("%f", &vetA[i]);
    }

    /// procurar maior/menor e sua posicao
    maiorVal = menorValPos = vetA[0];
    maiorValPos = menorValPos = 0;
    for(i = 1; i < 5; ++i) {
        /// se atual for maior
        if(vetA[i] > maiorVal) {
            maiorVal = vetA[i];
            maiorValPos = i;
        }

        /// se atual for menor
        if(vetA[i] < menorVal) {
            menorVal = vetA[i];
            menorValPos = i;
        }
    }

    /// print maior/menor e sua posicao
    printf("vetA[%d] = %f\n", maiorValPos, maiorVal);
    printf("vetA[%d] = %f\n", menorValPos, menorVal);

    return 0;
}
