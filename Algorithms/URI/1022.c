#include <stdio.h>

void soma(int n1, int d1, int n2, int d2);
void subt(int n1, int d1, int n2, int d2);
void mult(int n1, int d1, int n2, int d2);
void div(int n1, int d1, int n2, int d2);

void simplify(int *n, int *d);
int getGCD(int a, int b);

int abs(int n);

int main(){
    int N1, D1, N2, D2;
    char _operator;

    int n = 0;

    scanf("%d", &n);
    
    for(int i=0;i<n;i++){
        scanf("%d %*c %d", &N1, &D1);
        scanf(" %c ", &_operator);
        scanf("%d %*c %d", &N2, &D2);

        //printf("%d %d %c %d %d\n", N1, D1, _operator, N2, D2);

        switch(_operator){
            case '+':
                soma(N1, D1, N2, D2);
                break;

            case '-':
                subt(N1, D1, N2, D2);
                break;

            case '*':
                mult(N1, D1, N2, D2);
                break;

            case '/':
                div(N1, D1, N2, D2);
                break;
        }

    }
}

void soma(int n1, int d1, int n2, int d2){
    int n3 = 0, d3 = 0;

    n3 = (n1*d2 + n2*d1);
    d3 = (d1*d2);

    printf("%d/%d", n3, d3);
    printf(" = ");

    simplify(&n3, &d3);
    
    printf("%d/%d\n", n3, d3);
}

void subt(int n1, int d1, int n2, int d2){
    int n3 = 0, d3 = 0;

    n3 = (n1*d2 - n2*d1);
    d3 = (d1*d2);

    printf("%d/%d", n3, d3);
    printf(" = ");

    simplify(&n3, &d3);
    
    printf("%d/%d\n", n3, d3);
}

void mult(int n1, int d1, int n2, int d2){
    int n3 = 0, d3 = 0;

    n3 = (n1 * n2);
    d3 = (d1 * d2);

    printf("%d/%d", n3, d3);
    printf(" = ");

    simplify(&n3, &d3);
    
    printf("%d/%d\n", n3, d3);
}

void div(int n1, int d1, int n2, int d2){
    int n3 = 0, d3 = 0;

    n3 = (n1 * d2);
    d3 = (n2 * d1);

    printf("%d/%d", n3, d3);
    printf(" = ");

    simplify(&n3, &d3);
    
    printf("%d/%d\n", n3, d3);
}


void simplify(int *n, int *d){
    int gdc = getGCD(*n, *d);
    
    if(gdc != 0){
        *n /= abs(gdc);
        *d /= abs(gdc);
    }
}

int getGCD(int a, int b) {
	return (b == 0) ? a : getGCD(b, a % b);
}

int abs(int n){
    return (n>0) ? n:-n;
}

/*
    Soma: (N1*D2 + N2*D1) / (D1*D2)
    Subtração: (N1*D2 - N2*D1) / (D1*D2)
    Multiplicação: (N1*N2) / (D1*D2)
    Divisão: (N1/D1) / (N2/D2), ou seja (N1*D2)/(N2*D1)
*/