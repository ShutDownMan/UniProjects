#include "heap.h"

template <class T>
Heap<T>::Heap() {
    this->head = NULL;
}

template <class T>
void Heap<T>::push(const T &info) {
    Node<T>::insertOnHead(head, info);
}

template <class T>
T *Heap<T>::pop() {
    T *info = this->top();

    Node<T>::removeHead(this->head);

    return info;
}

template <class T>
T *Heap<T>::top() {
    return this->head->getInfoPtr();
}

template <class T>
bool Heap<T>::isEmpty() {
    return (this->head == NULL);
}

template <class T>
Heap<T>::~Heap() {
    printf("Freeing heap.\n");
}

template <class T>
void Heap<T>::show() {
    Node<T> *tracer = NULL;

    printf("Linked List: \n");
    for(tracer = this->head; tracer; tracer = tracer->getNext()) {
        printf("(%g)-> ", tracer->getInfo());
    }
    printf("(!);\n");
}
