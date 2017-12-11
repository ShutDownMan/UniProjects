#include <stdio.h>

int fac(int n);

int main(){
    int n;

    printf("digite um numero: ");
    scanf("%d",&n);

    printf("\no fatorial de %d eh: %d", n, fac(n));

}

int fac(int n){
    if(n <= 1){
        return 1;
    } else {
        return n * fac(n-1);
    }
}