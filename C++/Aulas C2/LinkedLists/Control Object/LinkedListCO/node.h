#ifndef NODE_H
#define NODE_H

class Node {
private:
    int val;
    Node *next;
public:
    Node(int val);

    void insertOnTail(Node *node, int val);
    void insertSorted(Node *&node, int val);

    void setVal(int val);
    int getVal();
    void setNext(Node *next);
    Node *getNext();
    Node **getNextPtr();

    void removeTail(Node *&ant);

    ~Node();
};

#endif // NODE_H
