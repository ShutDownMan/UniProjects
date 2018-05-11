#ifndef MAIN_H
#define MAIN_H

typedef struct no {
	int info;
	struct no* prox;
} Lista;

Lista *impares(Lista *l);

Lista *remove_intervalo(Lista *l, int a, int b);

int maximo(Lista *l);

#endif