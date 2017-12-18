#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 12

int lermat (double matriz[][MAX], int tam);
double soma (double matriz[][MAX], double* resultado);
double* media  (double matriz[][MAX], double* resultado);


int main(int argc, char const *argv[]){
    double matriz[MAX][MAX], resultado = 0;
    char ope;

    scanf("%c ", &ope);

    lermat(matriz, MAX);

    switch (ope){
        case 'S': 
            soma(matriz, &resultado); 
            break;

        default:
            media(matriz, &resultado); 
            break;
    }
    //printf("%c\n", ope);
    printf("%.1lf\n", resultado);
    return 0;
}

int lermat (double matriz[][MAX], int tam){
    int i, j;

    for (i = 0; i < tam; ++i)
        for ( j = 0; j < tam; ++j){
            scanf("%lf", &matriz[i][j]);
        }
    return 0;    
}

double soma (double matriz[][MAX], double *resultado){
    double soma = 0;
    int i, j;

    for (i = 0; i < MAX; ++i){
        for ( j = 0; j < MAX; j++){
            if (((i+j) < (MAX-1)) && (j > i)){
                soma += matriz[i][j];
            }
        }
    }

    *resultado = soma;
    //printf(" soma = %g\n", soma);
    return soma;
    
}

double* media (double matriz[][MAX], double *resultado){
    int i, j;
    double soma = 0;
    int c = 0;

    for (i = 0; i < MAX; ++i){
        for ( j = 0; j < MAX; j++){
            if (((i+j) < (MAX-1)) && (j > i)){
                soma += matriz[i][j];
                c++;
            }
        }
    }

    *resultado = (soma / c);
}