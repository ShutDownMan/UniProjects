#include "queue.h"

template <class T>
Queue<T>::Queue() {
    this->head = NULL;
    this->tail = NULL;
}

template <class T>
void Queue<T>::enqueue(const T &info) {
    Node<T>::insertOnTail(this->head, info);

    if(!this->tail) {
        this->tail = this->head;
    } else {
        this->tail = this->tail->next;
    }
}

template <class T>
void Queue<T>::dequeue(const T &) {
    Node<T> *tracer;

    Node<T>::removeTail(this->head);

    for(tracer = this->head; tracer && tracer->next; tracer == tracer->next)
        ;

    this->tail = tracer;
}

template <class T>
T *Queue<T>::pop() {
    T *info = this->top();

    Node<T>::removeHead(this->head);

    return info;
}

template <class T>
T *Queue<T>::top() {
    return this->head->getInfoPtr();
}

template <class T>
bool Queue<T>::isEmpty() {
    return (this->head == NULL);
}

template <class T>
void Queue<T>::show() {
    Node<T> *tracer = NULL;

    printf("Linked List: \n");
    for(tracer = this->head; tracer; tracer = tracer->getNext()) {
        printf("(%g)-> ", tracer->getInfo());
    }
    printf("(!);\n");
}

template <class T>
Queue<T>::~Queue() {
    printf("Freeing queue.\n");
}

