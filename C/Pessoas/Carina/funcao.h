#ifndef FUNCAO_H_INCLUDED
#define FUNCAO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Transicao{
	int EstadoAtual;
	char CaracterLido;
	int EstadoProx;
};

struct Transicao transicao[255];

int estados[10];
int num_transicoes, num_estadosFinal, EstadosFinal[10], EstadoInicial;
char alfabeto[255];

void Carregar_Arquivo(char Arq[]);

int validar_palavra( char palavra[] );

int processar_palavra(char palavra[], int estado);

int eh_final(int estado);

int prox_estado(int estadoAtual, char simbolo);

#endif
