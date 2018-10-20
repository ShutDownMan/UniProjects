#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int main(int argc, char const *argv[]) {
	return 0;
}

void enqueue(Fila *f, int x) {
	struct no *novoNo = NULL;

	if(!f->incio) {
		novoNo = malloc(sizeof(struct no));
		novoNo->info = x;
		novoNo->prox = NULL;

		f->incio = novoNo;
		f->fim = novoNo;
	} else {
		novoNo = malloc(sizeof(struct no));
		novoNo->info = x;
		f->fim->prox = novoNo;
		f->fim = novoNo;
	}

}

int dequeue(Fila *f) {
	struct no *aux = NULL;
	int res;

	if(!f->incio) return 0;

	if(f->incio == f->fim)
		f->fim = NULL;

	res = f->incio->info;

	aux = f->incio->prox;
	free(f->incio);
	f->incio = aux;

	return res;
}