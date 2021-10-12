#include <stdio.h>

void functionA(int a) {
    a = 10*a;
}

int main(int argc, char const *argv[])
{
    int value = 10;

    functionA(value);

    printf("value = %d\n", value);

    return 0;
}
