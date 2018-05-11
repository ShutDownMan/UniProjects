#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no *prox;
}No;

typedef struct fila{
    No *inicio;
    No *fim;
}Fila;


int vazia(Fila *f){
    return !f;
}

Fila *insere(Fila *f, int info){
    No *faux = (Fila *)malloc(sizeof(Fila));

    faux->info = info;
    faux->prox = NULL;

    if(vazia(f)){
        f->inicio = faux;
	    f->fim = faux;
	    return f;
    }

    f->fim->prox = faux;
    f->fim = faux;

    return f;
}

void imprime(Fila *f){
    Fila *aux = f;

    while(aux){
        printf("[%d]->",aux->inicio->info);
        aux->inicio=aux->inicio->prox;
    }
    printf("[  ]\n");

    system("pause");
}

int main(){
    Fila *dobanco;

    dobanco = insere(dobanco,1);
    dobanco = insere(dobanco,2);
    dobanco = insere(dobanco,3);
    dobanco = insere(dobanco,4);

    imprime(dobanco);

    return 0;
}