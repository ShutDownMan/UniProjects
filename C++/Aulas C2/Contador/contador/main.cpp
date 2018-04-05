#include "contador.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    Contador* c1 = new Contador();

    while(c1->getTime() < 50) {
        c1->increment();
        cout << "Time: " << c1->getTime() << endl;
    }

    delete c1;

    return 0;
}
