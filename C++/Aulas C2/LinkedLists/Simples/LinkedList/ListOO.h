#ifndef LIST_H
#define LIST_H

class List {
private:
    int info;
    List *next;
public:
    List();
    List(int val);

    List **getNextPtr();

    List *getNext();
    void setNext(List* list);

    static List *insertOnHead(List *&list, int val);
    static List *insertOnTail(List *&list, int val);

    void print();

    ~List();
};

#endif LIST_H
