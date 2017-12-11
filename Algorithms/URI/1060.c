#include <stdio.h>

int main() {

    int sum, i;
    double curr;

    for(i = 0; i < 6;i ++) {
        scanf("%lf", &curr);

        if(curr > 0){
            sum++;
        }
    }

    printf("%d valores positivos\n", sum);

    return 0;
}