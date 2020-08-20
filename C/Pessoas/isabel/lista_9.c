#include <stdio.h>

int main(void) {
    int vetA[6] = {0};
    int i = 0;

    /// ler valores
    for(i = 0; i < 6;) {
        scanf("%d", &vetA[i]);

        /// se numero lido eh par
        if(!(vetA[i] % 2)) {
            /// avanca loop
            ++i;
        }
    }

    /// print na ordem inversa
    for(i = 5; i >= 0; --i) {
        printf("%d\n", vetA[i]);
    }

    return 0;
}
