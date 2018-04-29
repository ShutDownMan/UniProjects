#ifndef LIST_H
#define LIST_H

#include "node.h"

class List {
private:
    Node *head;
public:
    List();

    Node *getHead();
    void setHead(Node *node);

    List *insertSorted(int val);

    void removeHead();

    void show();

    ~List();
};

#endif // LIST_H
