#include "ListOO.h"

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

void List::print() {

    printf("(%d)->", this->info);
    if(this->next) {
        this->next->print();
    } else {
        printf("(!);\n");
    }
}

List::~List() {
    printf("Liberando mem%cria (%d).\n", 162, this->info);

    if(this->next) {
        delete this->next;
    }
}
