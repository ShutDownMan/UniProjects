#include <stdio.h>

int main() {
    int i = 1, j = 0;

    while(i <= 9){
        for(j = 7; j>4; --j){
            printf("I=%d J=%d\n", i, j);
        }
        i += 2;
    }

    return 0;
}