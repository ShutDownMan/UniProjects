#include "lab.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	double *vetor;
	unsigned int qtd_numeros = 0, qtd_repetidos = 0;
	char *arq = "a.txt";
	vetor = le_valores(arq, &qtd_numeros);

	//FILE *f = abre_arquivo("a.txt");
	fecha_arquivo(NULL);

	for(int i = 0; i < (int)qtd_numeros ; i++)
		printf("V[%d] = %.2lf\n", i, vetor[i]);

/* MAIOR */
	printf("\nMaior valor = %lf\n", maior(vetor, qtd_numeros));
	printf("qtd_numeros = %d\n", qtd_numeros);

/* MENOR */
	printf("\nMenor valor = %lf\n", menor(vetor, qtd_numeros));
	printf("qtd_numeros = %d\n", qtd_numeros);

/* MEDIA */
	printf("\nMedia = %.2lf\n", media(vetor, qtd_numeros));
	printf("qtd_numeros = %d\n", qtd_numeros);

/* DESVIO */
	printf("\nDesvio padrao = %lf\n", desvio(vetor, qtd_numeros));
	printf("qtd_numeros = %d\n", qtd_numeros);

/* AMPLITUDE */
	printf("\nAmplitude = %.2lf\n", amplitude(vetor, qtd_numeros));
	printf("qtd_numeros = %d\n", qtd_numeros);

/* VALOR */
	printf("\nValor na posicao = %.2lf\n", valor(vetor, qtd_numeros, 2));
	printf("qtd_numeros = %d\n", qtd_numeros);

/* REPETIDOS */
	double moda = repetido(vetor, qtd_numeros, &qtd_repetidos);
    printf("\nnumero %g repetiu %d vezes.\n", moda, qtd_repetidos);
	printf("qtd_numeros = %d\n", qtd_numeros);

	free(vetor);
	return 0;
}