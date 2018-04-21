#include "list.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

List::List() {
    this->info = 0;
    this->next = NULL;
}

List::List(int val) {
    this->info = val;
    this->next = NULL;
}

List **List::getNextPtr() {
    return &this->next;
}

List *List::getNext() {
    return this->next;
}

void List::setNext(List *list) {
    this->next = list;
}

List *List::insertOnHead(List *&list, int val) {
    List *aux;
    if(!list) {
        list = new List(val);
        return list;
    }
    aux = list;
    list = new List(val);
    list->setNext(aux);

    return list;
}

List *List::insertOnTail(List *&list, int val) {
    if(!list) {
        list = new List(val);
        return list;
    }
    list->setNext(insertOnTail(*list->getNextPtr(), val));
    return list;
}

void List::print(List *list) {
    List **tracer;

    if(list) {
        for(tracer = &list; *tracer; tracer = (*tracer)->getNextPtr()) {
            printf("(%d)->", (*tracer)->info);
        }
        printf("(!);\n");
    }
}

void List::freeList(List *list) {
    if(!list) return;

    freeList(list->getNext());
    delete list;
}

List::~List() {
    printf("Liberando mem%cria (%d).\n", 162, this->info);
}
