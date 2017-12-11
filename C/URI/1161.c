#include <stdio.h>

long int fac(int f);

int main() {
    int n1, n2;

    while((scanf("%d %d", &n1, &n2)) != EOF) {
        printf("%ld\n", fac(n1)+fac(n2));
    }

    return 0;
}

long int fac(int f) {
    return (f <= 1) ? 1 : f * fac(f-1);
}