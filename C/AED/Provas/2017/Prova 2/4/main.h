#ifndef MAIN_H
#define MAIN_H

struct no {
	int info;
	struct no* prox;
}

typedef struct {
	struct no* inicio;
	struct no* fim;
} Fila;

void enqueue(Fila *f, int x);

int dequeue(Fila *f);

#endif