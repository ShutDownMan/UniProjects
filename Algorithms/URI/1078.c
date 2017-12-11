#include <stdio.h>

int main() {
    int i, num;

    scanf("%d", &num);

    for(i = 1; i <= 10; ++i) {
        printf("%d x %d = %d\n", i, num, i*num);
    }

    return 0;
}