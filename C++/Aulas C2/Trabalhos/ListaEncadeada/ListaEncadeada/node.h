#ifndef NODE_H
#define NODE_H

#include <stdio.h>

template <class T> class Node {
private:
    T info;
    Node *next;

public:
    Node();
    Node(T const&);

    T getInfo();
    Node *getNext();

    T *getInfoPtr();

    static Node *insertOnHead(Node *&, T const&);
    static Node *insertOnTail(Node *&, T const&);

    static void removeHead(Node *&);
    static void removeTail(Node *&);

    int getLength();
    Node *getNodePos(int);

    Node *operator[](int);

    void show();

    ~Node();
};

#include "node.tcc"

#endif // NODE_H
