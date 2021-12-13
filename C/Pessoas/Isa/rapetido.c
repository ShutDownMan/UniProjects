#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INIT_SIZE 256
#define TRUE 1
#define FALSE 0

double repetido(double *valores, unsigned int qtd_numeros, unsigned int *qtd_repeticoes) {
    double moda = HUGE_VAL;
    int i = 0, j = 0;
    char achado = FALSE;

    *qtd_repeticoes = 0;

    /// array nula
    if(!valores) {
        return moda;
    }

    /// uma array de contagem e outra com o número que ela tá contando
    /// além de variáveis de tamanho e alocação
    unsigned int contagem_tam = 0, alocado_tam = INIT_SIZE;
    unsigned int *contagem = (unsigned int *)malloc(sizeof(unsigned int) * alocado_tam);
    double *contagem_val = (double *)malloc(sizeof(double) * alocado_tam);

    /// para cada número em valores
    for(i = 0; i < qtd_numeros; ++i) {
        achado = FALSE;
        /// procura pelo valor atual na array de contagem
        for(j = 0; j < contagem_tam; ++j) {
            /// se achou o valor
            if(contagem_val[j] == valores[i]) {
                /// incrementa ele na array
                contagem[j]++;
                achado = TRUE;
            }
        }

        /// se não achou o valor na array de contagem
        if(achado == FALSE) {
            /// adiciona o valor
            contagem[contagem_tam] = 1;
            contagem_val[contagem_tam] = valores[i];
            contagem_tam++;

            /// se estourou o tamanho alocado
            if(contagem_tam == alocado_tam) {
                /// dobra o tamanho da array
                alocado_tam = 2 * alocado_tam;
                contagem = (unsigned int *)realloc(contagem, alocado_tam);
                contagem_val = (double *)realloc(contagem_val, alocado_tam);
            }
        }
    }

    /// array vazia
    if(!contagem_tam) {
        return moda;
    }

    *qtd_repeticoes = contagem[0];
    /// pega a quantidade de repetições do número com maior frequência
    for(i = 1; i < contagem_tam; ++i) {
        if(contagem[i] > *qtd_repeticoes) {
            moda = contagem_val[i];
            *qtd_repeticoes = contagem[i];
        }
    }

    return moda;
}

int main() {
    double valores[] = {15.1, 2.2, 3.3, 10, 2.2, 10, 7, 7.4, 2.2, 4};
    unsigned int repeticoes = 0;
    double moda = repetido(valores, 10, &repeticoes);

    printf("valor %g repetiu %d vezes\n", moda, repeticoes);

    return 0;
}