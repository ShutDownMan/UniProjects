#include <stdio.h>

int main() {
    int i = 1, j = 0;

    while(i <= 9){
        for(j = 6; j>3; --j){
            printf("I=%d J=%d\n", i, i+j);            
        }
        i += 2;
    }

    return 0;
}