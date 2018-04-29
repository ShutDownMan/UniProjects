#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List::List() {
    this->setHead(NULL);
}

Node *List::getHead() {
    return this->head;
}

void List::setHead(Node *node) {
    this->head = node;
}

List *List::insertSorted(int val) {
    if(!this->getHead()) {
        this->setHead(new Node(val));
        return this;
    }
    this->head->insertSorted(this->head, val);
    return this;
}

void List::removeHead() {

}

void List::show() {
    Node **tracer;

    if(!this->getHead()) {
        printf("List is empty\n");
        return;
    }

    for(tracer = &this->head; *tracer; tracer = (*tracer)->getNextPtr()) {
        printf("(%d)->", (*tracer)->getVal());
    }
    printf("(!);\n");
}

List::~List() {

}
