#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1024
#define MAXSTR 64

typedef int TipoChave;

typedef struct {
	int matricula;
	char nome[MAXSTR];
} TipoRegistro;

typedef struct {
	TipoChave key; // chave
	TipoRegistro reg; // registro armazenado
	int ocupado; // indica se o slot está ocupado
} slot;

typedef slot TabelaHash[TAM];

void inicializaTabelaHash(TabelaHash T);

void inserir(TabelaHash T, TipoChave key, TipoRegistro reg);

//retorna a posição do registro de chave k na tabela hash T
// ou -1 caso a chave não esteja presente.
int buscar(TabelaHash T, TipoChave key);

void remover(TabelaHash T, TipoChave key);

int hash(int k){
	return k%TAM;
}

void readInput(TabelaHash T);

int main(void) {
	TabelaHash T;

	readInput(T);

	return 0;
}

void readInput(TabelaHash T) {
	int n, num;
	char str[MAXSTR];
	TipoRegistro reg;

	scanf("%d", &n);
	while(n--) {
		scanf("%d%*c", &num);
		scanf("%[^\n]%*c", &str);

		reg.matricula = num;
		strcpy(reg.nome, str);

		inserir(T, num, reg);
	}
}

void printReg(TabelaHash T, int ind) {
	printf("-----------------\n");
	if(!T[ind].ocupado) {
		printf("Posicao livre!\n");
		printf("-----------------\n\n");
		return;
	}
	printf("matricula = %d\n", T[ind].reg.matricula);;
	printf("nome = %s\n", T[ind].reg.nome);
	printf("-----------------\n\n");
}

void inserir(TabelaHash T, TipoChave key, TipoRegistro reg) {
	int ind = hash(key);

	if(T[ind].ocupado) {
		printf("+++++++++++++++++\n");
		printf("Posicao ocupada!\n");
		printf("+++++++++++++++++\n\n");
		return;
	}

	T[ind].key = key;
	T[ind].reg = reg;
	T[ind].ocupado = 1;

	printReg(T, ind);
}