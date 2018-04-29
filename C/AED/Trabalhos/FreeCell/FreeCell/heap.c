#include <stdlib.h>
#include <stdio.h>

#include "heap.h"

// HEAP FUNCTIONS //

Heap *createHeap() {
    Heap *newHeap = (Heap*)malloc(sizeof(Heap));

    newHeap->length = 0;
    newHeap->start = NULL;
    newHeap->end = NULL;

    return newHeap;
}

Heap *insertCard(Heap *heap, Card *card) {
    Node *aux;

    if(!card) return heap;

    if(!heap) {
        Heap *newHeap = createHeap();
        newHeap->length++;
        newHeap->start = createNode(card);
        newHeap->end = newHeap->start;
        return newHeap;
    }

    aux = heap->start;
    heap->start = createNode(card);
    heap->start->next = aux;
    heap->length++;

    return heap;
}

Heap *concatHeap(Heap *heap1, Heap *heap2) {
    if(!heap1) {
        heap1 = createHeap();
    }

    if(heap2) {
        if(!heap1->start) {
            heap1->start = heap2->start;
            heap1->end = heap2->end;
        } else {
            heap2->end->next = heap1->start;
            heap2->end = heap1->end;
            heap1->start = heap2->start;
            heap1->end = heap2->end;
        }

        heap1->length += heap2->length;

        heap2->start = NULL;
        heap2->end = NULL;
        heap2->length = 0;
    }

    return heap1;
}

Node *reverseHeap(Node *node) {
    if(!node) return NULL;

    return insertNodeOnTail(reverseHeap(node->next), node->card);
}

Node *insertNodeOnTail(Node *list, Card *card) {
    if(!list) return createNode(card);
    list->next = insertNodeOnTail(list->next, card);
    return list;
}

Node *pop(Heap *heap) {
    Node *aux;

    if(!heap || !heap->start) return NULL;

    aux = heap->start;
    if(heap->start == heap->end) {
        heap->start = heap->end = NULL;
    } else {
        heap->start = heap->start->next;
    }
    heap->length--;
    aux->next = NULL;

    return aux;
}

Node *createNode(Card *card) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->card = card;
    newNode->next = NULL;

    return newNode;
}

void freeList(Node *node) {
    if(!node) return;

    freeList(node->next);
    free(node);
}
