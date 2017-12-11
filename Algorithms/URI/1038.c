#include <stdio.h>

int main(){
    int index, quant;
    float precos[5] = {4.00, 4.50, 5.00, 2.00, 1.50};

    scanf("%d %d", &index, &quant);

    printf("Total: R$ %.2f\n", quant*precos[index-1]);

    return 0;
}