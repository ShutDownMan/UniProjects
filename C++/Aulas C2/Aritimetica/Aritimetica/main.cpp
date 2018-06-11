#include <iostream>
#include "base.h"

using namespace std;

int main() {
    Base *b;
    char str[256];

    scanf("%[^\n]%*c", str);

    b = Base::montaExpressaoPrefix(str);

    return 0;
}

