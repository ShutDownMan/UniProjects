#include <stdio.h>

int main(void) {
    int vetA[10] = {0};
    int maiorVal = 0, maiorValPos = 0;
    int i = 0;

    /// ler valores
    for(i = 0; i < 10; ++i) {
        scanf("%d", &vetA[i]);
    }

    /// procurar maior e sua posicao
    maiorVal = vetA[0];
    maiorValPos = 0;
    for(i = 1; i < 10; ++i) {
        /// se atual for maior
        if(vetA[i] > maiorVal) {
            maiorVal = vetA[i];
            maiorValPos = i;
        }
    }

    /// print maior e sua posicao
    printf("vetA[%d] = %d\n", maiorValPos, maiorVal);

    return 0;
}
