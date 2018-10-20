#include <stdio.h>

struct no {
	int info;
	struct no * esq;
	struct no * dir;
	int fb;
};
typedef struct no* ArvoreAVL;

void rotacaoDireitaEsquerda(ArvoreAVL p) {

	if(!p || !p->dir || !p->dir->esq) return;

	struct no *u = p->dir;
	struct no *v = p->dir->esq;

	struct no *aux1 = v->dir;
	struct no *aux2 = v->esq;

	v->dir = u;
	u->esq = aux1;
	v->esq = p;
	p->dir = aux2;
}

void rotacaoEsquerdaDireita(ArvoreAVL p) {

	if(!p || !p->esq || !p->esq->dir) return;

	struct no *u = p->esq;
	struct no *v = p->esq->dir;

	struct no *aux1 = v->esq;
	struct no *aux2 = v->dir;

	v->esq = u;
	u->dir = aux1;
	v->dir = p;
	p->esq = aux2;
}


int main(int argc, char const *argv[]) {
	ArvoreAVL p;

	p = rotacaoDireita(p);

	return 0;
}