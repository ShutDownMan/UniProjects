#include <stdlib.h>
#include <stdio.h>

#include "heap.h"

// HEAP FUNCTIONS //

///
/// \brief  createHeap, inicializa pilha
/// \return memória alocada para pilha inicializada
/// \pre    nenhuma
/// \post   nenhuma
///
Stack *createHeap() {
    /// aloca memória para pilha
    Stack *newHeap = (Stack*)malloc(sizeof(Stack));

    /// incializa campos da estrutura
    newHeap->length = 0;
    newHeap->start = NULL;
    newHeap->end = NULL;

    /// retorna pilha inicializada
    return newHeap;
}

///
/// \brief  insertCard, insere na pilha a carta indicada
/// \param  heap, pilha a ser modificada
/// \param  card, carta a ser inserida
/// \return pilha modificada
/// \pre    nenhuma
/// \post   nenhuma
///
Stack *insertCard(Stack *heap, Card *card) {
    Node *aux;

    /// se carta é nula, nada é inserido
    if(!card) return heap;

    /// se pilha é nula
    if(!heap) {
        /// cria uma pilha e a retorna
        Stack *newHeap = createHeap();
        newHeap->length++;
        newHeap->start = createNode(card);
        newHeap->end = newHeap->start;
        return newHeap;
    }

    /// adiciona carta a cabeça
    aux = heap->start;
    heap->start = createNode(card);
    heap->start->next = aux;
    heap->length++;

    /// retorna pilha modificada
    return heap;
}

///
/// \brief  concatHeap, concatena duas pilhas
/// \param  heap1, primeira pilha
/// \param  heap2, segunda pilha
/// \return primeira pilha
/// \pre    nenhuma
/// \post   nenhuma
///
Stack *concatHeap(Stack *heap1, Stack *heap2) {
    /// se primeira pilha é nula
    if(!heap1) {
        /// inicializa a primeira pilha
        heap1 = createHeap();
    }

    /// se a segunda pilha não é nula
    if(heap2) {
        /// se a primeira pilha tem cartas
        if(!heap1->start) {
            /// coloca o começo da primeira pilha como final da segunda
            heap1->start = heap2->start;
            /// coloca final da segunda como final da primeira
            heap1->end = heap2->end;
        } else { //< se primeira pilha está vazia
            /// coloca primeira pilha como a segunda
            heap2->end->next = heap1->start;
            heap2->end = heap1->end;
            heap1->start = heap2->start;
            heap1->end = heap2->end;
        }

        /// adiciona tamanho da segunda pilha na primeira
        heap1->length += heap2->length;

        /// esvazia a segunda pilha
        heap2->start = NULL;
        heap2->end = NULL;
        heap2->length = 0;
    }

    /// retorna primeira pilha modificada
    return heap1;
}

///
/// \brief  reverseHeap, inverte uma cópia
/// \param  node, cabeça atual da lista
/// \return pilha invertida
/// \pre    nenhuma
/// \post   nenhuma
///
Node *reverseList(Node *node) {
    /// se nó é nulo, nada a ser feito
    if(!node) return NULL;

    /// adiciona nó atual a cauda de uma pilha auxiliar e chama proximo nó recursivamente
    return insertNodeOnTail(reverseList(node->next), node->card);
}

///
/// \brief  insertNodeOnTail, insere nó no final da lista fornecida
/// \param  list, lista a ser modificada
/// \param  card, carta a ser adicionada
/// \return lista modificada
/// \pre    nenhuma
/// \post   nó é inserida na cauda
///
Node *insertNodeOnTail(Node *list, Card *card) {
    /// se lista é vazia, retorna nó
    if(!list) return createNode(card);

    /// coloca proximo do nó atual como chamada recursiva do proximo nó
    list->next = insertNodeOnTail(list->next, card);

    /// retorna nó atual
    return list;
}

///
/// \brief  pop, retira a cabeça de uma pilha e a retorna
/// \param  heap, pilha a ser modificada
/// \return nó removido da pilha
/// \pre    nenhuma
/// \post   pilha perde a cabeça
///
Node *pop(Stack *heap) {
    Node *aux;

    /// se pilha é nula ou vazia, nada a ser feito
    if(!heap || !heap->start) return NULL;

    aux = heap->start;
    /// se começo da pilha é igual final (só tem um nó)
    if(heap->start == heap->end) {
        /// esvazia lista
        heap->start = heap->end = NULL;
    } else { //< se não
        /// começo da lista se torna segundo nó
        heap->start = heap->start->next;
    }

    /// diminui tamanho da pilha
    heap->length--;
    aux->next = NULL;

    /// retorna nó retirado
    return aux;
}

///
/// \brief  createNode, inicializa nó
/// \param  card, carta apontada pelo nó
/// \return nó inicializado
/// \pre    nenhuma
/// \post   nenhuma
///
Node *createNode(Card *card) {
    /// aloca memória para nó
    Node *newNode = (Node*)malloc(sizeof(Node));

    /// inicializa campos da esturura
    newNode->card = card;
    newNode->next = NULL;

    /// retorna o nó
    return newNode;
}


///
/// \brief  freeList, libera espaço da memória usado para lista
/// \param  node, cabeça atual da lista
/// \pre    nenhuma
/// \post   memória da lista é liberada
///
void freeList(Node *node) {
    /// se nó é nulo, nada a ser feito
    if(!node) return;

    /// chama proximo nó recursivamente e libera memória do nó atual
    freeList(node->next);
    free(node);
}
