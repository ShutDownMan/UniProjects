//
// Created by Jedson on 10/21/2018.
//

#ifndef BTREE_QUEUE_H
#define BTREE_QUEUE_H

typedef struct QNode {
    void *info;
    struct QNode *next, *prev;
} QNode;

typedef struct Queue {
    QNode *first, *last;
    int count;
} Queue;

//- INITIALIZE -//

Queue *createQueue();

QNode *createQNode(void *info);

//- UPDATE -//

void pushQ(Queue *queue, void *info);

QNode *popQ(Queue *queue);

//- DELETE -//

void deleteQueue(Queue *queue);

//- SHOW -//

void printQ(Queue *queue);

#endif //BTREE_QUEUE_H
