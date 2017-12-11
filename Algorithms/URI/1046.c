#include <stdio.h>

int main(){
    int a, b, result;

    scanf("%d %d", &a, &b);

    result = (a >= b) ? -(a-b)+24 : -(a-b);

    printf("O JOGO DUROU %d HORA(S)\n", result);

    return 0;
}