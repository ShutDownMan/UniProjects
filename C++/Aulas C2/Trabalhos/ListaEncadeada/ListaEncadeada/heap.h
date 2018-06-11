#ifndef HEAP_H
#define HEAP_H

#include "node.h"
#include <stdio.h>

template <class T>
class Heap: public Node<T> {
private:
    Node<T> *head;
public:
    Heap();

    void push(T const&);
    T *pop();

    T *top();

    Heap *revert();

    bool isEmpty();

    void show();

    ~Heap();
};

#include "heap.tcc"

#endif // HEAP_H
