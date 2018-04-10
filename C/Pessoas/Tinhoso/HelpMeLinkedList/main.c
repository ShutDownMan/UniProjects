#include <stdio.h>
#include <stdlib.h>
#include "exercicio1.h"

int main(){
    Lista *l = NULL;

    l = insere(l,5);
    l = insere(l,9);
    l = insere(l,3);
    l = insere(l,6);

    imprime(l);

    imprime(inverte(l));

    return 0;
}

// FUNCOES DO EXERCICIOS //

int vazia (Lista *l){
    return !l;
}

Lista *insere(Lista *l, int info){
    Lista *aux = (Lista *)malloc(sizeof(Lista));
    aux->info = info;
    aux->prox = l;
    return aux;
}

void imprime (Lista *l){
    if(vazia(l)) {
        printf("\n");
        return;
    }

    printf("%d ", l->info);

    imprime(l->prox);
}

Lista *remover(Lista *l, int info){
    Lista *ant = l;
    Lista *p = l;

    while(p && p->info != info){
        ant = p;
        p = p->prox;
    }

    if(p){
        if(p==l){
            l = l->prox;
        }else{
            ant->prox = p->prox;
        }
        free(p);
    }else
        printf("ELEMENTO NAO ENCONTRADO");

    return l;
}

Lista* inverte(Lista *list) {
    Lista *acc;

    if(vazia(list)) return NULL;

    if(vazia(list->prox)) return copiano(list);

    acc = inverte(list->prox);
    eresni(acc, list->info);

    return acc;
}


// FUNCOES AUXILIARES //

Lista* eresni(Lista *list, int val) {
    if(vazia(list)) return NULL;

    if(list->prox) {
        eresni(list->prox, val);
        return list;
    }

    list->prox = criano(val);

    return list;
}

Lista *criano(int val) {
    Lista *newNo = malloc(sizeof(Lista));

    newNo->info = val;
    newNo->prox = NULL;

    return newNo;
}

Lista *copiano(Lista *no) {
    Lista *newNo = criano(no->info);

    newNo->prox = NULL;

    return newNo;
}
