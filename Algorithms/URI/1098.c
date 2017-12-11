#include <stdio.h>

int main() {
    float i = 0, j = 0;

    while(i <= 2.2){
        for(j = 1; j<=3;j++){
            printf("I=%g J=%g\n", i, j+i);            
        }
        i += 0.2;
    }

    return 0;
}