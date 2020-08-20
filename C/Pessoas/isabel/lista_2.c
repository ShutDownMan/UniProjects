#include <stdio.h>

int main(void) {
    int vetA[6] = {0};
    int i = 0;

    /// ler valores
    for(i = 0; i < 6; ++i) {
        scanf("%d", &vetA[i]);
    }

    /// print valores
    for(i = 0; i < 6; ++i) {
        printf("vetA[%d] = %d\n", i, vetA[i]);
    }

    return 0;
}
