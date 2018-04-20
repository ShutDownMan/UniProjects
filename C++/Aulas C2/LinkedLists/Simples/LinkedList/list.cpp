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

List *List::getNext() {
    return this->next;
}

void List::setNext(List *list) {
    this->next = list;
}

List::~List() {

}

static List *insertOnHead(List *&list, int val) {
}

static List *insertOnTail(List *&list, int val) {
    if(list) {
        list->setNext(insertOnTail(list->getNext(), val));
        return list;
    }
    list = new List(val);
    return list;
}
