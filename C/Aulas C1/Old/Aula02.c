#include <stdio.h>

inline int InvertAll2(int a) {
    return (a %10)*10 + (a /10);
}

inline int InvertAll3(int a) {
    return (a %10)*100 + (a %100/10)*10 + (a /100);
}

inline int InvertTenthsUp(int a) {
    return (a %100/10)*100 + (a /100)*10 + (a %10);
}

inline int InvertTenthsDown(int a) {
    return (a %10)*100 + a/10;
}

inline int CrossMult(int a, int b) {
    return (a /10)*(b %10) + (b /10)*(a %10);
}

int main() {
    int a, b;

    printf("Entre com dois numeros para serem invertidos: ");

    scanf("%d %d", &a, &b);

    printf("%d invertido eh %02d \n", a, CrossMult(a, b));

    return 0;
}