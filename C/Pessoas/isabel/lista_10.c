#include <stdio.h>

int main(void) {
    float vetA[15] = {0};
    float media;
    int i = 0;

    /// ler valores
    for(i = 0; i < 15; ++i) {
        scanf("%f", &vetA[i]);
    }

    /// faz a media
    for(i = 0; i < 15; ++i) {
        media += vetA[i];
    }
    media /= 15;

    /// print media
    printf("media = %.1f\n", media);

    return 0;
}
