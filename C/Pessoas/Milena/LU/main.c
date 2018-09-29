#include <stdio.h>
#include <stdlib.h>
#include "eliminacaogauss.h"

void imprimeMatriz(double **m, int lin, int col){
    int i, j;
    double v[lin];
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            printf("%lf\t", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    vetorb(m,v,lin);
}

void matriz(double **m, int lin, int col){
    int i, j;
    printf("Digite os valores:\n");
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            scanf("%lf", &m[i][j]);
        }
    }
    imprimeMatriz(m, lin, col);
    printf("\n");
}

double **criar(int lin, int col){
    int i;
    double ** m = (double **)malloc(sizeof(double**)*lin);
    double *aux = (double*)malloc(sizeof(double*)*(lin*col));
    for(i = 0; i < lin; i++){
        m[i] = &aux[col*i];
    }
    matriz(m, lin, col);
    return m;
}

int tam_pivo(int ordem){
    int i, j, tam = 0;
    for(i = 0; i < ordem; i++){
        for(j = 0; j < ordem; j++){
            if(i!=j)
                tam++;
        }
    }
    return tam/2;
}

void elimGauss(double **m, int ordem, double pivo[]){
    int i, j, k;
    int aux_pivo = 0;
    double *aux;

    // troca a primeira com a proxima linha com valor diferente a 0, se m[0][0] = 0
    if(m[0][0] == 0){
        for(i = 1; i < ordem; i++){
            for(j = 0; j < 1; j++){
                if(m[i][j] != 0){
                    aux = m[0];
                    m[0] = m[i];
                    m[i] = aux;
                    break;
                }
            }
        }
    }

    //eliminacao de gauss
    for(k = 0; k < ordem-1; k++){
        for(i = k + 1; i < ordem; i++){
            pivo[aux_pivo] = m[i][k]/m[k][k];
            m[i][k] = 0;
            for(j = k + 1; j <= ordem ; j++){
                m[i][j] -= pivo[aux_pivo]*m[k][j];
                printf("\n");
            }
            imprimeMatriz(m, ordem, ordem +1);
            aux_pivo++;
        }
    }

    printf("\nFIM\n\n");

    if(m[ordem - 1][ordem-1] != 0){
        solucao(m, ordem);
    }
    else{
        printf("Sistema Impossivel\n");
    }

    return &pivo;

}
void solucao(double **m, int ordem){
    int i, j;
    double aux, result[ordem-1];
    result[ordem-1] = m[ordem - 1][ordem]/m[ordem - 1][ordem - 1];

    for(i = ordem - 2; i >= 0 ; i--){
        aux  = 0;
        for(j = i + 1; j < ordem; j++){
            aux += m[i][j]*result[j];
        }
        result[i] = (m[i][ordem] - aux)/m[i][i];
    }

    for(i = 0; i < ordem; i++){
        printf("result[%d] = %lf\n", i, result[i]);
    }

    printf("\nFIM\n");

}

void vetorb(double **m,double *vet, int size){

    int i;
    for(i=0;i<size;i++){
        vet[i] = m[i][size];
        printf("%lf\n", vet[i]);
    }

}


double** matrizL(double **l,double *p,int size){

    int i,j;

    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            l[i][j] = 0;
        }
    }
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(i==j){
                l[i][j] = 1;
            }
        }
    }
    int aux = 0;
    for(i=0;i<size;i++){
        for(j=0; j < size;j++){
            if(i > j){
                l[i][j] = p[aux];
                aux++;
            }
        }
    }

     for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            printf("%lf ", l[i][j]);
        }
        printf("\n");
    }
    return l;
}

void calculoML(double **m, double **l, int size){
    int i,j;
    double aux, y[size], x[size], v[size];

    printf("\n");

    y[size] = v[size];

    y[0] = m[0][size] / l[0][0];

    for(i=1;i<size-1;i++){
        aux = 0.0;
        for(j=0;j < i-1;j++){
            aux = aux + (l[i][j]*y[j]);
        }
    }

    if(m[size-1][size-1] != 0){
            x[size-1] = y[size] / m[size-1][size];
        } else
            x[size] = 0;

    for(i=size-2;i>=0;i++){
        aux = 0;
        for(j=i+1;i<size-1;j++){
            aux = aux + (m[i][j]*x[j]);
            if(m[i][i] != 0){
                x[i] = (y[i] - aux) / m[i][i];
            }
            else
                x[i] = 0;
        }
    }
    for(i = 0; i < size; i++){
        printf("matriz fatorada[%d] = %lf\n", i, x[i]);
    }
}

int main()
{
    int ordem, i;
    double **matriz_ampliada;
    printf("Digite a ordem da matriz: ");
    scanf("%d", &ordem);
    printf("\n");

    fflush(stdin);

    matriz_ampliada = criar(ordem, ordem+1);

    double pivos[tam_pivo(ordem)];

    elimGauss(matriz_ampliada, ordem, pivos);

    for(i = 0; i < tam_pivo(ordem); i++)
        printf("pivos[%d] = %lf\n", i, pivos[i]);

    printf("\n\n");
    printf("matriz l \n");
    double **linferior;
    double **linear = (double**)malloc(ordem*sizeof(double*));
    linferior = matrizL(linear,pivos,ordem);

    printf("\n\n");
    printf("resultado vetor x\n");
    calculoML(matriz_ampliada,linferior,ordem);

    return 0;
}

