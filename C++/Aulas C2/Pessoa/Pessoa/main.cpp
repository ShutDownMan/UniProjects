#include <iostream>

#include "pessoa.h"
#include "date.h"

using namespace std;


int main() {
    Person *person = new Person(new string("Alisson"), new Date(12, 9, 1995), 1.66);

    cout << *person->getName() << " is " << person->getAge() << " year(s) old." << endl;

    person->show();

    return 0;
}
