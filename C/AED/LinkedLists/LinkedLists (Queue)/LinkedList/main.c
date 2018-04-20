#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

// EXERCISES FUNCTIONS //

int main(void) {
    Queue *q1 = readQueue();

    dequeue(q1, 2);
    printQueue(q1);

    return 0;
}

int isEmpty(Queue *q) {
    return !(q->first);
}

Queue *enqueue(Queue *q, int val) {
    Node *newNode = createNode(val);
    if(isEmpty(q)) {
        q->first = newNode;
        q->last = q->first;
        return q;
    }

    newNode->next = q->first;
    q->first = newNode;
    return q;
}

void dequeue(Queue *q, int val) {
    // Meybe someday
}

void printQueue(Queue *q) {
    Node **tracer;

    if(isEmpty(q)) {
        printf("Empty list!\n");
        return;
    }

    printf("[(%d)->...(%d)]: ", q->first->info, q->last->info);
    for(tracer = &q->first; *tracer; tracer = &(*tracer)->next) {
        printf("(%d)->", (*tracer)->info);
    }

    printf("(!).\n");
}

// HELPER FUNCTIONS //

Queue *readQueue() {
    Queue *newQ = (Queue*)malloc(sizeof(Queue));
    int qnt, num;

    newQ->first = NULL;
    newQ->last = NULL;

    printf("Type in the length of the queue: ");
    scanf("%d%*c", &qnt);
    newQ->length = qnt;

    while(qnt--) {
        printf("Type in a number to queue: ");
        scanf("%d%*c", &num);
        enqueue(newQ, num);
    }

    return newQ;
}

Node *createNode(int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->info = val;
    newNode->next = NULL;
    return newNode;
}
