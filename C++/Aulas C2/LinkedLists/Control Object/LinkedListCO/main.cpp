#include <list.h>
#include <iostream>

using namespace std;

int main() {
    List *list = new List();

    list->insertSorted(91);
    list->insertSorted(22);
    list->insertSorted(34);
    list->insertSorted(38);
    list->insertSorted(73);
    list->insertSorted(24);

    list->show();

    return 0;
}

