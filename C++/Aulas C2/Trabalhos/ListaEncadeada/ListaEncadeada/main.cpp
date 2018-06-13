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

    T aux;

    Node<T>::insertOnTail(simpleLL, 0.2);
    Node<T>::insertOnTail(simpleLL, 1.8);
    Node<T>::insertOnTail(simpleLL, 2.1);
    Node<T>::insertOnHead(simpleLL, 3.7);

    simpleLL->show();
    printf("--------------------\n");
    printf("List has length = %d\n", simpleLL->getLength());

    printf("--------------------\n");

    printf("Value of node on position (2) = ");
    cout << simpleLL->getNodePos(2)->getInfo() << endl;
    printf("--------------------\n");

    Node<T>::removeHead(simpleLL);
    simpleLL->show();
    printf("--------------------\n");

    Node<T>::removeTail(simpleLL);
    simpleLL->show();

    printf("--------------------\n");
    delete simpleLL;
    printf("\n++++++++++++++++++++\n\n");

    heap->push(0.2);
    heap->push(1.8);
    heap->push(2.1);
    heap->push(3.7);

    heap->show();
    printf("--------------------\n");

    heap->revert()->show();
    printf("--------------------\n");

    aux = heap->pop();
    printf("Value of node on head (pop) = ");
    cout << aux << endl;
    printf("--------------------\n");

    aux = heap->top();
    printf("Value of node on head (top) = ");
    cout << aux << endl;
    printf("--------------------\n");

    delete heap;
    printf("\n++++++++++++++++++++\n\n");

    queue->enqueue(0.2);
    queue->enqueue(1.8);
    queue->enqueue(2.1);
    queue->enqueue(3.7);

    queue->show();
    printf("--------------------\n");

    queue->revert()->show();
    printf("--------------------\n");

    delete queue;
    printf("\n++++++++++++++++++++\n\n");

    return 0;
}
