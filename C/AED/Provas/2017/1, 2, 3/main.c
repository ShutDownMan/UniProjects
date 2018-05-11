#include <stdio.h>
#include <stdlib.h>

#include "main.h"

Lista *criaNo(int info) {
	Lista *novoNo = NULL;

	novoNo = malloc(sizeof(Lista));
	novoNo->info = info;
	novoNo->prox = NULL;

	return novoNo;
}

Lista *insereCauda(Lista *l, int info) {
	Lista *novoNo = NULL;

	if(!l) return criaNo(info);

	l->prox = insereCauda(l->prox, info);

	return l;
}

Lista *impares(Lista *l) {
	Lista **tracer = NULL, *newLista = NULL;

	if(!l) return NULL;

	for(tracer = &l; *tracer; tracer = &(*tracer)->prox) {
		if((*tracer)->info%2) {
			newLista = insereCauda(newLista, (*tracer)->info);
		}
	}

	return newLista;
}

Lista *remove_intervalo(Lista *l, int a, int b) {
	Lista *tracer = NULL, *aux = NULL;

	if(!l) return NULL;

	for(tracer = l; tracer->prox;) {
		if(tracer->prox->info >= a && tracer->prox->info <= b) {
			aux = tracer->prox->prox;
			free(tracer->prox);
			tracer->prox = aux;
		} else {
			tracer = tracer->prox;
		}
	}

	if(l->info >= a && l->info <= b) {
		aux = l->prox;
		free(l);
		return aux;
	}

	return l;
}

int maximo(Lista *l) {
	int max = 0;
	if(!l) return -1;

	max = maximo(l->prox);
	return (l->info > max) ? l->info : max;
}

void printLista(Lista *l) {
	Lista **tracer = NULL;

	if(!l) {
		printf("Lista nula\n");
		return;
	}

	for(tracer = &l; *tracer; tracer = &(*tracer)->prox) {
		printf("(%d)->", (*tracer)->info);
	}
	printf("(!);\n");
}

int main(int argc, char const *argv[]) {
	Lista *lista1 = NULL;

	lista1 = insereCauda(lista1, 0);
	lista1 = insereCauda(lista1, 4);
	lista1 = insereCauda(lista1, 6);
	lista1 = insereCauda(lista1, 10);
	lista1 = insereCauda(lista1, 25);
	lista1 = insereCauda(lista1, -1);
	lista1 = insereCauda(lista1, 5);

	printLista(lista1);

	printLista(remove_intervalo(lista1, 0, 5));

	return 0;
}
