#include <stdio.h>
#include <math.h>

int main(){
    float num;
    int interval = 0;
    char intSym;

    scanf("%f", &num);

    if(num <= 100 || num > 0){
        interval = ceil(num/25);
        intSym = (interval-1) ? '(' : '[';

        printf("Intervalo %c%d,%d]\n", intSym, (interval-1) * 25, interval * 25);
    } else {
        printf("Fora de intervalo\n");
    }


    return 0;
}