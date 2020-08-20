#include <stdio.h>

int main(void) {
    int vetA[6] = {0};
    int i = 0;

    /// a)
    vetA[0] = 1;
    vetA[1] = 0;
    vetA[2] = 5;
    vetA[3] = -2;
    vetA[4] = -5;
    vetA[5] = -7;

    /// b)
    int val1 = vetA[0] + vetA[1] + vetA[5];
    printf("val1 = %d\n", val1);

    /// c)
    vetA[3] = 100;

    /// d)
    for(i = 0; i < 6; ++i) {
        printf("vetA[%d] = %d\n", i, vetA[i]);
    }

    return 0;
}
