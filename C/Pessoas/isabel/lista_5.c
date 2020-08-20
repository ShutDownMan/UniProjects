#include <stdio.h>

int main(void) {
    int vetA[10] = {0};
    int quantPares = 0;
    int i = 0;

    /// ler valores
    for(i = 0; i < 10; ++i) {
        scanf("%d", &vetA[i]);
    }

    /// contar pares
    for(i = 0; i < 10; ++i) {
        /// val % 2 = 1 se impar
        if(!(vetA[i] % 2)) {
            quantPares++;
        }
    }

    /// print quantPares
    printf("quantPares = %d\n", quantPares);

    return 0;
}
