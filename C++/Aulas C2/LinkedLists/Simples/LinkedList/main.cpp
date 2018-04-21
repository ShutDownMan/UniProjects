#include <iostream>

#include "list.h"

using namespace std;

int main() {
    List *list = NULL;

    List::insertOnHead(list, 1);
    List::insertOnHead(list, 2);
    List::insertOnHead(list, 3);
    List::insertOnHead(list, 4);
    List::insertOnHead(list, 2);

    List::print(list);

    List::freeList(list);

    return 0;
}

