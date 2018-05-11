#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int info;
	struct no* prox;
} Lista;

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

Lista *removerep(Lista *listaRepetidos, Lista *listaOriginal) {
	Lista **tracer;
	int present = 0;

	if(!listaOriginal) return NULL;

	if(listaRepetidos) {
		for(tracer = &listaRepetidos; *tracer && !present; tracer = &(*tracer)->prox) {
			present = (listaOriginal->info == (*tracer)->info);
		}
	}

	if(!present) {
		listaRepetidos = insereCauda(listaRepetidos, listaOriginal->info);
	}

	removerep(listaRepetidos, listaOriginal->prox);

	return listaRepetidos;
}

Lista *removerep2(Lista *listaOriginal) {
	Lista **tracer, *aux;
	int present = 0;

	if(!listaOriginal) return NULL;

	for(tracer = &listaOriginal->prox; *tracer && !present; tracer = &(*tracer)->prox) {
		present = (listaOriginal->info == (*tracer)->info);
	}

	if(!present) {
		aux = criaNo(listaOriginal->info);
		aux->prox = removerep2(listaOriginal->prox);
		return aux;
	}

	return removerep2(listaOriginal->prox);
}

int conta_ocorrencias(Lista *l, int info) {
	if(!l) return 0;

	if(l->info == info) {
		return 1 + conta_ocorrencias(l->prox, info);
	}

	return conta_ocorrencias(l->prox, info);
}

Lista *menores(Lista *l, int info) {
	Lista *tracer = NULL, *novaLista = NULL;

	if(!l) return NULL;

	for(tracer = l; tracer; tracer = tracer->prox) {
		if(tracer->info < info) {
			novaLista = insereCauda(novaLista, tracer->info);
		}
	}

	return novaLista;
}

Lista *inserir_apos(Lista *l, int info_ref, int info) {
	Lista *novoNo = NULL;

	if(!l) return criaNo(info);

	if(l->info == info_ref) {
		novoNo = criaNo(info);
		novoNo->prox = l->prox;
		l->prox = novoNo;
		return l;
	}

	l->prox = inserir_apos(l->prox, info_ref, info);

	return l;
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
	Lista *l1 = NULL, *l2 = NULL;

	l1 = inserir_apos(l1, 5, 10);
	l1 = insereCauda(l1, 1);
	l1 = insereCauda(l1, 0);
	l1 = insereCauda(l1, 5);
	l1 = insereCauda(l1, 5);
	l1 = insereCauda(l1, 4);
	l1 = insereCauda(l1, 2);
	l1 = insereCauda(l1, 5);
	l1 = insereCauda(l1, 7);
	l1 = insereCauda(l1, 0);
	l1 = insereCauda(l1, 5);


	printLista(l1);

	printf("-------------------\n");
	printLista(menores(l1, 5));

	return 0;
}
