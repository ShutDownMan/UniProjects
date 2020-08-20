#include <stdio.h>

int main(void) {
    int vetA[50] = {0};
    int i = 0;

    /// cria vetor
    for(i = 0; i < 50; ++i) {
        vetA[i] = (i + 5 * i) % (i + 1);
    }

    /// print vetor
    for(i = 0; i < 50; ++i) {
        printf("vetA[%d] = %d\n", i, vetA[i]);
    }

    return 0;
}
