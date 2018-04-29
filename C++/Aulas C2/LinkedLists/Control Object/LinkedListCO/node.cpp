#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node::Node(int val) {
    Node *newNode;
    this->val = val;
    this->next = NULL;
}

void Node::insertOnTail(Node *node, int val) {

}

void Node::insertSorted(Node *&node, int val) {
    Node *aux;

    if(node->val > val) {
        aux = node->next->next;
        node->next = new Node(val);
        node->next->next = aux;
        return;
    }

    if(node->next) {
        node->insertSorted(node->next, val);
    }

}

void Node::setVal(int val) {
    this->val = val;
}

int Node::getVal() {
    return this->val;
}

void Node::setNext(Node *next) {
    this->next = next;
}

Node *Node::getNext() {
    return this->next;
}

Node **Node::getNextPtr() {
    return &this->next;
}

void Node::removeTail(Node *&ant) {

}

Node::~Node() {

}
