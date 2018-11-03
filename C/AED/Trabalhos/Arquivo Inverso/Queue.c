//
// Created by Jedson on 10/21/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"

//- INITIALIZE -//

/**
 * cria uma nova fila
 * @return fila alocada e inicializada
 * @precondition nenhuma
 * @postcondition fila é criada e retornada
 */
Queue *createQueue() {
    Queue *newQueue = (Queue *) malloc(sizeof(Queue));

    newQueue->count = 0;
    newQueue->first = NULL;
    newQueue->last = NULL;

    return newQueue;
}

/**
 * cria um nó de fila
 * @param info valor a ser armazenado pelo novo nó
 * @return nó alocado e inicializado
 * @precondition nenhuma
 * @postcondition nó é criado e retornado
 */
QNode *createQNode(void *info) {
    QNode *newQNode = (QNode *) malloc(sizeof(QNode));

    newQNode->info = info;
    newQNode->next = NULL;

    return newQNode;
}

//- UPDATE -//

/**
 * insere valor no final da fila
 * @param queue fila a ser inserido o valor
 * @param info valor a ser inserido na fila
 * @precondition nenhuma
 * @postcondition nenhuma
 */
void pushQ(Queue *queue, void *info) {
    if (!queue) return;
    QNode *newQNode = createQNode(info);

    if (!queue->first) {
        queue->first = queue->last = newQNode;
    } else {
        queue->last->next = newQNode;
        queue->last = newQNode;
    }
    queue->count++;
}

/**
 * retorna valor o começo da fila
 * @param queue é a fila ser modificada
 * @return nó no começo da fila
 * @precondition nenhuma
 * @postcondition nó no começo da fila é modificado
 */
QNode *popQ(Queue *queue) {
    QNode *node = NULL;

    if (!queue) return NULL;
    if (!queue->first) return NULL;

    node = queue->first;
    queue->first = node->next;
    if (!queue->first) {
        queue->last = NULL;
    }

    queue->count--;

    return node;
}

//- DELETE -//

/**
 * remove a fila
 * @param queue fila a ser liberada
 * @precondition nenhuma
 * @postcondition nenhuma
 */
void deleteQueue(Queue *queue) {
    QNode *tracer, *next;

    for(tracer = queue->first; tracer; tracer = next) {
        next = tracer->next;
        free(tracer);
    }

    free(queue);
}

//- SHOW -//

/**
 * printa na saida padrão a fila indicada
 * @param queue fila indicada
 * @precondition nenhuma
 * @postcondition nenhuma
 */
void printQ(Queue *queue) {
    QNode *tracer;

    for(tracer = queue->first; tracer; tracer = tracer->next) {
        printf("[0x%p]<->", tracer->info);
    }
    printf("\n");
}
