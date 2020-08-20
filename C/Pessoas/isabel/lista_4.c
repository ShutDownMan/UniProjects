#include <stdio.h>

int main(void) {
    float vetA[8] = {0};
    int pos1 = 0, pos2 = 0;
    int i = 0;

    /// ler valores vetor
    for(i = 0; i < 8; ++i) {
        scanf("%f", &vetA[i]);
    }

    /// ler valores
    scanf("%d", &pos1);
    scanf("%d", &pos2);

    /// print valores na pos1 e pos2
    printf("vetA[%d] = %f\n", pos1-1, vetA[pos1-1]);
    printf("vetA[%d] = %f\n", pos2-1, vetA[pos2-1]);
    
    return 0;
}
