//
// Created by Jedson on 10/21/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"

//- INITIALIZE -//

Queue *createQueue() {
    Queue *newQueue = (Queue *) malloc(sizeof(Queue));

    newQueue->count = 0;
    newQueue->first = NULL;
    newQueue->last = NULL;

    return newQueue;
}

QNode *createQNode(void *info) {
    QNode *newQNode = (QNode *) malloc(sizeof(QNode));

    newQNode->info = info;
    newQNode->next = NULL;
    newQNode->prev = NULL;

    return newQNode;
}

//- UPDATE -//

void pushQ(Queue *queue, void *info) {
    if (!queue) return;
    QNode *newQNode = createQNode(info);

    if (!queue->first) {
        queue->first = queue->last = newQNode;
    } else {
        newQNode->prev = queue->last;
        queue->last->next = newQNode;
        queue->last = newQNode;
    }
    queue->count++;
}

QNode *popQ(Queue *queue) {
    QNode *node = NULL;

    if (!queue) return NULL;
    if (!queue->first) return NULL;

    node = queue->first;
    queue->first = node->next;
    if (queue->first) {
        queue->first->prev = NULL;
    } else {
        queue->last = NULL;
    }

    queue->count--;

    return node;
}

//- DELETE -//

void deleteQueue(Queue *queue) {
    QNode *tracer, *next;

    for(tracer = queue->first; tracer; tracer = next) {
        next = tracer->next;
        free(tracer);
    }

    free(queue);
}


//- SHOW -//

void printQ(Queue *queue) {
    QNode *tracer;

    for(tracer = queue->first; tracer; tracer = tracer->next) {
        printf("[0x%p]<->", tracer->info);
    }
    printf("\n");
}
