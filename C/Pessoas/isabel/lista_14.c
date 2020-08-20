#include <stdio.h>

int main(void) {
    int vetA[10] = {0};
    float media;
    int i = 0, j = 0;

    /// ler valores
    for(i = 0; i < 10; ++i) {
        scanf("%d", &vetA[i]);
    }

    /// verifica se ha iguais e printa
    for(i = 0; i < 10; ++i) {
        for(j = 1; j < 10; ++j) {
            if(i != j && vetA[i] == vetA[j]) {
                printf("vetA[%d] = vetA[%d] = %d\n", i, j, vetA[i]);
            }
        }
    }

    return 0;
}
