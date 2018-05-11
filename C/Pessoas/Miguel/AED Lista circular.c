#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int info;
	struct no* prox;
} No;

typedef struct Lista {
	struct no* cabeca = NULL;
	struct no* cauda = NULL;
} Lista;

Lista *criaNo(int info) {
	No *novoNo = (No*)malloc(sizeof(No));

	novoNo->info = info;
	novoNo->prox = NULL;

	return novoNo;
}

Lista *insereCauda(Lista *l, int info) {
	Lista *novoNo = criaNo(info);

	if(!l->cabeca) {
		l->cabeca = novoNo;
		l->cauda = novoNo;
		return l;
	}

	l->cauda->prox = novoNo;
	l->cauda = novoNo;

	return l;
}

Lista *remover(Lista *l, int info) {
	Lista *aux = NULL;


}

int main(void) {
	Lista *lista1 = malloc(sizeof(Lista));

	lista1 = insereCauda(lista1, 0);

	return 0;
}