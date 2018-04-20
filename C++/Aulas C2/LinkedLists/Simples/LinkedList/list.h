#ifndef LIST_H
#define LIST_H


class List {
private:
    int info;
    List *next;
public:
    List();
    List(int val);

    List *getNext();

    void setNext(List* list);

    static List *insertOnHead(List *&list, int val);
    static List *insertOnTail(List *&list, int val);

    List *printList();

    ~List();
};

#endif // LIST_H
