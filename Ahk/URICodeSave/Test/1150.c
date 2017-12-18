#include <stdio.h>

int main(void) {
    int x, z;
    int i, sum;

    scanf("%d %d", &x, &z);

    while(x >= z) {
        scanf("%d", &z);
    }

    sum = x;
    for(i = 0; sum < z; i++) {
        sum += x+i;
    }

    if(x > 0) i++;
    printf("%d\n", i);

}
