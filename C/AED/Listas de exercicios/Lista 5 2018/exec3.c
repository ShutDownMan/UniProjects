#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 702
#define MAXSTR 64

typedef int TipoChave;

typedef struct {
	int matricula;
	char nome[MAXSTR];
} TipoRegistro;

typedef struct slot {
	TipoChave key; // chave
	TipoRegistro *reg; // registro armazenado
	int ocupado; // indica se o slot está ocupado
	struct slot *next; // proximo registro na lista
} slot;

typedef slot TabelaHash[TAM];

void inicializaTabelaHash(TabelaHash T);

void inserir(TabelaHash T, TipoChave key, TipoRegistro reg);

TipoRegistro *buscar(TabelaHash T, TipoChave key);

void remover(TabelaHash T, TipoChave key);

int hash(int k) {
	return k%TAM;
}

void readInput(TabelaHash T);

void printReg(TipoRegistro *reg);

int main(void) {
	TabelaHash T;
	int i;

	for(i = 0; i < TAM; ++i) {
		T[i].ocupado = 0;
		T[i].next = NULL;
	}

	readInput(T);

	printReg(buscar(T, 757));

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

void printReg(TipoRegistro *reg) {

	printf("-----------------\n");
	if(!reg) {
		printf("Registro nulo\n");
		printf("-----------------\n\n");
		return;
	}

	printf("matricula = %d\n", reg->matricula);;
	printf("nome = %s\n", reg->nome);
	printf("-----------------\n\n");
}

TipoRegistro *createReg(TipoRegistro reg) {
	TipoRegistro *newReg = malloc(sizeof(TipoRegistro));

	*newReg = reg;

	return newReg;
}

slot *createSlot(TipoChave key, TipoRegistro *reg) {
	slot *newSlot = malloc(sizeof(slot));

	newSlot->key = key;
	newSlot->reg = reg;
	newSlot->ocupado = 1;
	newSlot->next = NULL;

	return newSlot;
}

void inserir(TabelaHash T, TipoChave key, TipoRegistro reg) {
	int ind;
	slot **tracer = NULL;

	ind = hash(key);
	if(!T[ind].ocupado) {
		T[ind].key = key;
		T[ind].reg = createReg(reg);
		T[ind].ocupado = 1;
		printReg(T[ind].reg);
		return;
	} else {
		if(T[ind].next) {
			for(tracer = &(T[ind].next); (*tracer)->next; tracer = &(*tracer)->next)
				;
			(*tracer)->next = createSlot(key, createReg(reg));
			printReg((*tracer)->next->reg);
		} else {
			T[ind].next = createSlot(key, createReg(reg));
			printReg(T[ind].next->reg);
		}
	}
}

TipoRegistro *buscar(TabelaHash T, TipoChave key) {
	slot *tracer;
	int ind;

	ind = hash(key);
	if(T[ind].key == key) {
		return T[ind].reg;
	}

	for(tracer = T[ind].next; tracer && (tracer->key != key); tracer = tracer->next)
		;

	if(tracer) return tracer->reg;

	return NULL;
}