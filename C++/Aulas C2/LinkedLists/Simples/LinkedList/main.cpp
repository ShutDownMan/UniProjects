#include <iostream>

#include "list.h"

using namespace std;

int main() {
    List *list = NULL;

    List::insertOnTail(list, 1);
    List::insertOnTail(list, 2);
    List::insertOnTail(list, 3);
    List::insertOnTail(list, 4);
    List::insertOnTail(list, 2);

    List::print(list);

    List::freeList(list);

    return 0;
}

