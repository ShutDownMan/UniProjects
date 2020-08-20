#include <stdio.h>

int main(void) {
    float vetA[10] = {0};
    float maiorVal = 0, menorVal = 0;
    int i = 0;

    /// ler valores
    for(i = 0; i < 10; ++i) {
        scanf("%f", &vetA[i]);
    }

    /// procurar maior e menor
    maiorVal = menorVal = vetA[0];
    for(i = 1; i < 10; ++i) {
        /// se atual for maior
        if(vetA[i] > maiorVal) {
            maiorVal = vetA[i];
        }

        /// se atual for menor
        if(vetA[i] < menorVal) {
            menorVal = vetA[i];
        }
    }

    /// print maior e menor
    printf("maiorVal = %f\n", maiorVal);
    printf("menorVal = %f\n", menorVal);

    return 0;
}
