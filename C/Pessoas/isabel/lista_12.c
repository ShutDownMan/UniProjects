#include <stdio.h>

int main(void) {
    float vetA[5] = {0};
    float maiorVal, menorVal, media;
    int quantNegativos = 0;
    int i = 0;

    /// ler valores
    for(i = 0; i < 5; ++i) {
        scanf("%f", &vetA[i]);
    }

    /// procurar maior, menor e calc media
    maiorVal = menorVal = media = vetA[0];
    for(i = 1; i < 5; ++i) {
        /// se atual for maior
        if(vetA[i] > maiorVal) {
            maiorVal = vetA[i];
        }

        /// se atual for menor
        if(vetA[i] < menorVal) {
            menorVal = vetA[i];
        }

        media += vetA[i];
    }

    media /= 5;

    /// maior val, menor val e media
    printf("maiorVal = %f\n", maiorVal);
    printf("menorVal = %f\n", menorVal);
    printf("media = %f\n", media);

    return 0;
}
