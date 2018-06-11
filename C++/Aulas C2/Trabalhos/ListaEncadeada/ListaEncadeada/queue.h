#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include "node.h"

template <class T>
class Queue: public Node<T> {
private:
    Node<T> *head;
    Node<T> *tail;

public:
    Queue();

    void enqueue(T const&);
    void dequeue(T const&);

    T *pop();
    T *top();

    bool isEmpty();

    void show();

    ~Queue();
};

#include "queue.tcc"

#endif // QUEUE_H
