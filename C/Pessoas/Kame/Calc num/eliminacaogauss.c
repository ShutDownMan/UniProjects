#include <stdio.h>
#include <stdlib.h>
#include "eliminacaogauss.h"

/*!
 * \brief imprimeMatriz Imprime a matriz
 * \param m Matriz
 * \param lin Quantidade de linhas
 * \param col Quantidade de colunas
 */
void imprimeMatriz(double **m, int lin, int col){
    int i, j;
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            printf("%lf\t", m[i][j]);
        }
        printf("\n");
    }
}

/*!
 * \brief matriz scaneia os valores
 * \param m
 * \param lin
 * \param col
 */
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

/*!
 * \brief criar aloca memoria para a matriz
 * \param lin
 * \param col
 * \return matriz alocada
 */
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

/*!
 * \brief elimGauss eliminacao de gauss
 * \param m
 * \param ordem quantidade incognitas
 * \param pivo vetor de pivos utilizados
 */
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
    } else {
        printf("Sistema Impossivel\n");
    }
}

/*!
 * \brief solucao resolve a eliminacao de gauss, descobre os xs
 * \param m
 * \param ordem
 */
void solucao(double **m, int ordem){
    int i, j;
    double aux, result[ordem-1];
    result[ordem-1] = m[ordem - 1][ordem]/m[ordem - 1][ordem - 1];

    for(i = ordem - 2; i >= 0; i--){
        aux = 0;
        for(j = i + 1; j < ordem; j++){
            aux += m[i][j]*result[j];
        }
        result[i] = (m[i][ordem] - aux)/m[i][i];
    }

    for(i = 0; i < ordem; i++){
        printf("x%d = %lf\n", i, result[i]);
    }

    printf("\nFIM\n");
}

int main(void){
    int ordem, i;
    double **matriz_ampliada;
    printf("Digite a ordem da matriz: ");
    scanf("%d", &ordem);
    printf("\n");

    fflush(stdin);

    matriz_ampliada = criar(ordem, ordem+1);

    double pivos[ordem];

    elimGauss(matriz_ampliada, ordem, pivos);

    for(i = 0; i < tam_pivo(ordem); i++)
        printf("pivos[%d] = %lf\n", i, pivos[i]);

    printf("\nFIM\n");

    return 0;
}

