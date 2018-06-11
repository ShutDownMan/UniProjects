#include <iostream>
#include "node.h"
#include "heap.h"
#include "queue.h"

typedef double T;

using namespace std;

int main() {
    Node<T> *simpleLL = NULL;
    Heap<T> *heap = new Heap<double>();
    Queue<T> *queue = new Queue<double>();

    Node<T>::insertOnTail(simpleLL, 0.2);
    Node<T>::insertOnTail(simpleLL, 1.8);
    Node<T>::insertOnTail(simpleLL, 2.1);
    Node<T>::insertOnHead(simpleLL, 3.7);

    Node<T>::removeHead(simpleLL);

    simpleLL->show();
    delete simpleLL;
    printf("--------------------\n");

    heap->push(0.2);
    heap->push(1.8);
    heap->push(2.1);
    heap->push(3.7);

    heap->revert()->show();
    printf("--------------------\n");

    heap->show();
    delete heap;
    printf("--------------------\n");

    queue->enqueue(0.2);
    queue->enqueue(1.8);
    queue->enqueue(2.1);
    queue->enqueue(3.7);

    queue->revert()->show();
    printf("--------------------\n");

    queue->show();
    delete queue;
    printf("--------------------\n");

    return 0;
}
