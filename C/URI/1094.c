#include <stdio.h>

int main() {
    int n, i, animalCount = 0, totalSum = 0;
    char currAnimal;

    int count[17] = { 0 };

    count[0] = 0;
    count[15] = 0;
    count[16] = 0;

    scanf("%d", &n);

    for(i = 0; i < n; ++i) {
        scanf("%d %c", &animalCount, &currAnimal);

        totalSum += animalCount;

        count[currAnimal-'C'] += animalCount;
    }

    printf("Total: %d cobaias\n", totalSum);
    printf("Total de coelhos: %d\n", count[0]);
    printf("Total de ratos: %d\n", count[15]);
    printf("Total de sapos: %d\n", count[16]);
    printf("Percentual de coelhos: %.2f %%\n", ((float)count[0]/totalSum)*100);
    printf("Percentual de ratos: %.2f %%\n", ((float)count[15]/totalSum)*100);
    printf("Percentual de sapos: %.2f %%\n", ((float)count[16]/totalSum)*100);
}