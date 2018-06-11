#include "node.h"

template <class T>
Node<T>::Node() {}

template <class T>
Node<T>::Node(T const& info) {
    this->info = info;
    this->next = NULL;
}

template <class T>
T Node<T>::getInfo() {
    return this->info;
}

template <class T>
T *Node<T>::getInfoPtr() {
    return &this->info;
}

template <class T>
Node<T> *Node<T>::getNext() {
    return this->next;
}

template <class T>
Node<T> *Node<T>::insertOnHead(Node<T> *&node, T const &info) {
    if(!node) {
        node = new Node<T>(info);
        return node;
    }

    Node<T> *newHead = new Node<T>(info);
    newHead->next = node;
    node = newHead;

    return newHead;
}

template <class T>
Node<T> *Node<T>::insertOnTail(Node<T> *&node, T const &info) {
    if(!node) {
        node = new Node<T>(info);
        return node;
    }

    if(!node->next) {
        node->next = new Node<T>(info);
    } else {
        insertOnTail(node->next, info);
    }

    return node;
}

template <class T>
void Node<T>::removeHead(Node *&head) {
    Node *aux = head;
    head = head->next;
    delete aux;
}

template <class T>
void Node<T>::removeTail(Node *&node) {
    Node *aux = NULL;

    if(!node) return;

    if(node->next && !node->next->next) {
        aux = node->next;
        node->next = NULL;
    } else if(node && !node->next) {
        aux = node;
        node = NULL;
    }

    if(!aux) {
        removeTail(node->next);
    } else {
        delete aux;
    }
}

template <class T>
Node<T> *Node<T>::revert(Node<T> *node) {
    Node<T> *aux = NULL;

    if(!node) return NULL;

    aux = revert(node->next);

    return insertOnTail(aux, node->info);
}

template <class T>
int Node<T>::getLength() {
    if(!this->next) return 0;

    return 1 + this->next->getLength();
}

template <class T>
Node<T> *Node<T>::getNodePos(int n) {

    if(n <= 0) return NULL;

    if(n == 1) {
        return this;
    } else {
        if(this->next) return this->next->getNodePos(n-1);
    }

    return NULL;
}

template <class T>
Node<T> *Node<T>::operator[](int n) {
    return this->getNodePos(n+1);
}

template <class T>
void Node<T>::show() {
    Node<T> *tracer = NULL;

    printf("Linked List: \n");
    for(tracer = this; tracer; tracer = tracer->next) {
        printf("(%g)-> ", tracer->info);
    }
    printf("(!);\n");
}

template <class T>
Node<T>::~Node() {
    printf("Freeing node (%g).\n", this->info);
}

